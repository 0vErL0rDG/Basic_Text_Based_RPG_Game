#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_ITEMS_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_ITEMS_H

// =============================================
//          Custom Item Type enum
// =============================================
typedef enum ItemType {
    ITEM_ARMOR,
    ITEM_WEAPON,
    ITEM_LEGGINGS,
    ITEM_BOOTS,
    ITEM_EMPTY
} ItemType;



// =============================================
//      Struct For Holding Items Details
// =============================================
typedef struct Weapon_Details {
    short ID;
    char Weapon_NAME[MAX_ITEM_NAME_LEN];
    short Weapon_DMG;
    struct Weapon_Details *next;
}weapon_details;

typedef struct Armor_Details {
    short ID;
    char Armor_NAME[MAX_ITEM_NAME_LEN];
    short Armor_Protection;
    struct Armor_Details *next;
}armor_details;

typedef struct Leggings_Details {
    short ID;
    char Leggings_NAME[MAX_ITEM_NAME_LEN];
    short Leggings_Protection;
    struct Weapon_Details *next;
}leggings_details;

typedef struct Boot_Details {
    short ID;
    char Boot_NAME[MAX_ITEM_NAME_LEN];
    short Boot_Protection;
    struct Weapon_Details *next;
}boot_details;



// ==================================================================
//      Item-List For Adding / Finding New Items ( Linked List)
// ==================================================================
typedef struct ItemList {
    ItemType type;
    union {
        armor_details armor;
        weapon_details weapon;
        leggings_details leggings;
        boot_details boot;
    } item;
    struct ItemList *next;
}itemlist;



// =============================================
//          Available For Everyone
// =============================================
extern armor_details *ARMOR_HEADER;
extern weapon_details *WEAPON_HEADER;
extern leggings_details *LEGGINGS_HEADER;
extern boot_details *BOOT_HEADER;
extern itemlist *ITEM_LIST_HEADER;



// =============================================
//      Add_Item To Indivitual Functions
// =============================================
void Add_Weapon_To_Inventory_List(weapon_details *weapon);
void Add_Armor_To_Inventory_List(armor_details *armor);
void Add_Leggings_To_Inventory_List(leggings_details *leggings);
void Add_Boot_To_Inventory_List(boot_details *boot);




// =============================================
//          Create Your Own Items
// =============================================
void Create_Armor(short ID , const char *name , short Protection);
void Create_Weapon(short ID , const char *name , short DMG);
void Create_Leggings(short ID , const char *name , short Protection);
void Create_Boot(short ID , const char *name , short Protection);



// ====================================================
//     INIT_PLAYER_INVENTORY & Other FUNCTIONS
// ====================================================
void init_game_items(void); // Load Items At The Beginning
// void init_player_inventory(ItemType item); // Will Remove Next Patch
// itemlist *Search_Item_Via_list(char *item_type , short id); // Will Implement In Future



// =============================================
//  Making Them Available For Everyone
// =============================================
extern weapon_details PRE_DEFINED_WEAPONS[];
extern armor_details PRE_DEFINED_ARMORS[];
extern leggings_details PRE_DEFINED_LEGGINGS[];
extern boot_details PRE_DEFINED_BOOTS[];



#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_ITEMS_H