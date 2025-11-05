#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_MOB_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_MOB_H

// =============================================
//          MOB STRUCTURE DETINED
// =============================================

typedef struct MOB_Details{
    short MOB_ID;
    char Name[MAX_PLAYER_NAME];
    // STATUS SECTION START HERE ---:>
    short Health;
    short MAX_Health;
    short Mana;
    short MAx_Mana;
    short Stamina;
    short Max_Stamina;
    // ECONOMY & OTHERS ---:>
    short DROP_GOLD;
    short DROP_EXP;
    short Attack_DMG; // Basic Start From (5) Upto 40(Ultimate)
    short MOB_Turn;
    // ITEM SECTION ---:>
    weapon_details *MOB_Weapon;
    armor_details *MOB_Armor;
    leggings_details *MOB_Leggings;
    boot_details *MOB_BOOTS;
    // ABILITY SECTION ---:>
    ability_details *abilities;  // Dynamic array of abilities
    int ability_count; // If Anyone Want They Can Add In Future
}mob_details;



// =============================================
        // MOB-List ( Link List )
// =============================================
typedef struct MobList {
    mob_details mob;
    struct MobList *next;
} MobList;

extern MobList *PREDEFINED_MOBS_HEAD;




// =============================================
// EVERY WORKING FUNCTION RELATED TO MOB DEFINED HERE ---:>
// =============================================
mob_details* CREATE_SIMPLE_MOB(const short id, const char *name,
                              short health, short max_health, short mana, short max_mana,
                              short drop_gold, short drop_exp, short attack_dmg, short mob_turn,
                              weapon_details *weapon, armor_details *armor, leggings_details *leggings, boot_details *boots);
mob_details* CREATE_MOB_WITH_ABILITY(const short id, const char *name,
                                    short health, short max_health, short mana, short max_mana,
                                    short drop_gold, short drop_exp, short attack_dmg, short mob_turn,
                                    weapon_details *weapon, armor_details *armor, leggings_details *leggings, boot_details *boots,
                                    const Ability_Holder ability_holder, int num_abilities, ...);


void ADD_MOB(mob_details *mob); // ADD MOB TO Link List By Taking MOB_DETAILS Structure ---:>
void MOB_INITIALIZE(void); // LOAD AT THE START OF THE GAME ---:>
short Mob_Counter(); // A SIMPLE MOB COUNTER FOR TRACK & OTHER FUNCTION TO WORK ---:>


// =============================================
//                  FUTURE UPDATE
// =============================================
// MobList *Search_MOB_BY_ID(short id); // FOR FUTURE

#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_MOB_H