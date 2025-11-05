#include "../HEADER_FILES/Header_Store.h"
MobList *PREDEFINED_MOBS_HEAD = NULL;
ability_details *ability;// Linked List Head
extern ability_details PREDEFINED_ABILITIES[];


void ADD_MOB(mob_details *mob) {
    MobList *new_node = malloc(sizeof(MobList));
    new_node->mob = *mob;  // Copy the mob data
    new_node->next = PREDEFINED_MOBS_HEAD;
    PREDEFINED_MOBS_HEAD = new_node;

    DBG_MOBS("Added Mob: [%s] (ID: %d)\n", mob->Name, mob->MOB_ID);
    DBG_NEW_LINE("");
}


// void ADD_ABILITY(ability_details *ability) {
//     // ABILITY *new_node = malloc(sizeof(ability));
//
//
// }

mob_details* CREATE_SIMPLE_MOB(const short id, const char *name,
                              short health, short max_health, short mana, short max_mana,
                              short drop_gold, short drop_exp, short attack_dmg, short mob_turn,
                              weapon_details *weapon, armor_details *armor, leggings_details *leggings, boot_details *boots) {
    mob_details *mob = malloc(sizeof(mob_details));
    if (!mob) return NULL;

    // Initialize all basic fields
    mob->MOB_ID = id;
    snprintf(mob->Name, sizeof(mob->Name), "%s", name);
    mob->Health = health;
    mob->MAX_Health = max_health;
    mob->Mana = mana;
    mob->MAx_Mana = max_mana;
    mob->Stamina = 100;
    mob->Max_Stamina = 100;
    mob->DROP_GOLD = drop_gold;
    mob->DROP_EXP = drop_exp;
    mob->Attack_DMG = attack_dmg;
    mob->MOB_Turn = mob_turn;
    mob->MOB_Weapon = weapon;
    mob->MOB_Armor = armor;
    mob->MOB_Leggings = leggings;
    mob->MOB_BOOTS = boots;

    mob->abilities = NULL;
    mob->ability_count = 0;

    ADD_MOB(mob);
    return mob;
}

mob_details* CREATE_MOB_WITH_ABILITY(const short id, const char *name,
                                    short health, short max_health, short mana, short max_mana,
                                    short drop_gold, short drop_exp, short attack_dmg, short mob_turn,
                                    weapon_details *weapon, armor_details *armor, leggings_details *leggings, boot_details *boots,
                                    const Ability_Holder ability_holder, int num_abilities, ...) {

    mob_details *mob = malloc(sizeof(mob_details));
    if (!mob) return NULL;

    // Initialize basic mob fields
    mob->MOB_ID = id;
    snprintf(mob->Name, sizeof(mob->Name), "%s", name);
    mob->Health = health;
    mob->MAX_Health = max_health;
    mob->Mana = mana;
    mob->MAx_Mana = max_mana;
    mob->Stamina = 100;
    mob->Max_Stamina = 100;
    mob->DROP_GOLD = drop_gold;
    mob->DROP_EXP = drop_exp;
    mob->Attack_DMG = attack_dmg;
    mob->MOB_Turn = mob_turn;
    mob->MOB_Weapon = weapon;
    mob->MOB_Armor = armor;
    mob->MOB_Leggings = leggings;
    mob->MOB_BOOTS = boots;

    // Initialize abilities
    mob->abilities = NULL;
    mob->ability_count = 0;

    // Add abilities if any
    if (num_abilities > 0) {
        mob->abilities = malloc(num_abilities * sizeof(ability_details));
        mob->ability_count = num_abilities;

        va_list args;
        va_start(args, num_abilities);
        for(int i = 0; i < num_abilities; i++) {
            int ability_id = va_arg(args, int);  // FIX: Use int instead of short
            // Use the global PREDEFINED_ABILITIES array from Ability.c
            extern ability_details PREDEFINED_ABILITIES[];
            mob->abilities[i] = PREDEFINED_ABILITIES[ability_id];
        }
        va_end(args);
    }

    ADD_MOB(mob);
    return mob;
}

void MOB_INITIALIZE(void) {
    /* mob->MOB_ID = id; // 1
    snprintf(mob->Name, sizeof(mob->Name), "%s", name); // 2
    mob->Health = health; // 3
    mob->MAX_Health = max_health; // 4
    mob->Mana = mana; // 5
    mob->MAx_Mana = max_mana; // 6
    mob->DROP_GOLD = drop_gold; // 7
    mob->DROP_EXP = drop_exp; // 8
    mob->Attack_DMG = attack_dmg; // 9
    mob->MOB_Turn = mob_turn; // 10
    mob->MOB_Weapon = weapon; // 11
    mob->MOB_Armor = armor;*/ // 12
    // Use CREATE_AND_ADD_MOB which handles linked list automatically

// 1. Zombie
CREATE_MOB_WITH_ABILITY(0, "ZOMBIE", 50,50, 30,30,35,15, 3, 0,
                       &PRE_DEFINED_WEAPONS[1], &PRE_DEFINED_ARMORS[1],
                       &PRE_DEFINED_LEGGINGS[1], &PRE_DEFINED_BOOTS[1],
                       MOB_USER, 1, 8);  // Deep Bite

// 2. Skeleton Archer
CREATE_MOB_WITH_ABILITY(1, "SKELETON_ARCHER", 40,40, 25,25,25,12, 5, 0,
                       &PRE_DEFINED_WEAPONS[1], &PRE_DEFINED_ARMORS[1],
                       &PRE_DEFINED_LEGGINGS[2], &PRE_DEFINED_BOOTS[2],
                       MOB_USER, 1, 9);  // Bone Arrow

// 3. Goblin Warrior
CREATE_MOB_WITH_ABILITY(2, "GOBLIN_WARRIOR", 35,35, 20,20,18,8, 4, 0,
                       &PRE_DEFINED_WEAPONS[2], &PRE_DEFINED_ARMORS[1],
                       &PRE_DEFINED_LEGGINGS[1], &PRE_DEFINED_BOOTS[1],
                       MOB_USER, 1, 10);  // Goblin Smash

// 4. Dark Mage
CREATE_MOB_WITH_ABILITY(3, "DARK_MAGE", 30,30, 50,50,40,20, 2, 0,
                       &PRE_DEFINED_WEAPONS[0], &PRE_DEFINED_ARMORS[2],
                       &PRE_DEFINED_LEGGINGS[2], &PRE_DEFINED_BOOTS[2],
                       MOB_USER, 1, 11);  // Shadow Bolt

// 5. Orc Berserker
CREATE_MOB_WITH_ABILITY(4, "ORC_BERSERKER", 70,70, 15,15,45,18, 6, 0,
                       &PRE_DEFINED_WEAPONS[2], &PRE_DEFINED_ARMORS[2],
                       &PRE_DEFINED_LEGGINGS[3], &PRE_DEFINED_BOOTS[3],
                       MOB_USER, 1, 12);  // Rage Strike

// 6. Spider Queen
CREATE_MOB_WITH_ABILITY(5, "SPIDER_QUEEN", 45,45, 35,35,38,16, 4, 0,
                       &PRE_DEFINED_WEAPONS[0], &PRE_DEFINED_ARMORS[1],
                       &PRE_DEFINED_LEGGINGS[1], &PRE_DEFINED_BOOTS[1],
                       MOB_USER, 1, 13);  // Venom Bite

// 7. Ice Elemental
CREATE_MOB_WITH_ABILITY(6, "ICE_ELEMENTAL", 55,55, 40,40,42,22, 3, 0,
                       &PRE_DEFINED_WEAPONS[0], &PRE_DEFINED_ARMORS[3],
                       &PRE_DEFINED_LEGGINGS[3], &PRE_DEFINED_BOOTS[3],
                       MOB_USER, 1, 14);  // Frost Nova

// 8. Bandit Leader
CREATE_MOB_WITH_ABILITY(7, "BANDIT_LEADER", 48,48, 28,28,50,25, 5, 0,
                       &PRE_DEFINED_WEAPONS[3], &PRE_DEFINED_ARMORS[2],
                       &PRE_DEFINED_LEGGINGS[2], &PRE_DEFINED_BOOTS[2],
                       MOB_USER, 1, 15);  // Soul Drain

// 9. Lich King
CREATE_MOB_WITH_ABILITY(8, "LICH_KING", 80,80, 60,60,100,50, 8, 0,
                       &PRE_DEFINED_WEAPONS[3], &PRE_DEFINED_ARMORS[3],
                       &PRE_DEFINED_LEGGINGS[4], &PRE_DEFINED_BOOTS[4],
                       MOB_USER, 2, 11, 15);  // Shadow Bolt + Soul Drain

// 10. Dragon Whelp
CREATE_MOB_WITH_ABILITY(9, "DRAGON_WHELP", 65,65, 45,45,75,35, 7, 0,
                       &PRE_DEFINED_WEAPONS[0], &PRE_DEFINED_ARMORS[3],
                       &PRE_DEFINED_LEGGINGS[3], &PRE_DEFINED_BOOTS[4],
                       MOB_USER, 1, 16);  // Fire Breath
    // Debug: Print all mobs in linked list
    MobList *current = PREDEFINED_MOBS_HEAD;
    while (current != NULL) {
        DBG_MOBS_INIT("MOB Found: ( %s ) Health: [ %d ], Weapon: [ %s ]\n"
            ,current->mob.Name, current->mob.Health
            ,current->mob.MOB_Weapon->Weapon_NAME);

        current = current->next;
    }
    DBG_NEW_LINE("");
}

MobList *Search_MOB_BY_ID(const short id) {
    MobList *current = PREDEFINED_MOBS_HEAD;
    while (current != NULL) {
        if (current->mob.MOB_ID == id) {
            DBG_MOBS("\nMOB FOUND ! \nName : [%s]\nHealth : [%d]\nMana : [%d]\nAttack_DMG : [%d]\nMOB_TURN : [%d] \n"
                     "Armor_Name : [%s] , Armor_Protection : [%d]\n"
                     "Weapon_Name : [%s] , Weapon_DMG : [%d] "
                ,current->mob.Name,current->mob.Health,current->mob.Mana,current->mob.Attack_DMG,current->mob.MOB_Turn
                ,current->mob.MOB_Armor->Armor_NAME,current->mob.MOB_Armor->Armor_Protection
                ,current->mob.MOB_Weapon->Weapon_NAME,current->mob.MOB_Weapon->Weapon_DMG);
            printf("MOB FOUND!\n");
            return current;
        }
        current = current->next; // Move Next
    }
    printf("MOB Not FOUND!\n");

    return NULL; // Return NULL IF NOT FOUND
    DBG_NEW_LINE("");
}

short Mob_Counter() {
    int i = 0;
    MobList *current = PREDEFINED_MOBS_HEAD;
    while (current != NULL) {
        i++;
        current = current->next;
    }
    return i;
}