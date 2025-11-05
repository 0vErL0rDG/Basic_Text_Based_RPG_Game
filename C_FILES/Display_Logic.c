#include "../HEADER_FILES/Header_Store.h"

void draw_bar(const char* label, int current, int max, int width) {
    int filled = (current * width) / max;
    if (filled > width) filled = width;
    if (filled < 0) filled = 0;

    printf("|  %-8s [", label);

    // Filled portion
    for (int i = 0; i < filled; i++) {
        printf("#");
    }

    // Empty portion
    for (int i = filled; i < width; i++) {
        printf(" ");
    }

    printf("] %4d/%-9d  |\n", current, max);
}

void clear_console(void) {
    for (int i = 0; i < 100; i++) {
        printf("\n");
    }
    printf("\n");
}

void Display_Player_Status(void) {
    if (p == NULL) {
        printf("Player not initialized!\n");
        return;
    }
    clear_console();
    printf("\n\n\n----------------------------------------------------\n");
    printf("                 PLAYER STATUS                    \n");
    printf("----------------------------------------------------\n");
    printf("|  Name: %-20s Level: %-12d  |\n", p->Name, 1);
    printf("|                                                  |\n");

    draw_bar("Health", p->Health, p->MAX_Health, 20);
    draw_bar("Mana", p->Mana, p->MAX_Mana, 20);
    draw_bar("Stamina", p->Stamina, p->MAX_Stamina, 20);

    printf("|                                                  |\n");
    printf("|  Gold: %-11d   Experience: %d/%-11d  |\n", p->GOLD, p->EXP, p->MAX_EXP);
    printf("|                                                  |\n");
    printf("|  Attack: %-6d      Rank: %2d (Coming Soon)      |\n", p->Attack_DMG, p->Player_Turn);
    printf("|  Armor:     %-35s  |\n", p->p_on_hand_inv.armor.Armor_Name);
    printf("|  Weapon:    %-35s  |\n", p->p_on_hand_inv.weapon.Weapon_Name);
    printf("|  Leggings:  %-35s  |\n", p->p_on_hand_inv.leggings.Leggings_Name);
    printf("|  Boots:     %-35s  |\n", p->p_on_hand_inv.boots.Boot_Name);
    printf("----------------------------------------------------\n");
    sleep(1);

}

void Display_Player_Inventory_Both(void) {

    clear_console();
    printf("\n-------------------------------------------------------\n");
    printf("                     INVENTORY                         \n");
    printf("-------------------------------------------------------\n");

    // Display Equipped Items
    Display_Equipped_Items();
    sleep(1);
    Player_Inv_Looper(p);
    sleep(2);
}

void Display_Equipped_Items(void) {
    printf("EQUIPPED ITEMS:\n");
    printf("--------------------------------------------------------\n");
    printf("| WEAPON   : %-16s ARMOR :  %-16s|\n", p->p_on_hand_inv.weapon.Weapon_Name,p->p_on_hand_inv.armor.Armor_Name);
    printf("|            Damage : %-14d   Defense : %-5d |\n", p->p_on_hand_inv.weapon.Weapon_DMG,p->p_on_hand_inv.armor.Armor_Protection);
    printf("|                                                      |\n");
    printf("| Leggings : %-16s Boots :  %-16s|\n", p->p_on_hand_inv.leggings.Leggings_Name,p->p_on_hand_inv.boots.Boot_Name);
    printf("|            Defense : %-14d  Defense : %-6d|\n", p->p_on_hand_inv.leggings.Leggings_Protection,p->p_on_hand_inv.boots.Boot_Protection);
    printf("--------------------------------------------------------\n");

    // Display Player Stats

}


// Call Current Equipped & In Inventory Items
void Player_Inv_Looper(player_details *i) {
    printf("\n-------------------------------------------------------");
    printf("\nCURRENT INVENTORY:\n");
    // Call Current Equipped & In Inventory Items
    printf("-------------------------------------------------------\n");
    if (i == NULL) return;

    DBG_SUCCESS("\n=== Player Inventory ===\n");

    int item_count = 0;

    for (int slot = 0; slot < i->inventory_size; slot++) {
        switch (i->s_inv[slot].type) {
            case ITEM_WEAPON:
                if (i->s_inv[slot].item.weapon.Weapon_NAME[0] != '\0') {
                    printf("| Weapon : %-17s  DMG     : %-13d |\n",
                           i->s_inv[slot].item.weapon.Weapon_NAME,
                           i->s_inv[slot].item.weapon.Weapon_DMG);
                    item_count++;
                }
                break;

            case ITEM_ARMOR:
                if (i->s_inv[slot].item.armor.Armor_NAME[0] != '\0') {
                    printf("| Armor  : %-17s  Defense : %-13d |\n",
                           i->s_inv[slot].item.armor.Armor_NAME,
                           i->s_inv[slot].item.armor.Armor_Protection);
                    item_count++;
                }
                break;

            case ITEM_LEGGINGS:
                if (i->s_inv[slot].item.leggings.Leggings_NAME[0] != '\0') {
                    printf("| Leggings: %-17s Defense : %-13d |\n",
                           i->s_inv[slot].item.leggings.Leggings_NAME,
                           i->s_inv[slot].item.leggings.Leggings_Protection);
                    item_count++;
                }
                break;

            case ITEM_BOOTS:
                if (i->s_inv[slot].item.boot.Boot_NAME[0] != '\0') {
                    printf("| Boots  : %-17s  Defense : %-13d |\n",
                           i->s_inv[slot].item.boot.Boot_NAME,
                           i->s_inv[slot].item.boot.Boot_Protection);
                    item_count++;
                }
                break;

            case ITEM_EMPTY:
            default:
                // Empty slot or unknown type, skip
                break;
        }
    }

    if (item_count == 0) {
        printf("| Inventory is empty.%-36s|\n", "");
    } else {
        printf("| Total items : %-38d|\n", item_count);
    }
    printf("-------------------------------------------------------\n");
}


// void Print_Normal_Status() {
//     if (p == NULL) {
//         printf("Player not initialized!\n");
//         return;
//     }
//             printf("\n--USER_DETAILS-- "
//                    "\nName : [%s]"
//                    "\nHealth : [%d]"
//                    "\nMAX_Health : [%d]"
//                    "\nMana : [%d]"
//                    "\nMAX_Mana [%d]"
//                    "\nStamina : [%d]"
//                    "\nMAX_Stamina : [%d]"
//                    "\nGold : [%d]"
//                    "\nExp : [%d]"
//                    "\nMAX_EXP : [%d]"
//                    "\nPLAYER_TURN : [%d]"
//                    "\nAttack_DMG : [%d]"
//                    "\nArmor_Name : [%s] | Armor_Protection : [%d]"
//                    "\nWeapon_Name : [%s] | Weapon_DMG : [%d] \n"
//                      ,p->Name,p->Health,p->MAX_Health,p->Mana,p->MAX_Mana,p->Stamina,p->MAX_Stamina,p->GOLD,p->EXP,p->MAX_EXP,p->Player_Turn,p->Attack_DMG
//                      ,p->player_inv.armor.Armor_Name,p->player_inv.armor.Armor_Protection
//                      ,p->player_inv.weapon.Weapon_Name,p->player_inv.weapon.Weapon_DMG);
//
// }
