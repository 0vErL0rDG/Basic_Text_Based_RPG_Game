#include "../HEADER_FILES/Header_Store.h"

// Defining All Three To NULL
armor_details *ARMOR_HEADER = NULL;
weapon_details *WEAPON_HEADER = NULL;
leggings_details *LEGGINGS_HEADER = NULL;
boot_details *BOOT_HEADER = NULL;
itemlist *ITEM_LIST_HEADER = NULL;


// Create CUSTOM [ WEAPON , ARMOR , LEGGINGS ,BOOT ]
    // CUSTOM WEAPON CREATION
void Create_Weapon(const short ID , const char *name , const short DMG){

    weapon_details *new_node = malloc(sizeof(weapon_details));
    if (!new_node) {
        fprintf(stderr,"Error At Armor Creation | File [%s] , Line (%d)",__FILE_NAME__ , __LINE__);
        return;
    }

    if (strlen(name) >= CUSTOM_ITEM_NAME_LEN ) {
        fprintf(stderr,"Weapon Name Length (%llu) Max Limit (%d)",strlen(name),CUSTOM_ITEM_NAME_LEN);
        exit(1);
    }
    snprintf(new_node->Weapon_NAME,sizeof(new_node->Weapon_NAME),"%s",name);

    new_node->Weapon_NAME[MAX_ITEM_NAME_LEN - 1] = '\0';
    new_node->ID = ID;
    new_node->Weapon_DMG = DMG;
    new_node->next = WEAPON_HEADER;  // Point to current head
    Add_Weapon_To_Inventory_List(new_node);
    WEAPON_HEADER = new_node;

}


    // CUSTOM ARMOR CREATION
void Create_Armor(const short ID , const char *name , const short Protection) {
    armor_details *new_node = malloc(sizeof(armor_details));
    if (!new_node) {
        fprintf(stderr,"Error At Armor Creation | File [%s] , Line (%d)",__FILE_NAME__ , __LINE__);
        return;
    }

    if (strlen(name) >= CUSTOM_ITEM_NAME_LEN ) {
        fprintf(stderr,"Armor Name Length (%llu) Max Limit (%d)",strlen(name),CUSTOM_ITEM_NAME_LEN);
        free(new_node);
        return;
    }

    snprintf(new_node->Armor_NAME,sizeof(new_node->Armor_NAME),"%s",name);
    new_node->Armor_NAME[MAX_ITEM_NAME_LEN - 1] = '\0';
    new_node->ID = ID;
    new_node->Armor_Protection = Protection;
    new_node->next = ARMOR_HEADER;  // Point to current head
    Add_Armor_To_Inventory_List(new_node);
    ARMOR_HEADER = new_node;

}

    // CUSTOM LEGGINGS CREATIONS
void Create_Leggings(const short ID , const char *name , const short Protection) {
    armor_details *new_node = malloc(sizeof(armor_details));
    if (!new_node) {
        fprintf(stderr,"Error At Leggings Creation | File [%s] , Line (%d)",__FILE_NAME__ , __LINE__);
        return;
    }

    if (strlen(name) >= CUSTOM_ITEM_NAME_LEN ) {
        fprintf(stderr,"Leggings Name Length (%llu) Max Limit (%d)",strlen(name),CUSTOM_ITEM_NAME_LEN);
        free(new_node);
        return;
    }

    snprintf(new_node->Armor_NAME,sizeof(new_node->Armor_NAME),"%s",name);
    new_node->Armor_NAME[MAX_ITEM_NAME_LEN - 1] = '\0';
    new_node->ID = ID;
    new_node->Armor_Protection = Protection;
    new_node->next = ARMOR_HEADER;  // Point to current head
    Add_Armor_To_Inventory_List(new_node);
    ARMOR_HEADER = new_node;

}

    // CUSTOM BOOTS CREATIONS
void Create_Boots(const short ID , const char *name , const short Protection) {
    armor_details *new_node = malloc(sizeof(armor_details));
    if (!new_node) {
        fprintf(stderr,"Error At Boots Creation | File [%s] , Line (%d)",__FILE_NAME__ , __LINE__);
        return;
    }

    if (strlen(name) >= CUSTOM_ITEM_NAME_LEN ) {
        fprintf(stderr,"Boots Name Length (%llu) Max Limit (%d)",strlen(name),CUSTOM_ITEM_NAME_LEN);
        free(new_node);
        return;
    }

    snprintf(new_node->Armor_NAME,sizeof(new_node->Armor_NAME),"%s",name);
    new_node->Armor_NAME[MAX_ITEM_NAME_LEN - 1] = '\0';
    new_node->ID = ID;
    new_node->Armor_Protection = Protection;
    new_node->next = ARMOR_HEADER;  // Point to current head
    Add_Armor_To_Inventory_List(new_node);
    ARMOR_HEADER = new_node;

}



// Armor & Weapons Are Made Here

// Basic Armor & Weapon Defined
// armor_details basic_armor(void) {
//     armor_details armor;
//     armor.ID = 1;
//     snprintf(armor.Armor_NAME,MAX_ITEM_NAME_LEN,"Basic Armor");
//     armor.Armor_Protection = 5;
//     return armor;
// }
//
// weapon_details basic_weapon(void) {
//     weapon_details weapon;
//     weapon.ID = 1;
//     snprintf(weapon.Weapon_NAME,MAX_ITEM_NAME_LEN,"Basic Weapon");
//     weapon.Weapon_DMG = 5;
//     return weapon;
// }

// Predefined Items
weapon_details PRE_DEFINED_WEAPONS[] = {
    // Define Weapons
    {0,"Bare Hand",3},
    {1,"Basic Sword",5},
    {2,"Iron Sword",14},
    {3,"Dragon Blade",45},
};

armor_details PRE_DEFINED_ARMORS[] = {
    // Define Weapons
    {1,"Torn Cloth",1},
    {1,"Basic Armor",5},
    {2,"Iron Armor",8},
    {3,"Dragon Scale",14},

};

leggings_details PRE_DEFINED_LEGGINGS[] = {
    // Define Weapons
    {0,"Underwear",0},
    {1,"Torn Cloth",1},
    {2,"Basic Leggings",3},
    {3,"Iron Leggings",5},
    {4,"Dragon Blade",30},

};

boot_details PRE_DEFINED_BOOTS[] = {
    // Define Weapons
    {0,"Grass Shoe",0},
    {1,"It's a Boot?",1},
    {2,"Basic Boots",2},
    {3,"Iron Boots",4},
    {4,"Dragon Boots",24},

};




void init_game_items(void) {

    for (int i = 0; i < sizeof(PRE_DEFINED_WEAPONS) / sizeof(PRE_DEFINED_WEAPONS[0]); i++) {
        Create_Weapon(
            PRE_DEFINED_WEAPONS[i].ID,
            PRE_DEFINED_WEAPONS[i].Weapon_NAME,
            PRE_DEFINED_WEAPONS[i].Weapon_DMG
        );
        DBG_WEAPONS("Weapon Added: %s | (DMG: %d)\n",  PRE_DEFINED_WEAPONS[i].Weapon_NAME, PRE_DEFINED_WEAPONS[i].Weapon_DMG);

    }
    DBG_NEW_LINE("");
    for (int i = 0; i < sizeof(PRE_DEFINED_WEAPONS) / sizeof(PRE_DEFINED_WEAPONS[0]); i++) {
        Create_Armor(
            PRE_DEFINED_ARMORS[i].ID,
            PRE_DEFINED_ARMORS[i].Armor_NAME,
            PRE_DEFINED_ARMORS[i].Armor_Protection
        );
        DBG_ARMORS("Armor Added: %s (Protection: %d)\n", PRE_DEFINED_ARMORS[i].Armor_NAME, PRE_DEFINED_ARMORS[i].Armor_Protection);

    }
    DBG_NEW_LINE("");

    for (int i = 0; i < sizeof(PRE_DEFINED_LEGGINGS) / sizeof(PRE_DEFINED_LEGGINGS[0]); i++) {
        Create_Leggings(
            PRE_DEFINED_LEGGINGS[i].ID,
            PRE_DEFINED_LEGGINGS[i].Leggings_NAME,
            PRE_DEFINED_LEGGINGS[i].Leggings_Protection
        );
        DBG_WEAPONS("Leggings Added: %s | (DMG: %d)\n",  PRE_DEFINED_LEGGINGS[i].Leggings_NAME, PRE_DEFINED_LEGGINGS[i].Leggings_Protection);

    }
    DBG_NEW_LINE("");
    for (int i = 0; i < sizeof(PRE_DEFINED_BOOTS) / sizeof(PRE_DEFINED_BOOTS[0]); i++) {
        Create_Armor(
            PRE_DEFINED_BOOTS[i].ID,
            PRE_DEFINED_BOOTS[i].Boot_NAME,
            PRE_DEFINED_BOOTS[i].Boot_Protection
        );
        DBG_ARMORS("Boots Added: %s (Protection: %d)\n", PRE_DEFINED_BOOTS[i].Boot_NAME, PRE_DEFINED_BOOTS[i].Boot_Protection);

    }
    DBG_NEW_LINE("");
}

void Add_Weapon_To_Inventory_List(weapon_details *weapon) {

    itemlist *new_node = malloc(sizeof(itemlist));
    if (!new_node) return;

    new_node->type = ITEM_WEAPON;
    new_node->item.weapon = *weapon;
    new_node->next = ITEM_LIST_HEADER;
    ITEM_LIST_HEADER = new_node;
}

void Add_Armor_To_Inventory_List(armor_details *armor) {

    itemlist *new_node = malloc(sizeof(itemlist));
    if (!new_node) return;

    new_node->type = ITEM_ARMOR;
    new_node->item.armor = *armor;
    new_node->next = ITEM_LIST_HEADER;
    ITEM_LIST_HEADER = new_node;
}
void Add_Leggings_To_Inventory_List(leggings_details *leggings) {

    itemlist *new_node = malloc(sizeof(itemlist));
    if (!new_node) return;

    new_node->type = ITEM_LEGGINGS;
    new_node->item.leggings = *leggings;
    new_node->next = ITEM_LIST_HEADER;
    ITEM_LIST_HEADER = new_node;
}
void Add_Boots_To_Inventory_List(boot_details *boot) {

    itemlist *new_node = malloc(sizeof(itemlist));
    if (!new_node) return;

new_node->type = ITEM_BOOTS;
    new_node->item.boot = *boot;
    new_node->next = ITEM_LIST_HEADER;
    ITEM_LIST_HEADER = new_node;
}

// =============================================
// =============================================
//              FUTURE UPDATE
// =============================================
// =============================================

//
// void init_player_inventory(ItemType item) {
//
//     int i = 0;
//     while (i < MAX_INVENTORY_SIZE) {
//         if (item == ITEM_ARMOR) {
//             if (!p->s_inv[i].item.armor.ID)
//             printf("%s(%d)\n",p->s_inv[i].item.armor.Armor_NAME,p->s_inv[i].item.armor.Armor_Protection);
//         }
//         if (item == ITEM_WEAPON) {
//             if (!p->s_inv[i].item.weapon.ID)
//             printf("%s(%d)\n",p->s_inv[i].item.weapon.Weapon_NAME,p->s_inv[i].item.weapon.Weapon_DMG);
//         }
//         if (item == ITEM_LEGGINGS) {
//             if (!p->s_inv[i].item.leggings.ID)
//                 printf("%s(%d)\n",p->s_inv[i].item.leggings.Leggings_NAME,p->s_inv[i].item.leggings.Leggings_Protection);
//         }
//         if (item == ITEM_BOOTS) {
//             if (!p->s_inv[i].item.boot.ID)
//                 printf("%s(%d)\n",p->s_inv[i].item.boot.Boot_NAME,p->s_inv[i].item.boot.Boot_Protection);
//         }
//
//         i++;
//     }
// }


// itemlist *Search_Item_Via_list(char *item_type, short id) {
//
//     itemlist *current = ITEM_LIST_HEADER;
//
//     char temp_name_holder[MAX_ITEM_NAME_LEN];
//     snprintf(temp_name_holder, sizeof(temp_name_holder), "%s", item_type);
//
//     for (int i = 0; i < strlen(temp_name_holder); i++) {
//         temp_name_holder[i] = tolower(temp_name_holder[i]);
//     }
//
//     if (strcmp(temp_name_holder, "weapon") == 0) {
//         weapon_details *wd = WEAPON_HEADER;  // Initialize wd pointer - THIS WAS MISSING!
//         while (wd != NULL) {
//             if (wd->ID == id) {
//                 if (current == NULL) {
//                     current = malloc(sizeof(itemlist));
//                 }
//                 current->item.weapon.ID = wd->ID;
//                 snprintf(current->item.weapon.Weapon_NAME, sizeof(current->item.weapon.Weapon_NAME), "%s", wd->Weapon_NAME);
//                 return current;
//             }
//             wd = wd->next;
//         }
//     }
//     else if (strcmp(temp_name_holder, "armor") == 0) {
//         armor_details *ad = ARMOR_HEADER;
//         while (ad != NULL) {
//             if (ad->ID == id) {
//                 if (current == NULL) {
//                     current = malloc(sizeof(itemlist));
//                 }
//                 current->item.armor.ID = ad->ID;
//                 snprintf(current->item.armor.Armor_NAME, sizeof(current->item.armor.Armor_NAME), "%s", ad->Armor_NAME);
//                 return current;
//             }
//             ad = ad->next;
//         }
//     }
//     else if (strcmp(temp_name_holder, "leggings") == 0) {
//         leggings_details *ld = LEGGINGS_HEADER;
//         while (ld != NULL) {
//             if (ld->ID == id) {
//                 if (current == NULL) {
//                     current = malloc(sizeof(itemlist));
//                 }
//                 current->item.leggings.ID = ld->ID;
//                 snprintf(current->item.leggings.Leggings_NAME, sizeof(current->item.leggings.Leggings_NAME), "%s", ld->Leggings_NAME);
//                 return current;
//             }
//             ld = ld->next;
//         }
//     }
//     else if (strcmp(temp_name_holder, "boots") == 0) {
//         boot_details *bd = BOOT_HEADER;
//         while (bd != NULL) {
//             if (bd->ID == id) {
//                 if (current == NULL) {
//                     current = malloc(sizeof(itemlist));
//                 }
//                 current->item.armor.ID = bd->ID;
//                 snprintf(current->item.boot.Boot_NAME, sizeof(current->item.boot.Boot_NAME), "%s", bd->Boot_NAME);
//                 return current;
//             }
//             bd = bd->next;
//         }
//     }
//
//     printf("Item Doesn't Exist!\n");
//     DBG_PROBLEM("Function [Search_Item_LIST] In %s line(%d)",__FILE_NAME__,__LINE__);
//     DBG_NEW_LINE("");
//     return NULL;
// }