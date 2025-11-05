#include "../HEADER_FILES/Header_Store.h"

// Predefined Abilities for both HUMANS and MOBS
ability_details PREDEFINED_ABILITIES[] = {
    // HUMAN Abilities (0-7)
        {HUMAN_USER, 0, "Power Strike", 10, 25, "You strike with immense power!", {2, 0}},
        {HUMAN_USER, 1, "Fire Ball", 15, 35, "You launch a fiery projectile!", {3, 0}},
        {HUMAN_USER, 2, "Heal", 20, -30, "You heal your wounds!", {4, 0}},  // Negative damage = healing
        {HUMAN_USER, 3, "Shield Bash", 5, 15, "You bash with your shield!", {1, 0}},
        {HUMAN_USER, 4, "Double Slash", 12, 40, "You strike twice in quick succession!", {3, 0}},
        {HUMAN_USER, 5, "Poison Dart", 8, 20, "You throw a poisoned dart!", {2, 0}},
        {HUMAN_USER, 6, "Lightning Bolt", 25, 50, "You summon a lightning bolt!", {5, 0}},
        {HUMAN_USER, 7, "Berserk Rage", 30, 60, "You enter a berserker rage!", {6, 0}},

        // MOB Abilities (8-15)
        {MOB_USER, 8, "Deep Bite", 15, 25, "Zombie has bitten you, you are bleeding!", {3, 0}},
        {MOB_USER, 9, "Bone Arrow", 20, 18, "Piercing arrow strikes true!", {2, 0}},
        {MOB_USER, 10, "Goblin Smash", 15, 12, "Ugg smash puny human!", {4, 0}},
        {MOB_USER, 11, "Shadow Bolt", 35, 25, "Dark energy consumes you!", {3, 0}},
        {MOB_USER, 12, "Rage Strike", 10, 30, "Orc smash! You feel bones crack!", {5, 0}},
        {MOB_USER, 13, "Venom Bite", 30, 20, "Venom courses through your veins!", {4, 0}},
        {MOB_USER, 14, "Frost Nova", 40, 22, "Freezing cold slows your movements!", {4, 0}},
        {MOB_USER, 15, "Soul Drain", 50, 40, "Your very soul is being drained!", {5, 0}}
};

// Dynamic ability system
ability_details *player_abilities = NULL;
int player_ability_count = 0;

void add_ability_to_player(short ability_id) {
    // Check if ability already exists
    for (int i = 0; i < player_ability_count; i++) {
        if (player_abilities[i].ability_id == ability_id) {
            return; // Already exists
        }
    }

    // Realloc to add new ability
    player_abilities = realloc(player_abilities, (player_ability_count + 1) * sizeof(ability_details));
    player_abilities[player_ability_count] = PREDEFINED_ABILITIES[ability_id];
    player_ability_count++;
}

ability_details* Use_Ability_In_Battle(void) {
    printf("\n--- %s Ability Menu ---\n", p->Name);

    for (int i = 0; i < player_ability_count; i++) {
        printf("%d. %s (Mana: %d, DMG: %d)\n",
               i+1,
               player_abilities[i].ability_name,
               player_abilities[i].mana_usage,
               player_abilities[i].ability_dmg);
    }

    if (player_ability_count == 0) {
        printf("No abilities available!\n");
        return NULL;
    }

    printf("Choose ability (1-%d): ", player_ability_count);
    short choice;
    scanf("%hd", &choice);

    if (choice > 0 && choice <= player_ability_count) {
        ability_details *selected = &player_abilities[choice-1];

        // Check if ability is on cooldown
        if (selected->ability_cooldown.ability_counter > 0) {
            printf("Ability on cooldown! Turns remaining: %d\n", selected->ability_cooldown.ability_counter);
            return NULL;
        }

        if (p->Mana >= selected->mana_usage) {
            p->Mana -= selected->mana_usage;
            // Put ability on cooldown
            selected->ability_cooldown.ability_counter = selected->ability_cooldown.cooldown;

            printf(" [ === %s === ] \n", selected->ability_dialogue);
            printf(".............................................\n");
            return selected;  // Return ability pointer to caller
        } else {
            printf("Not enough mana!\n");
            return NULL;
        }
    }
    return NULL;
}

void Update_Ability_Cooldowns(void) {
    for (int i = 0; i < player_ability_count; i++) {
        if (player_abilities[i].ability_cooldown.ability_counter > 0) {
            player_abilities[i].ability_cooldown.ability_counter--;
        }
    }
}


// void Use_Ability_In_Battle(void) {
//     printf("\n-------------------------------\n");
//     printf("   ---%s Ability Menu---\n   ",p->Name);
//     printf("| %s \n",p->ability[0].ability_name);
//     printf("| %s \n",p->ability[0].ability_name);
//     printf("| %s \n",p->ability[0].ability_name);
//     printf("| %s \n",p->ability[0].ability_name);
//     printf("-------------------------------\n");
// }