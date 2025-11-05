#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_USER_INFO_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_USER_INFO_H
#include "Items_Properties.h"

// =============================================
//    STRUCTURE FOR PLAYER ON HAND INVENTORY
// =============================================
typedef struct PLAYER_ON_HAND_INVENTORY{
    struct Armor{
        short Armor_ID;
        char Armor_Name[MAX_ITEM_NAME_LEN];
        short Armor_Protection;
    }armor;
    struct Weapon{
        short Weapon_ID;
        char Weapon_Name[MAX_ITEM_NAME_LEN];
        short Weapon_DMG;
    }weapon;
    struct Leggings{
        short leggings_ID;
        char Leggings_Name[MAX_ITEM_NAME_LEN];
        short Leggings_Protection;
    }leggings;
    struct Boots{
        short Boot_ID;
        char Boot_Name[MAX_ITEM_NAME_LEN];
        short Boot_Protection;
    }boots;
}player_on_hand_inventory;



// ==========================================================
//     STRUCT & TYPEDEF ENUM FOR ABILITY USERS / HOLDERS
// ==========================================================
typedef enum Ability_Holder {
    HUMAN_USER,
    MOB_USER
} Ability_Holder;

typedef struct ABILITY {
    Ability_Holder ability_holder;
    short ability_id;
    char ability_name[ABILITY_MAX_NAME];
    short mana_usage;
    short ability_dmg;
    char ability_dialogue[ABILITY_DIALOGUE]; // Custom MONSTER DIALOGUE AFTER USE
    struct ABILITY_COOLDOWN {
        short cooldown; // Time Devs Set For Ability Cooldown
        short ability_counter; // A Timer To Check If Ability On Cooldown
    }ability_cooldown;
    short total_ability; // Total Register Ability Human + Mob
}ability_details;


// =============================================
//        Player Information & Structure
// =============================================
typedef struct PLAYER_Details{
    char Name[MAX_PLAYER_NAME]; // Player Name
    short Player_Level;
    // Player Stats ---:>
    short Health;
    short MAX_Health;
    short Mana; // Player Mana Highest CAP 150
    short MAX_Mana;
    short Stamina;
    short MAX_Stamina;
    // Economy Section ---:>
    int GOLD;
    int EXP;
    int MAX_EXP;
    // Inventory Section
    short Attack_DMG;
    short Player_Turn; // Check Is Player Turn Or Not
    // INVENTORY SECTIONS ---:>
    struct PLAYER_ON_HAND_INVENTORY p_on_hand_inv;
    // =============================================
    //  Bag / Inventory | Where Every Item Stored
    // =============================================
    itemlist *s_inv;
    int inventory_size;
    // PLAYER ABILITY SECTION ---:>
    ability_details *ability;
}player_details;

// =============================================
//          FUNCTION RELATED TO PLAYER
// =============================================
void Player_Status(void); // Call THE Default Player Upon Running The Game
void Player_Inv_Looper(player_details *i); // Display Player Whole BaG



// =============================================
//          JUST SOME RANDOM STUFFS
// =============================================
extern player_details *p;
extern player_on_hand_inventory *inv;
extern ability_details *ability;

#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_USER_INFO_H