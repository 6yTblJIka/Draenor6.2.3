# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_Accounts Accounts/*.cpp Accounts/*.h)
file(GLOB_RECURSE sources_Anticheat Anticheat/*.cpp Anticheat/*.h)
file(GLOB_RECURSE sources_Achievements Achievements/*.cpp Achievements/*.h)
file(GLOB_RECURSE sources_Addons Addons/*.cpp Addons/*.h)
file(GLOB_RECURSE sources_AI AI/*.cpp AI/*.h AI/*.hpp)

file(GLOB_RECURSE sources_AuctionHouse AuctionHouse/*.cpp AuctionHouse/*.h)
file(GLOB_RECURSE sources_Battlefield Battlefield/*.cpp Battlefield/*.h)
file(GLOB_RECURSE sources_Battlegrounds Battlegrounds/*.cpp Battlegrounds/*.h Battlegrounds/*.hpp)

file(GLOB_RECURSE sources_BlackMarket BlackMarket/*.cpp BlackMarket/*.h)
file(GLOB_RECURSE sources_BattlePay BattlePay/*.cpp BattlePay/*.h)
file(GLOB_RECURSE sources_Calendar Calendar/*.cpp Calendar/*.h)

file(GLOB_RECURSE sources_Chat Chat/*.cpp Chat/*.h)
file(GLOB_RECURSE sources_Cinematic Cinematic/*.cpp Cinematic/*.h)
file(GLOB_RECURSE sources_Combat Combat/*.cpp Combat/*.h)
file(GLOB_RECURSE sources_Conditions Conditions/*.cpp Conditions/*.h)
file(GLOB_RECURSE sources_DataStores DataStores/*.cpp DataStores/*.h)
file(GLOB_RECURSE sources_DungeonFinding DungeonFinding/*.cpp DungeonFinding/*.h)
file(GLOB_RECURSE sources_Entities Entities/*.cpp Entities/*.h Entities/*.hpp)
file(GLOB_RECURSE sources_Events Events/*.cpp Events/*.h)
file(GLOB_RECURSE sources_Globals Globals/*.cpp Globals/*.h)
file(GLOB_RECURSE sources_Grids Grids/*.cpp Grids/*.h)
file(GLOB_RECURSE sources_Groups Groups/*.cpp Groups/*.h)
file(GLOB_RECURSE sources_Guilds Guilds/*.cpp Guilds/*.h)
file(GLOB_RECURSE sources_Handlers Handlers/*.cpp Handlers/*.h)
file(GLOB_RECURSE sources_Instances Instances/*.cpp Instances/*.h)
file(GLOB_RECURSE sources_Loot Loot/*.cpp Loot/*.h)
file(GLOB_RECURSE sources_Mails Mails/*.cpp Mails/*.h)
file(GLOB_RECURSE sources_Maps Maps/*.cpp Maps/*.h)
file(GLOB_RECURSE sources_Miscellaneous Miscellaneous/*.cpp Miscellaneous/*.h)
file(GLOB_RECURSE sources_Movement Movement/*.cpp Movement/*.h)
file(GLOB_RECURSE sources_OutdoorPvP OutdoorPvP/*.cpp OutdoorPvP/*.h)
file(GLOB_RECURSE sources_Pools Pools/*.cpp Pools/*.h)
file(GLOB_RECURSE sources_Quests Quests/*.cpp Quests/*.h)
file(GLOB_RECURSE sources_Reputation Reputation/*.cpp Reputation/*.h)
file(GLOB_RECURSE sources_Scripting Scripting/*.cpp Scripting/*.h Scripting/*.hpp)
file(GLOB_RECURSE sources_Server Server/*.cpp Server/*.h)
file(GLOB_RECURSE sources_Cross Server/Cross/*.cpp Server/Cross/*.h)
file(GLOB_RECURSE sources_Skills Skills/*.cpp Skills/*.h Skills/*.hpp)
file(GLOB_RECURSE sources_Spells Spells/*.cpp Spells/*.h)
file(GLOB_RECURSE sources_Texts Texts/*.cpp Texts/*.h)

file(GLOB_RECURSE sources_Tools Tools/*.cpp Tools/*.h)
file(GLOB_RECURSE sources_Tickets Tickets/*.cpp Tickets/*.h)

file(GLOB_RECURSE sources_Warden Warden/*.cpp Warden/*.h)
file(GLOB_RECURSE sources_Weather Weather/*.cpp Weather/*.h)
file(GLOB_RECURSE sources_PetBattle PetBattle/*.cpp PetBattle/*.h)
file(GLOB_RECURSE sources_World World/*.cpp World/*.h World/*.hpp)
file(GLOB_RECURSE sources_shared_ptrs SharedPtrs/*.h)
file(GLOB_RECURSE sources_Cinematic Cinematic/*.h Cinematic/*.cpp)

file(GLOB_RECURSE sources_Garrison Garrison/*.hpp Garrison/*.cpp)
file(GLOB_RECURSE sources_Vignette Vignette/*.hpp Vignette/*.cpp Vignette/*.hxx)

# Create game-libary

if (USE_COREPCH)
  set(game_STAT_PCH_HDR PrecompiledHeaders/gamePCH.h)
  set(game_STAT_PCH_SRC PrecompiledHeaders/gamePCH.cpp)
endif ()

set(game_STAT_SRCS
  ${game_STAT_SRCS}
  ${sources_Accounts}
  ${sources_Anticheat}
  ${sources_Achievements}
  ${sources_Addons}
  ${sources_AI}
  ${sources_AuctionHouse}
  ${sources_Battlefield}
  ${sources_Battlegrounds}
  ${sources_BattlePet}

  ${sources_BlackMarket}
  ${sources_BattlePay}
  ${sources_Calendar}

  ${sources_Chat}
  ${sources_Cinematic}
  ${sources_Combat}
  ${sources_Conditions}
  ${sources_DataStores}
  ${sources_DungeonFinding}
  ${sources_Entities}
  ${sources_Events}
  ${sources_Globals}
  ${sources_Grids}
  ${sources_Groups}
  ${sources_Guilds}
  ${sources_Handlers}
  ${sources_Instances}
  ${sources_Loot}
  ${sources_Mails}
  ${sources_Maps}
  ${sources_Miscellaneous}
  ${sources_Movement}
  ${sources_OutdoorPvP}
  ${sources_Pools}
  ${sources_Quests}
  ${sources_Reputation}
  ${sources_Scripting}
  ${sources_Server}
  ${sources_Cross}
  ${sources_Skills}
  ${sources_Spells}
  ${sources_Texts}
  ${sources_Tools}
  ${sources_Tickets}
  ${sources_Warden}
  ${sources_Weather}
  ${sources_World}
  ${sources_Cinematic}
  ${sources_PetBattle}
  ${sources_Garrison}
  ${sources_shared_ptrs}
  ${sources_Vignette}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_SOURCE_DIR}/dep/boost
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour/Include
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour/
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Recast/
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Recast/Include
  ${CMAKE_SOURCE_DIR}/src/server/collision
  ${CMAKE_SOURCE_DIR}/src/server/collision/Management
  ${CMAKE_SOURCE_DIR}/src/server/collision/Models
  ${CMAKE_SOURCE_DIR}/src/server/collision/Maps
  ${CMAKE_SOURCE_DIR}/src/server/collision/Pathfinding
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic/LinkedReference
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/server/shared/Reporting
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Accounts
  ${CMAKE_CURRENT_SOURCE_DIR}/Anticheat
  ${CMAKE_CURRENT_SOURCE_DIR}/Achievements
  ${CMAKE_CURRENT_SOURCE_DIR}/Addons
  ${CMAKE_CURRENT_SOURCE_DIR}/AI
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/CoreAI
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/ScriptedAI
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/SmartScripts
  ${CMAKE_CURRENT_SOURCE_DIR}/AuctionHouse
  ${CMAKE_CURRENT_SOURCE_DIR}/Battlefield
  ${CMAKE_CURRENT_SOURCE_DIR}/Battlefield/Zones
  ${CMAKE_CURRENT_SOURCE_DIR}/Battlegrounds
  ${CMAKE_CURRENT_SOURCE_DIR}/Battlegrounds/Zones
  ${CMAKE_CURRENT_SOURCE_DIR}/BattlePet

  ${CMAKE_CURRENT_SOURCE_DIR}/BattlePay
  ${CMAKE_CURRENT_SOURCE_DIR}/BlackMarket
  ${CMAKE_CURRENT_SOURCE_DIR}/Calendar
  ${CMAKE_CURRENT_SOURCE_DIR}/Chat
  ${CMAKE_CURRENT_SOURCE_DIR}/Chat/Channels
  ${CMAKE_CURRENT_SOURCE_DIR}/Cinematic
  ${CMAKE_CURRENT_SOURCE_DIR}/Combat

  ${CMAKE_CURRENT_SOURCE_DIR}/Garrison

  ${CMAKE_CURRENT_SOURCE_DIR}/Conditions
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStores
  ${CMAKE_CURRENT_SOURCE_DIR}/DungeonFinding
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/AreaTrigger
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Creature
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Conversation
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Corpse
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/DynamicObject
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/GameObject
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Item
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Item/Container
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Object
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Object/Updates
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Pet
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Player
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Totem
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Unit
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Vehicle
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Transport
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/SceneObject
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Taxi
  ${CMAKE_CURRENT_SOURCE_DIR}/Events
  ${CMAKE_CURRENT_SOURCE_DIR}/Globals
  ${CMAKE_CURRENT_SOURCE_DIR}/Grids/Cells
  ${CMAKE_CURRENT_SOURCE_DIR}/Grids/Notifiers
  ${CMAKE_CURRENT_SOURCE_DIR}/Grids
  ${CMAKE_CURRENT_SOURCE_DIR}/Groups
  ${CMAKE_CURRENT_SOURCE_DIR}/Guilds
  ${CMAKE_CURRENT_SOURCE_DIR}/Handlers
  ${CMAKE_CURRENT_SOURCE_DIR}/Instances
  ${CMAKE_CURRENT_SOURCE_DIR}/Loot
  ${CMAKE_CURRENT_SOURCE_DIR}/Mails
  ${CMAKE_CURRENT_SOURCE_DIR}/Maps
  ${CMAKE_CURRENT_SOURCE_DIR}/Miscellaneous
  ${CMAKE_CURRENT_SOURCE_DIR}/Movement
  ${CMAKE_CURRENT_SOURCE_DIR}/Movement/Spline
  ${CMAKE_CURRENT_SOURCE_DIR}/Movement/MovementGenerators
  ${CMAKE_CURRENT_SOURCE_DIR}/Movement/Waypoints
  ${CMAKE_CURRENT_SOURCE_DIR}/OutdoorPvP
  ${CMAKE_CURRENT_SOURCE_DIR}/Pools
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
  ${CMAKE_CURRENT_SOURCE_DIR}/Quests
  ${CMAKE_CURRENT_SOURCE_DIR}/Reputation
  ${CMAKE_CURRENT_SOURCE_DIR}/Scripting
  ${CMAKE_CURRENT_SOURCE_DIR}/Server/Cross
  ${CMAKE_CURRENT_SOURCE_DIR}/Server/Protocol
  ${CMAKE_CURRENT_SOURCE_DIR}/Server
  ${CMAKE_CURRENT_SOURCE_DIR}/Skills
  ${CMAKE_CURRENT_SOURCE_DIR}/Spells
  ${CMAKE_CURRENT_SOURCE_DIR}/Spells/Auras
  ${CMAKE_CURRENT_SOURCE_DIR}/Spells/SpellLog
  ${CMAKE_CURRENT_SOURCE_DIR}/Texts
  ${CMAKE_CURRENT_SOURCE_DIR}/Tools
  ${CMAKE_CURRENT_SOURCE_DIR}/Tickets
  ${CMAKE_CURRENT_SOURCE_DIR}/Warden
  ${CMAKE_CURRENT_SOURCE_DIR}/Warden/Modules
  ${CMAKE_CURRENT_SOURCE_DIR}/Weather
  ${CMAKE_CURRENT_SOURCE_DIR}/PetBattle
  ${CMAKE_CURRENT_SOURCE_DIR}/World
  ${CMAKE_CURRENT_SOURCE_DIR}/SharedPtrs
  ${CMAKE_CURRENT_SOURCE_DIR}/Vignette
  ${CMAKE_SOURCE_DIR}/src/server/scripts/PrecompiledHeaders
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
  ${MSFRAMEWORK_INCLUDE_DIR}
)

add_definitions("-DGAME_SERVER_PROJECTS")

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(game STATIC
  ${game_STAT_SRCS}
  ${game_STAT_PCH_SRC}
)
set_property(TARGET game PROPERTY FOLDER "server")

add_dependencies(game revision.h)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(game ${game_STAT_PCH_HDR} ${game_STAT_PCH_SRC})
endif ()
