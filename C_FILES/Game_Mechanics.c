#include "../HEADER_FILES/Header_Store.h"

mob_details *Random_MOB_Gen(void) {
    // Seed only ONCE at the beginning
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    short mob_count = Mob_Counter();

    if (mob_count <= 0) {
        fprintf(stderr, "No mobs available!\n");
        return NULL;
    }

    // Generate random index between 0 and mob_count-1
    short random_index = rand() % mob_count;

    // Traverse the list to the random index
    MobList *current = PREDEFINED_MOBS_HEAD;
    short current_index = 0;

    while (current != NULL && current_index < random_index) {
        current = current->next;
        current_index++;
    }

    if (current != NULL) {
        // Ensure mob has abilities initialized
        if (current->mob.abilities == NULL || current->mob.ability_count == 0) {
            // Add default basic attack ability if no abilities
            current->mob.ability_count = 1;
            current->mob.abilities = malloc(sizeof(ability_details));
            current->mob.abilities[0].ability_holder = MOB_USER;
            current->mob.abilities[0].ability_id = 0;
            snprintf(current->mob.abilities[0].ability_name, ABILITY_MAX_NAME, "Basic Attack");
            current->mob.abilities[0].mana_usage = 0;
            current->mob.abilities[0].ability_dmg = current->mob.Attack_DMG;
            snprintf(current->mob.abilities[0].ability_dialogue, ABILITY_DIALOGUE, "%s attacks you!", current->mob.Name);
            current->mob.abilities[0].ability_cooldown.cooldown = 0;
            current->mob.abilities[0].ability_cooldown.ability_counter = 0;
        }

        DBG_SUCCESS("Randomly selected mob: %s (Index: %d/%d) with %d abilities",
                   current->mob.Name, random_index, mob_count, current->mob.ability_count);
        return &(current->mob);
    }

    return NULL;
}

// Updated mob ability usage with random chance
void mob_use_ability(mob_details *mob) {
    if (mob->ability_count == 0) {
        // Fallback to basic attack
        printf("-----------------------------------------\n");
        printf("| %s attacks you for %d damage!         \n", mob->Name, mob->Attack_DMG);
        printf("-----------------------------------------\n");
        p->Health -= mob->Attack_DMG;
        sleep(1);
        return;
    }

    // 30% chance to use special ability, 70% chance for basic attack
    int use_ability = (rand() % 100) < 30;

    if (use_ability && mob->ability_count > 0) {
        // Find an ability that's not on cooldown and has enough mana
        ability_details *available_abilities[mob->ability_count];
        int available_count = 0;

        for (int i = 0; i < mob->ability_count; i++) {
            if (mob->abilities[i].ability_cooldown.ability_counter <= 0 &&
                mob->Mana >= mob->abilities[i].mana_usage) {
                available_abilities[available_count++] = &mob->abilities[i];
            }
        }

        if (available_count > 0) {
            // Use random available ability
            int ability_index = rand() % available_count;
            ability_details *ability = available_abilities[ability_index];

            mob->Mana -= ability->mana_usage;
            ability->ability_cooldown.ability_counter = ability->ability_cooldown.cooldown;

            printf("-----------------------------------------\n");
            printf("| %s uses %s!                          \n", mob->Name, ability->ability_name);
            printf("| %s                                    \n", ability->ability_dialogue);
            printf("-----------------------------------------\n");

            // Apply ability effect
            if (ability->ability_dmg < 0) {
                // Healing ability
                mob->Health -= ability->ability_dmg; // Subtract negative = add health
                if (mob->Health > mob->MAX_Health) mob->Health = mob->MAX_Health;
                printf("-----------------------------------------\n");
                printf("| %s heals for %d HP!                   \n", mob->Name, -ability->ability_dmg);
                printf("-----------------------------------------\n");
            } else {
                // Damage ability
                sleep(1);
                p->Health -= ability->ability_dmg;
                printf("-----------------------------------------\n");
                printf("| You take %d damage!                    \n", ability->ability_dmg);
                printf("-----------------------------------------\n");
            }
            return;
        }
    }

    // Use basic attack if no ability available or random chance failed
    printf("-----------------------------------------\n");
    printf("| %s attacks you for %d damage!         \n", mob->Name, mob->Attack_DMG);
    printf("-----------------------------------------\n");
    p->Health -= mob->Attack_DMG;
    sleep(1);
}

// Update mob cooldowns each turn
void Update_Mob_Ability_Cooldowns(mob_details *mob) {
    for (int i = 0; i < mob->ability_count; i++) {
        if (mob->abilities[i].ability_cooldown.ability_counter > 0) {
            mob->abilities[i].ability_cooldown.ability_counter--;
        }
    }
}

void Battle_Start() {
    clear_console();

    mob_details *random_mob = Random_MOB_Gen();
    if (random_mob != NULL) {
        p->Player_Turn = 1;
        random_mob->MOB_Turn = 0;
        printf("------------------------------------------------------------------\n");
        printf("| You encountered: %s\n", random_mob->Name);
        printf("------------------------------------------------------------------\n");
        printf("| Health  : %6d/%-6d | Mana   : %6d/%-6d\n",
               random_mob->Health, random_mob->MAX_Health, random_mob->Mana, random_mob->MAx_Mana);
        printf("| Stamina : %6d/%-6d | Attack : %-7d\n",
               random_mob->Stamina, random_mob->Max_Stamina, random_mob->Attack_DMG);
        printf("------------------------------------------------------------------\n");
        printf("|                      EQUIPPED ITEMS\n");
        printf("------------------------------------------------------------------\n");
        printf("| Weapon   : %s\n", random_mob->MOB_Weapon->Weapon_NAME);
        printf("| Armor    : %s\n", random_mob->MOB_Armor->Armor_NAME);
        printf("| Leggings : %s\n", random_mob->MOB_Leggings->Leggings_NAME);
        printf("| Boots    : %s\n", random_mob->MOB_BOOTS->Boot_NAME);
        printf("------------------------------------------------------------------\n");
        printf("\n");

        // Start battle...
        char user_input;
        printf("-----------------------------------------\n");
        printf("| Are You Gonna Fight? (Y/N)\n");
        printf("-----------------------------------------\n");
        scanf(" %1c", &user_input);

        short toggle_Player_turn = 1;
        switch (user_input) {
            case 'n':
            case 'N':
                printf("-----------------------------------------\n");
                printf("| You chose to retreat!\n");
                printf("-----------------------------------------\n");
                break;
            case 'y':
            case 'Y':
                printf("-----------------------------------------\n");
                printf("| Battle begins!\n");
                printf("-----------------------------------------\n");
                sleep(1);
                while (1) {
                    if (p->Health <= 0) {
                        printf("-----------------------------------------\n");
                        printf("| You have been defeated!\n");
                        printf("-----------------------------------------\n");
                        break;
                    }
                    if (random_mob->Health <= 0) {
                        printf("-----------------------------------------\n");
                        printf("| You defeated %s!\n", random_mob->Name);
                        printf("-----------------------------------------\n");
                        printf("-----------------------------------------\n");
                        printf("| You Gained %d Gold & %d EXP\n", random_mob->DROP_GOLD, random_mob->DROP_EXP);
                        printf("-----------------------------------------\n");
                        p->GOLD += random_mob->DROP_GOLD;
                        p->EXP += random_mob->DROP_EXP;
                        EXP_UPDATE();
                        break;
                    }
                    attack_defend:
                    if (toggle_Player_turn == 1) {
                        Update_Ability_Cooldowns();
                        // Player's turn
                        char attack_defend;
                        printf("-----------------------------------------\n");
                        printf("|            PLAYER'S TURN\n");
                        printf("-----------------------------------------\n");
                        printf("| Do you wish to Attack or Defend?\n");
                        printf("| (A) Attack  |  (D) Defend\n");
                        printf("-----------------------------------------\n");
                        scanf(" %1c", &attack_defend);

                        switch (attack_defend) {
                            case 'a':
                            case 'A': {
                                char attack_Method;
                                int ability_used = 0;

                                while (!ability_used) {
                                    printf("-----------------------------------------\n");
                                    printf("|          SELECT ATTACK METHOD\n");
                                    printf("-----------------------------------------\n");
                                    printf("| Basic Attack : %d\n", p->Attack_DMG);
                                    printf("| Use Ability --Menu--\n");
                                    printf("-----------------------------------------\n");
                                    printf("| (B) Basic Attack | (A) Ability\n");
                                    printf("-----------------------------------------\n");
                                    scanf(" %1c", &attack_Method);

                                    switch (attack_Method) {
                                        case 'b':
                                        case 'B':
                                            printf("-----------------------------------------\n");
                                            printf("| Player deals %d damage to %s!\n", p->Attack_DMG + p->p_on_hand_inv.weapon.Weapon_DMG, random_mob->Name);
                                            printf("-----------------------------------------\n");
                                            random_mob->Health -= p->Attack_DMG;
                                            ability_used = 1;
                                            sleep(1);
                                            break;

                                        case 'a':
                                        case 'A': {
                                            ability_details *selected = Use_Ability_In_Battle();
                                            clear_console();
                                            if (selected == NULL) {
                                                printf("-----------------------------------------\n");
                                                printf("| Press any key to continue to\n");
                                                printf("| attack menu...\n");
                                                printf("-----------------------------------------\n");
                                                getchar();
                                                continue;
                                            }
                                            sleep(1);
                                            printf("-----------------------------------------\n");
                                            printf("| Player deals %d damage to %s!\n", selected->ability_dmg + (p->p_on_hand_inv.weapon.Weapon_DMG / 2), random_mob->Name);
                                            printf("-----------------------------------------\n");
                                            random_mob->Health -= selected->ability_dmg;
                                            ability_used = 1;
                                            sleep(2);
                                            break;
                                        }

                                        default:
                                            printf("-----------------------------------------\n");
                                            printf("| Invalid attack method! Please\n");
                                            printf("| choose again.\n");
                                            printf("-----------------------------------------\n");
                                            break;
                                    }

                                    if (ability_used) {
                                        printf("-----------------------------------------\n");
                                        printf("| %s Status:\n", random_mob->Name);
                                        printf("-----------------------------------------\n");
                                        printf("| Health: %d/%d | Mana: %d/%d\n",
                                               random_mob->Health, random_mob->MAX_Health,
                                               random_mob->Mana, random_mob->MAx_Mana);
                                        printf("-----------------------------------------\n");
                                        sleep(1);
                                    }
                                }
                                break;
                            }
                            case 'd':
                            case 'D':
                                printf("-----------------------------------------\n");
                                printf("| You choose to defend! Damage\n");
                                printf("| reduced next turn.\n");
                                printf("-----------------------------------------\n");
                                sleep(2);

                                // Debug: Check current armor values
                                DBG_SUCCESS("- Armor Protection: %d\n", p->p_on_hand_inv.armor.Armor_Protection);
                                DBG_SUCCESS("- Leggings Protection: %d\n", p->p_on_hand_inv.leggings.Leggings_Protection);
                                DBG_SUCCESS("- Boots Protection: %d\n", p->p_on_hand_inv.boots.Boot_Protection);

                                short Player_Defense = p->p_on_hand_inv.armor.Armor_Protection +
                                                       p->p_on_hand_inv.leggings.Leggings_Protection +
                                                       p->p_on_hand_inv.boots.Boot_Protection;

                                DBG_SUCCESS("- DEBUG - Total Defense: %d\n", Player_Defense);
                                DBG_SUCCESS("- DEBUG - Mob Attack: %d\n", random_mob->Attack_DMG);

                                short calculate_dmg_taken;
                                if (Player_Defense >= random_mob->Attack_DMG) {
                                    calculate_dmg_taken = 1;
                                } else {
                                    calculate_dmg_taken = random_mob->Attack_DMG - Player_Defense;
                                }

                                // Mob's turn
                                printf("-----------------------------------------\n");
                                printf("|          %s's TURN\n", random_mob->Name);
                                printf("-----------------------------------------\n");
                                printf("| %s attacks you for %d damage!\n", random_mob->Name, calculate_dmg_taken);
                                printf("| Defense blocked %d damage!\n", random_mob->Attack_DMG - calculate_dmg_taken);
                                printf("-----------------------------------------\n");
                                p->Health -= calculate_dmg_taken;

                                sleep(2);

                                printf("-----------------------------------------\n");
                                printf("|            YOUR STATUS\n");
                                printf("-----------------------------------------\n");
                                printf("| Health : %d/%d | Mana : %d/%d\n", p->Health, p->MAX_Health, p->Mana, p->MAX_Mana);
                                printf("| Stamina: %d/%d\n", p->Stamina, p->MAX_Stamina);
                                printf("-----------------------------------------\n");
                                if (toggle_Player_turn == 1)
                                    goto attack_defend;
                        }

                        if (random_mob->Health <= 0) {
                            continue;
                        }
                        sleep(2);
                        printf("-----------------------------------------\n");
                        printf("| Switching to %s's turn...\n", random_mob->Name);
                        printf("-----------------------------------------\n");
                        sleep(2);
                        toggle_Player_turn = 0;

                    } else {
                        // Mob's turn
                        printf("-----------------------------------------\n");
                        printf("|          %s's TURN\n", random_mob->Name);
                        printf("-----------------------------------------\n");
                        Update_Mob_Ability_Cooldowns(random_mob);
                        mob_use_ability(random_mob);
                        sleep(1);

                        printf("-----------------------------------------\n");
                        printf("|            YOUR STATUS\n");
                        printf("-----------------------------------------\n");
                        printf("| Health : %d/%d | Mana : %d/%d\n", p->Health, p->MAX_Health, p->Mana, p->MAX_Mana);
                        printf("| Stamina: %d/%d\n", p->Stamina, p->MAX_Stamina);
                        printf("-----------------------------------------\n");

                        if (p->Health <= 0) {
                            printf("-----------------------------------------\n");
                            printf("| You have been defeated!\n");
                            printf("-----------------------------------------\n");
                            p->Health = p->MAX_Health;
                            p->Mana = p->MAX_Mana;
                            p->Stamina = p->MAX_Stamina;
                            break;
                        }
                        sleep(2);
                        printf("-----------------------------------------\n");
                        printf("| Switching to your turn...\n");
                        printf("-----------------------------------------\n");
                        sleep(1);
                        toggle_Player_turn = 1;
                    }
                }
                break;
        }
    } else {
        printf("-----------------------------------------\n");
        printf("| No mobs available to fight!\n");
        printf("-----------------------------------------\n");
    }
}

void EXP_UPDATE(void) {
    if (p->EXP >= p->MAX_EXP) {
        printf("-----------------------------------------\n");
        printf("| Congratulations! You Leveled Up!\n");
        printf("-----------------------------------------\n");
        p->Player_Level += 1;
        p->EXP = 0;
        p->MAX_EXP += 100;
    }
    else if (p->EXP < p->MAX_EXP) {
        printf("-----------------------------------------\n");
        printf("| Player Exp: %d / %d\n", p->EXP, p->MAX_EXP);
        printf("-----------------------------------------\n");
    }
}