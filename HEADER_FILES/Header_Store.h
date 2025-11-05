#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_HEADER_STORE_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_HEADER_STORE_H

// =============================================
//            C Libraries Added Here
// =============================================

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <error.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>

// =============================================
//          LIMIT TYPE DEFINED ADDED HERE
// =============================================
#define MAX_ITEM_NAME_LEN 16
#define CUSTOM_ITEM_NAME_LEN 32

// USER_INFORMATION.C
#define MAX_PLAYER_NAME 16
#define NOT_PLAYER_TURN 0
#define PLAYER_TURN 1
#define MAX_INVENTORY_SIZE 10

// ABILITY.C
#define ABILITY_MAX_NAME 20
#define ABILITY_DIALOGUE 64

// =============================================
//        Every Header FILE Defined HERE
// =============================================

#include "User_Information.h"
#include "Mob.h"
#include "Items_Properties.h"
#include "Predefined_Values.h"
#include "Game_Mechanics.h"
#include "Display_Logic.h"
#include "Devs_kit.h"
#include "Save_Load.h"


#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_HEADER_STORE_H