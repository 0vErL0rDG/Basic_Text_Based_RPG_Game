#include "../HEADER_FILES/Header_Store.h"


short DEBUG_STATUS = DEBUG_MODE_OFF; // global variable

void enable_debug() {
    DEBUG_STATUS = DEBUG_MODE_ON;
    printf("DEBUG MODE ENABLED \n");
}

void disable_debug(void) {
    DEBUG_STATUS = DEBUG_MODE_OFF;
    printf("DEBUG MODE DISABLED\n");
}

void debug_status(void) {
    if (DEBUG_STATUS == DEBUG_MODE_ON)
        printf("DEBUG IS ENABLED\n");
    else
        printf("DEBUG IS DISABLED\n");
}

void Display_Current_MOBS(void) {
    MobList *current = PREDEFINED_MOBS_HEAD;  // Initialize current pointer
    short mob_counter = 0;

    printf("\n--- Available MOBS ---\n");
    while (current != NULL) {
        printf("- %s (ID: %d, Health: %d/%d)\n",
               current->mob.Name,
               current->mob.MOB_ID,
               current->mob.Health,
               current->mob.MAX_Health);
        current = current->next;
        mob_counter++;
    }
    printf("\nTotal Mobs Found: (%d)\n", mob_counter);
}

void Display_Current_ITEMS(void) {
    itemlist *current = ITEM_LIST_HEADER;  // Use correct global variable name
    short item_counter = 0;

    printf("\n--- Available ITEMS ---\n");
    while (current != NULL) {
        switch (current->type) {
            case ITEM_ARMOR:
                printf("- ARMOR: %s (Protection: %d)\n",
                       current->item.armor.Armor_NAME,
                       current->item.armor.Armor_Protection);
                break;
            case ITEM_WEAPON:
                printf("- WEAPON: %s (Damage: %d)\n",
                       current->item.weapon.Weapon_NAME,
                       current->item.weapon.Weapon_DMG);
                break;
            case ITEM_LEGGINGS:
                printf("- LEGGINGS: %s (Protection: %d)\n",
                       current->item.leggings.Leggings_NAME,
                       current->item.leggings.Leggings_Protection);
                break;
            case ITEM_BOOTS:
                printf("- BOOTS: %s (Protection: %d)\n",
                       current->item.boot.Boot_NAME,
                       current->item.boot.Boot_Protection);
                break;
            case ITEM_EMPTY:
                printf("- EMPTY SLOT\n");
                break;
        }
        current = current->next;
        item_counter++;

    }
    printf("\nTotal Items Found: (%d)\n", item_counter);
}

void Cheat_Mode_On() {

    while (1) {
        printf("\n");
        printf(" |------Cheat Menu------| \n");
        printf(" | Add 100 Gold (1)\n");
        printf(" | Add 100 Gold (2)\n");
        sleep(1);
        printf(" | ????? \n");
        printf("Return (0)\n");
        char cheat_menu;
        scanf(" %1c",&cheat_menu);
        switch (cheat_menu) {
            case '1' :
                printf("100 Gold Was Added !\n");
                p->GOLD += 100;
                break;
            case '2' :
                printf("100 EXP Was Added !\n");
                p->EXP += 100;
                break;
            case '3' :
                printf("Check Your inventory You Chea.....!!!!!!!\n");
                // Adding Cheat Weapon
                p->p_on_hand_inv.weapon.Weapon_ID == 999;
                snprintf(p->p_on_hand_inv.weapon.Weapon_Name , sizeof(p->p_on_hand_inv.weapon.Weapon_Name), "%s", "?????");
                p->p_on_hand_inv.weapon.Weapon_DMG = 999;
                // Adding Cheat Armour
                p->p_on_hand_inv.armor.Armor_ID = 999;
                snprintf(p->p_on_hand_inv.armor.Armor_Name , sizeof(p->p_on_hand_inv.armor.Armor_Name), "%s", "?????");
                p->p_on_hand_inv.armor.Armor_Protection = 999;
                // Adding Cheat leggings
                p->p_on_hand_inv.leggings.leggings_ID = 999;
                snprintf(p->p_on_hand_inv.leggings.Leggings_Name , sizeof(p->p_on_hand_inv.leggings.Leggings_Name), "%s", "?????");
                p->p_on_hand_inv.leggings.Leggings_Protection= 999;
                // Adding Cheat Boots
                p->p_on_hand_inv.boots.Boot_ID = 999;
                snprintf(p->p_on_hand_inv.boots.Boot_Name , sizeof(p->p_on_hand_inv.boots.Boot_Name), "%s", "?????");
                p->p_on_hand_inv.boots.Boot_Protection = 999;
            case '0' :
                return;
        }
    }

}
