#include <ctype.h>

#include "../HEADER_FILES/Header_Store.h"


player_on_hand_inventory *inv = NULL;
player_details *p = NULL;
itemlist *s_inv = NULL;


void Player_Status(void) {

    // First Time Joining
    if (p == NULL && inv == NULL) {
            printf(R"(
               _ _ _       _                          _____  _
     ___  ___ | | | | ___ | | ___  ___  _____  ___   |  _  || | ___  _ _  ___  ___  ___  ___
    |___||___|| | | || -_|| ||  _|| . ||     || -_|  |   __|| || .'|| | || -_||  _||___||___|
              |_____||___||_||___||___||_|_|_||___|  |__|   |_||__,||_  ||___||_|
                                                                    |___|                    )");
        printf("\n   -----------------------------------------------------------------------------------------\n");



        //
        // Allocating & Error Checking Started FROM HERE--->>>
        //
        inv = malloc(sizeof(struct PLAYER_ON_HAND_INVENTORY));
        if (!inv) {
            perror("Memory Allocation For INVENTORYr Failed\n");
            exit(1);
        }
        DBG_NEW_LINE("");
        DBG_SUCCESS("Successfully Allocation For [ INVENTORY ] . File : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");
        p = malloc(sizeof(struct PLAYER_Details));
        if (!p) {
            perror("Memory Allocation For Player_DETAILS Failed\n");
            exit(1);
        }

        DBG_SUCCESS("Successfully Allocation For [ PLAYER_DETAILS ] File : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");

        s_inv = malloc(sizeof(itemlist));
        if (!s_inv) {
            perror("Memory Allocation For Player_Whole_Inventory Failed\n");
            exit(1);
        }
        DBG_SUCCESS("Successfully Allocation For [ Player_Whole_Inventory ] File : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");

        p->s_inv = malloc(MAX_INVENTORY_SIZE * sizeof(itemlist));
        if (!p->s_inv) {
            perror("Failed to allocate S_Inventory");
            exit(1);
        }
        DBG_SUCCESS("Successfully Allocation For [ S_INVENTORY ] File : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");

        p->ability = malloc(sizeof(p->ability));
        if (!p->ability) {
            perror("Failed to allocate Abilities");
            exit(1);
        }
        DBG_SUCCESS("Successfully Allocation For [ Abilities ] File : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");

        //
        // Allocating & Error Checking ENDS FROM HERE--->>>
        //



        //
        // PLAYER_DETAILS INSERT LOGIC STARTS HERE--->>>
        //


        //Asking For Player Name
        char temp_name[MAX_PLAYER_NAME];
        printf("\nPlease Enter Player Name :-");
        fgets(temp_name,sizeof(temp_name),stdin);
        temp_name[strcspn(temp_name,"\n")] = '\0';


        // Giving Default Values Of A Player As Well As Implementing Players Name
        strcpy(p->Name,temp_name);
        p->Player_Level = 1;
        p->Health = 120;
        p->MAX_Health = 120;
        p->Mana = 100;
        p->MAX_Mana = 100;
        p->Stamina = 100;
        p->MAX_Stamina = 100;
        p->GOLD = 100;
        p->EXP = 10;
        p->MAX_EXP = 100;
        p->Attack_DMG = 15;
        p->Player_Turn = 0;

        DBG_SUCCESS("Successfully Until Player_Status : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");

        //
        // PLAYER_DETAILS INSERT LOGIC ENDS HERE--->>>
        //





        //
        // SETUP INVENTORY/ONHAND ITEM & S_INVENTORY/MAIN_INVENTORY's LOGICS STARTS HERE--->>>
        //

        // Set inventory size first
        p->inventory_size = 4;
        p->s_inv[0].type = ITEM_WEAPON;
        p->s_inv[0].item.weapon.ID = PRE_DEFINED_WEAPONS[0].ID;
        snprintf(p->s_inv[0].item.weapon.Weapon_NAME, sizeof(p->s_inv[0].item.weapon.Weapon_NAME), "%s", PRE_DEFINED_WEAPONS[0].Weapon_NAME);
        p->s_inv[0].item.weapon.Weapon_DMG = PRE_DEFINED_WEAPONS[0].Weapon_DMG;

        p->s_inv[1].type = ITEM_ARMOR;
        p->s_inv[1].item.armor.ID = PRE_DEFINED_ARMORS[0].ID;
        snprintf(p->s_inv[1].item.armor.Armor_NAME, sizeof(p->s_inv[1].item.armor.Armor_NAME), "%s", PRE_DEFINED_ARMORS[0].Armor_NAME);
        p->s_inv[1].item.armor.Armor_Protection = PRE_DEFINED_ARMORS[0].Armor_Protection;

        p->s_inv[2].type = ITEM_LEGGINGS;
        p->s_inv[2].item.leggings.ID = PRE_DEFINED_LEGGINGS[0].ID; // Fixed index
        snprintf(p->s_inv[2].item.leggings.Leggings_NAME, sizeof(p->s_inv[2].item.leggings.Leggings_NAME), "%s", PRE_DEFINED_LEGGINGS[0].Leggings_NAME);
        p->s_inv[2].item.leggings.Leggings_Protection = PRE_DEFINED_LEGGINGS[0].Leggings_Protection; // Fixed index

        p->s_inv[3].type = ITEM_BOOTS;
        p->s_inv[3].item.boot.ID = PRE_DEFINED_BOOTS[0].ID; // Fixed index
        snprintf(p->s_inv[3].item.boot.Boot_NAME, sizeof(p->s_inv[3].item.boot.Boot_NAME), "%s", PRE_DEFINED_BOOTS[0].Boot_NAME);
        p->s_inv[3].item.boot.Boot_Protection = PRE_DEFINED_BOOTS[0].Boot_Protection; // Fixed index





        DBG_SUCCESS("Successfully Saved On_Hand Items : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");

        // This Is The Actual Hand / On Hand Items
        // Weapon Equipped
        snprintf(p->p_on_hand_inv.weapon.Weapon_Name , sizeof(p->p_on_hand_inv.weapon.Weapon_Name) , "%s" , PRE_DEFINED_WEAPONS[0].Weapon_NAME);
        p->p_on_hand_inv.weapon.Weapon_DMG = PRE_DEFINED_WEAPONS[0].Weapon_DMG;
        // Armor Equipped
        snprintf(p->p_on_hand_inv.armor.Armor_Name , sizeof(p->p_on_hand_inv.armor.Armor_Name) , "%s" ,  PRE_DEFINED_ARMORS[0].Armor_NAME);
        p->p_on_hand_inv.armor.Armor_Protection = PRE_DEFINED_ARMORS[0].Armor_Protection;
        // Legging Equipped
        snprintf(p->p_on_hand_inv.leggings.Leggings_Name , sizeof(p->p_on_hand_inv.leggings.Leggings_Name) , "%s" ,  PRE_DEFINED_LEGGINGS[0].Leggings_NAME);
        p->p_on_hand_inv.leggings.Leggings_Protection = PRE_DEFINED_LEGGINGS[0].Leggings_Protection;
        // Boot Equipped
        snprintf(p->p_on_hand_inv.boots.Boot_Name , sizeof(p->p_on_hand_inv.boots.Boot_Name) , "%s" ,  PRE_DEFINED_BOOTS[0].Boot_NAME);
        p->p_on_hand_inv.boots.Boot_Protection = PRE_DEFINED_BOOTS[0].Boot_Protection;


        DBG_SUCCESS("Successfully Saved Item On Inventory : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");
        DBG_NEW_LINE("");


        // Add Ability
        // p->ability->ability_holder = HUMAN_USER;
        // p->ability->ability_id = 0;
        // snprintf(p->ability->ability_name , sizeof(p->ability->ability_name) , "%s" , "Power Strike");
        // p->ability->ability_dmg = 10;
        // p->ability->mana_usage = 25;
        // p->ability->ability_cooldown = 2;
        // snprintf(p->ability->ability_dialogue, sizeof(p->ability->ability_dialogue) , "%s" , "You strike with immense power!");
        add_ability_to_player(0);


        DBG_SUCCESS("Successfully DONE PLAYER STATUS CALL : [%s] , Line (%d)",__FILE_NAME__,__LINE__);
        DBG_NEW_LINE("");
        //
        // SETUP INVENTORY/ONHAND ITEM & S_INVENTORY/MAIN_INVENTORY's LOGICS ENDS HERE--->>>
        //

        // Calling For INVENTORY VIEWER

    }


    // Old Player Logic

}

