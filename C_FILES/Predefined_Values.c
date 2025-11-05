#include "../Headers/Header_Store.h"

// =============================================================================
// PREDEFINED ABILITIES DATABASE
// =============================================================================

/**
 * Global array containing all predefined abilities for both HUMANS and MOBS
 * Structure: {user_type, ability_id, name, mana_cost, damage, dialogue, cooldown}
 * Note: Negative damage values represent healing abilities
 */
ability_details PREDEFINED_ABILITIES[] = {
    // ==================== HUMAN ABILITIES (IDs 0-7) ====================
    {HUMAN_USER, 0, "Power Strike",     10, 25, "You strike with immense power!",        {2, 0}},
    {HUMAN_USER, 1, "Fire Ball",        15, 35, "You launch a fiery projectile!",        {3, 0}},
    {HUMAN_USER, 2, "Heal",             20, -30, "You heal your wounds!",               {4, 0}},  // Negative damage = healing
    {HUMAN_USER, 3, "Shield Bash",      5,  15, "You bash with your shield!",           {1, 0}},
    {HUMAN_USER, 4, "Double Slash",     12, 40, "You strike twice in quick succession!", {3, 0}},
    {HUMAN_USER, 5, "Poison Dart",      8,  20, "You throw a poisoned dart!",           {2, 0}},
    {HUMAN_USER, 6, "Lightning Bolt",   25, 50, "You summon a lightning bolt!",         {5, 0}},
    {HUMAN_USER, 7, "Berserk Rage",     30, 60, "You enter a berserker rage!",          {6, 0}},

    // ===================== MOB ABILITIES (IDs 8-15) =====================
    {MOB_USER, 8,  "Deep Bite",        15, 25, "Zombie has bitten you, you are bleeding!", {3, 0}},
    {MOB_USER, 9,  "Bone Arrow",       20, 18, "Piercing arrow strikes true!",            {2, 0}},
    {MOB_USER, 10, "Goblin Smash",     15, 12, "Ugg smash puny human!",                  {4, 0}},
    {MOB_USER, 11, "Shadow Bolt",      35, 25, "Dark energy consumes you!",              {3, 0}},
    {MOB_USER, 12, "Rage Strike",      10, 30, "Orc smash! You feel bones crack!",       {5, 0}},
    {MOB_USER, 13, "Venom Bite",       30, 20, "Venom courses through your veins!",      {4, 0}},
    {MOB_USER, 14, "Frost Nova",       40, 22, "Freezing cold slows your movements!",    {4, 0}},
    {MOB_USER, 15, "Soul Drain",       50, 40, "Your very soul is being drained!",       {5, 0}}
};


weapon_details PRE_DEFINED_WEAPONS[] = {
    {0, "Bare Hand", 3},
    {1, "Basic Sword", 5},
    {2, "Iron Sword", 14},
    {3, "Dragon Blade", 45},
};
int PRE_DEFINED_WEAPONS_COUNT = sizeof(PRE_DEFINED_WEAPONS) / sizeof(PRE_DEFINED_WEAPONS[0]);

armor_details PRE_DEFINED_ARMORS[] = {
    {1, "Torn Cloth", 1},
    {1, "Basic Armor", 5},
    {2, "Iron Armor", 8},
    {3, "Dragon Scale", 14},
};
int PRE_DEFINED_ARMORS_COUNT = sizeof(PRE_DEFINED_ARMORS) / sizeof(PRE_DEFINED_ARMORS[0]);

leggings_details PRE_DEFINED_LEGGINGS[] = {
    {0, "Underwear", 0},
    {1, "Torn Cloth", 1},
    {2, "Basic Leggings", 3},
    {3, "Iron Leggings", 5},
    {4, "Dragon Blade", 30},
};
int PRE_DEFINED_LEGGINGS_COUNT = sizeof(PRE_DEFINED_LEGGINGS) / sizeof(PRE_DEFINED_LEGGINGS[0]);

boot_details PRE_DEFINED_BOOTS[] = {
    {0, "Grass Shoe", 0},
    {1, "It's a Boot?", 1},
    {2, "Basic Boots", 2},
    {3, "Iron Boots", 4},
    {4, "Dragon Boots", 24},
};
int PRE_DEFINED_BOOTS_COUNT = sizeof(PRE_DEFINED_BOOTS) / sizeof(PRE_DEFINED_BOOTS[0]);


// =============================================
// PREDEFINED MOBS DATABASE DEFINITIONS
// =============================================

mob_details PRE_DEFINED_MOBS[] = {
    // Goblin Warrior
    {
        1, "Goblin Warrior",
        50, 50,    // Health, Max Health
        30, 30,    // Mana, Max Mana
        100, 100,  // Stamina, Max Stamina
        10, 15,    // Drop Gold, Drop EXP
        8, 0,      // Attack DMG, Mob Turn
        &PRE_DEFINED_WEAPONS[1],  // Basic Sword
        &PRE_DEFINED_ARMORS[1],   // Basic Armor
        &PRE_DEFINED_LEGGINGS[2], // Basic Leggings
        &PRE_DEFINED_BOOTS[2],    // Basic Boots
        NULL, 0                    // Abilities, Ability Count
    },

    // Skeleton Archer
    {
        2, "Skeleton Archer",
        40, 40,    // Health, Max Health
        25, 25,    // Mana, Max Mana
        100, 100,  // Stamina, Max Stamina
        8, 12,     // Drop Gold, Drop EXP
        6, 0,      // Attack DMG, Mob Turn
        &PRE_DEFINED_WEAPONS[0],  // Bare Hand
        &PRE_DEFINED_ARMORS[0],   // Torn Cloth
        &PRE_DEFINED_LEGGINGS[1], // Torn Cloth
        &PRE_DEFINED_BOOTS[1],    // It's a Boot?
        NULL, 0                    // Abilities, Ability Count
    },

    // Orc Brute
    {
        3, "Orc Brute",
        70, 70,    // Health, Max Health
        20, 20,    // Mana, Max Mana
        100, 100,  // Stamina, Max Stamina
        15, 20,    // Drop Gold, Drop EXP
        12, 0,     // Attack DMG, Mob Turn
        &PRE_DEFINED_WEAPONS[2],  // Iron Sword
        &PRE_DEFINED_ARMORS[2],   // Iron Armor
        &PRE_DEFINED_LEGGINGS[3], // Iron Leggings
        &PRE_DEFINED_BOOTS[3],    // Iron Boots
        NULL, 0                    // Abilities, Ability Count
    }
};

// =============================================
// ARRAY SIZE CONSTANTS DEFINITIONS (MANUAL COUNT)
// =============================================

 // Goblin Warrior, Skeleton Archer, Orc Brute