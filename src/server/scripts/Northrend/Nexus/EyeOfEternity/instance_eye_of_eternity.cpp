////////////////////////////////////////////////////////////////////////////////
//
// Project-Hellscream https://hellscream.org
// Copyright (C) 2018-2020 Project-Hellscream-6.2
// Discord https://discord.gg/CWCF3C9
//
////////////////////////////////////////////////////////////////////////////////

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "eye_of_eternity.h"
#include "Player.h"

class instance_eye_of_eternity : public InstanceMapScript
{
public:
    instance_eye_of_eternity() : InstanceMapScript("instance_eye_of_eternity", 616) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_eye_of_eternity_InstanceMapScript(map);
    }

    struct instance_eye_of_eternity_InstanceMapScript : public InstanceScript
    {
        instance_eye_of_eternity_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);

            vortexTriggers.clear();
            portalTriggers.clear();

            malygosGUID = 0;
            irisGUID = 0;
            lastPortalGUID = 0;
            platformGUID = 0;
            exitPortalGUID = 0;
            alexstraszaBunnyGUID = 0;
        };

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (type == DATA_MALYGOS_EVENT)
            {
                if (state == FAIL)
                {
                    for (std::list<uint64>::const_iterator itr_trigger = portalTriggers.begin(); itr_trigger != portalTriggers.end(); ++itr_trigger)
                    {
                        if (Creature* trigger = instance->GetCreature(*itr_trigger))
                        {
                            // just in case
                            trigger->RemoveAllAuras();
                            trigger->AI()->Reset();
                        }
                    }

                    SpawnGameObject(GO_EXIT_PORTAL, exitPortalPosition);

                    if (GameObject* platform = instance->GetGameObject(platformGUID))
                        platform->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_DESTROYED);
                }
                else if (state == DONE)
                    SpawnGameObject(GO_EXIT_PORTAL, exitPortalPosition);
            }
            return true;
        }

        /// @todo this should be handled in map, maybe add a summon function in map
        // There is no other way afaik...
        void SpawnGameObject(uint32 entry, Position& pos)
        {
            GameObject* go = new GameObject;
            if (!go->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT), entry, instance,
                PHASEMASK_NORMAL, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(),
                0, 0, 0, 0, 120, GO_STATE_READY))
            {
                delete go;
                return;
            }

            instance->AddToMap(go);
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_NEXUS_RAID_PLATFORM:
                    platformGUID = go->GetGUID();
                    break;
                case GO_FOCUSING_IRIS_10:
                    if (instance->GetDifficultyID() == Difficulty::RAID_DIFFICULTY_10MAN_NORMAL)
                    {
                        irisGUID = go->GetGUID();
                        go->GetPosition(&focusingIrisPosition);
                    }
                    break;
                case GO_FOCUSING_IRIS_25:
                    if (instance->GetDifficultyID() == Difficulty::RAID_DIFFICULTY_25MAN_NORMAL)
                    {
                        irisGUID = go->GetGUID();
                        go->GetPosition(&focusingIrisPosition);
                    }
                    break;
                case GO_EXIT_PORTAL:
                    exitPortalGUID = go->GetGUID();
                    go->GetPosition(&exitPortalPosition);
                    break;
                case GO_HEART_OF_MAGIC_10:
                    if (instance->GetDifficultyID() == Difficulty::RAID_DIFFICULTY_10MAN_NORMAL)
                        heartOfMagicGUID = go->GetGUID();
                    break;
                case GO_HEART_OF_MAGIC_25:
                    if (instance->GetDifficultyID() == Difficulty::RAID_DIFFICULTY_25MAN_NORMAL)
                        heartOfMagicGUID = go->GetGUID();
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_VORTEX_TRIGGER:
                    vortexTriggers.push_back(creature->GetGUID());
                    break;
                case NPC_MALYGOS:
                    malygosGUID = creature->GetGUID();
                    creature->setActive(true);
                    break;
                case NPC_PORTAL_TRIGGER:
                    portalTriggers.push_back(creature->GetGUID());
                    creature->setActive(true);
                    break;
                case NPC_ALEXSTRASZA_BUNNY:
                    alexstraszaBunnyGUID = creature->GetGUID();
                    break;
                case NPC_ALEXSTRASZAS_GIFT:
                    giftBoxBunnyGUID = creature->GetGUID();
                    break;
            }
        }

        void OnUnitDeath(Unit* unit)
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            // Player continues to be moving after death no matter if spline will be cleared along with all movements,
            // so on next world tick was all about delay if box will pop or not (when new movement will be registered)
            // since in EoE you never stop falling. However root at this precise* moment works,
            // it will get cleared on release. If by any chance some lag happen "Reload()" and "RepopMe()" works,
            // last test I made now gave me 50/0 of this bug so I can't do more about it.
            unit->SetControlled(true, UNIT_STATE_ROOT);
        }

        void ProcessEvent(WorldObject* /*obj*/, uint32 eventId)
        {
            if (eventId == EVENT_FOCUSING_IRIS)
            {
                if (Creature* alexstraszaBunny = instance->GetCreature(alexstraszaBunnyGUID))
                {
                    alexstraszaBunny->CastSpell(alexstraszaBunny, SPELL_IRIS_OPENED);
                }

                if (Creature* malygos = instance->GetCreature(malygosGUID))
                    malygos->AI()->DoAction(0); // ACTION_LAND_ENCOUNTER_START

                if (GameObject* exitPortal = instance->GetGameObject(exitPortalGUID))
                    exitPortal->Delete();
            }
        }

        void VortexHandling()
        {
            if (Creature* malygos = instance->GetCreature(malygosGUID))
            {
                std::list<HostileReference*> m_threatlist = malygos->getThreatManager().getThreatList();
                for (std::list<uint64>::const_iterator itr_vortex = vortexTriggers.begin(); itr_vortex != vortexTriggers.end(); ++itr_vortex)
                {
                    if (m_threatlist.empty())
                        return;

                    uint8 counter = 0;
                    if (Creature* trigger = instance->GetCreature(*itr_vortex))
                    {
                        for (std::list<HostileReference*>::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                        {
                            if (Unit* target = (*itr)->getTarget())
                            {
                                Player* player = target->ToPlayer();

                                if (!player || !player->isAlive() || player->isGameMaster() || player->HasAura(SPELL_VORTEX_4))
                                    continue;

                                player->CastSpell(trigger, SPELL_VORTEX_4, true);
                                break;
                            }
                        }
                    }
                }
            }
        }

        void PowerSparksHandling()
        {
            bool next = (lastPortalGUID == portalTriggers.back() || !lastPortalGUID ? true : false);

            for (std::list<uint64>::const_iterator itr_trigger = portalTriggers.begin(); itr_trigger != portalTriggers.end(); ++itr_trigger)
            {
                if (next)
                {
                    if (Creature* trigger = instance->GetCreature(*itr_trigger))
                    {
                        lastPortalGUID = trigger->GetGUID();
                        trigger->CastSpell(trigger, SPELL_PORTAL_OPENED, true);
                        return;
                    }
                }

                if (*itr_trigger == lastPortalGUID)
                    next = true;
            }
        }

        void SetData(uint32 data, uint32 /*value*/)
        {
            switch (data)
            {
                case DATA_VORTEX_HANDLING:
                    VortexHandling();
                    break;
                case DATA_POWER_SPARKS_HANDLING:
                    PowerSparksHandling();
                    break;
                case DATA_RESPAWN_IRIS:
                    SpawnGameObject(instance->GetDifficultyID() == Difficulty::RAID_DIFFICULTY_25MAN_NORMAL ? GO_FOCUSING_IRIS_10 : GO_FOCUSING_IRIS_25, focusingIrisPosition);
                    break;
            }
        }

        uint64 GetData64(uint32 data)
        {
            switch (data)
            {
                case DATA_TRIGGER:
                    return vortexTriggers.front();
                case DATA_MALYGOS:
                    return malygosGUID;
                case DATA_PLATFORM:
                    return platformGUID;
                case DATA_ALEXSTRASZA_BUNNY_GUID:
                    return alexstraszaBunnyGUID;
                case DATA_HEART_OF_MAGIC_GUID:
                    return heartOfMagicGUID;
                case DATA_FOCUSING_IRIS_GUID:
                    return irisGUID;
                case DATA_GIFT_BOX_BUNNY_GUID:
                    return giftBoxBunnyGUID;
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "E E " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* str)
        {
            if (!str)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(str);

            char dataHead1, dataHead2;

            std::istringstream loadStream(str);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'E' && dataHead2 == 'E')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        private:
            std::list<uint64> vortexTriggers;
            std::list<uint64> portalTriggers;
            uint64 malygosGUID;
            uint64 irisGUID;
            uint64 lastPortalGUID;
            uint64 platformGUID;
            uint64 exitPortalGUID;
            uint64 heartOfMagicGUID;
            uint64 alexstraszaBunnyGUID;
            uint64 giftBoxBunnyGUID;
            Position focusingIrisPosition;
            Position exitPortalPosition;
    };
};

#ifndef __clang_analyzer__
void AddSC_instance_eye_of_eternity()
{
   new instance_eye_of_eternity();
}
#endif
