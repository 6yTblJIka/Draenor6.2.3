////////////////////////////////////////////////////////////////////////////////
//
// Project-Hellscream https://hellscream.org
// Copyright (C) 2018-2020 Project-Hellscream-6.2
// Discord https://discord.gg/CWCF3C9
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __TRINITY_SOCIALMGR_H
#define __TRINITY_SOCIALMGR_H

#include "DatabaseEnv.h"
#include "Common.h"

class SocialMgr;
class PlayerSocial;
class Player;
class WorldPacket;

enum FriendStatus
{
    FRIEND_STATUS_OFFLINE   = 0x00,
    FRIEND_STATUS_ONLINE    = 0x01,
    FRIEND_STATUS_AFK       = 0x02,
    FRIEND_STATUS_DND       = 0x04,
    FRIEND_STATUS_RAF       = 0x08
};

enum SocialFlag
{
    SOCIAL_FLAG_FRIEND      = 0x01,
    SOCIAL_FLAG_IGNORED     = 0x02,
    SOCIAL_FLAG_MUTED       = 0x04,                          // guessed
    SOCIAL_FLAG_UNK         = 0x08                           // Unknown - does not appear to be RaF
};

struct FriendInfo
{
    FriendStatus Status;
    uint8 Flags;
    uint32 Area;
    uint8 Level;
    uint8 Class;
    std::string Note;

    FriendInfo() : Status(FRIEND_STATUS_OFFLINE), Flags(0), Area(0), Level(0), Class(0), Note()
    {

    }

    FriendInfo(uint8 flags, const std::string& note) : Status(FRIEND_STATUS_OFFLINE), Flags(flags), Area(0), Level(0), Class(0), Note(note)
    {

    }
};

typedef std::map<uint32, FriendInfo> PlayerSocialMap;
typedef std::map<uint32, PlayerSocial> SocialMap;

/// Results of friend related commands
enum FriendsResult
{
    FRIEND_DB_ERROR         = 0x00,
    FRIEND_LIST_FULL        = 0x01,
    FRIEND_ONLINE           = 0x02,
    FRIEND_OFFLINE          = 0x03,
    FRIEND_NOT_FOUND        = 0x04,
    FRIEND_REMOVED          = 0x05,
    FRIEND_ADDED_ONLINE     = 0x06,
    FRIEND_ADDED_OFFLINE    = 0x07,
    FRIEND_ALREADY          = 0x08,
    FRIEND_SELF             = 0x09,
    FRIEND_ENEMY            = 0x0A,
    FRIEND_IGNORE_FULL      = 0x0B,
    FRIEND_IGNORE_SELF      = 0x0C,
    FRIEND_IGNORE_NOT_FOUND = 0x0D,
    FRIEND_IGNORE_ALREADY   = 0x0E,
    FRIEND_IGNORE_ADDED     = 0x0F,
    FRIEND_IGNORE_REMOVED   = 0x10,
    FRIEND_IGNORE_AMBIGUOUS = 0x11,                         // That name is ambiguous, type more of the player's server name
    FRIEND_MUTE_FULL        = 0x12,
    FRIEND_MUTE_SELF        = 0x13,
    FRIEND_MUTE_NOT_FOUND   = 0x14,
    FRIEND_MUTE_ALREADY     = 0x15,
    FRIEND_MUTE_ADDED       = 0x16,
    FRIEND_MUTE_REMOVED     = 0x17,
    FRIEND_MUTE_AMBIGUOUS   = 0x18,                         // That name is ambiguous, type more of the player's server name
    FRIEND_UNK7             = 0x19,                         // no message at client
    FRIEND_UNKNOWN          = 0x1A                          // Unknown friend response from server
};

#define SOCIALMGR_FRIEND_LIMIT  50
#define SOCIALMGR_IGNORE_LIMIT  50

class PlayerSocial
{
    friend class SocialMgr;
    public:
        PlayerSocial();
        ~PlayerSocial();
        // adding/removing
        bool AddToSocialList(uint32 friend_guid, bool ignore);
        void RemoveFromSocialList(uint32 friend_guid, bool ignore);
        void SetFriendNote(uint32 friendGuid, std::string note);
        // Packet send's
        void SendSocialList(Player* player);
        // Misc
        bool HasFriend(uint32 friend_guid);
        bool HasIgnore(uint32 ignore_guid);
        uint32 GetPlayerGUID() const { return m_playerGUID; }
        void SetPlayerGUID(uint32 guid, uint32 p_AccountID) { m_playerGUID = guid; m_AccountID = p_AccountID; }
        uint32 GetNumberOfSocialsWithFlag(SocialFlag flag);
        PlayerSocialMap const& GetSocialMap() const { return m_playerSocialMap; }
    private:
        PlayerSocialMap m_playerSocialMap;
        uint32 m_playerGUID;
        uint32 m_AccountID;
};

class SocialMgr
{
    friend class ACE_Singleton<SocialMgr, ACE_Null_Mutex>;

    private:
        SocialMgr();
        ~SocialMgr();

    public:
        // Misc
        void RemovePlayerSocial(uint32 guid) { m_socialMap.erase(guid); }

        void GetFriendInfo(Player* player, uint32 friendGUID, FriendInfo &friendInfo);
        // Packet management
        void SendFriendStatus(Player* player, FriendsResult result, uint32 friend_guid, bool broadcast);
        void BroadcastToFriendListers(Player* player, WorldPacket* packet);
        // Loading
        PlayerSocial *LoadFromDB(PreparedQueryResult result, uint32 guid, uint32 account_id);
    private:
        SocialMap m_socialMap;
};

#define sSocialMgr ACE_Singleton<SocialMgr, ACE_Null_Mutex>::instance()
#endif

