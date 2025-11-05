#include <ctype.h>
#include "../HEADER_FILES/Header_Store.h"

// ... your existing Player_Status function ...

int main() {
    init_game_items();
    MOB_INITIALIZE();

    while (1) {
        printf("\n");
        printf(" |----------------------------|\n");
        printf(" |------ USER INTERFACE ------|\n");
        printf(" |----------------------------|\n");
        printf(" |------- New Game (1) -------|\n");
        printf(" |  Continue / Load Game (2)  |\n");
        printf(" |----------------------------|\n");
        printf(" |----------------------------|\n");

        char Main_Options;
        scanf(" %c",&Main_Options);

        switch (Main_Options) {
            case '1':
                // Clear the input buffer before calling Player_Status
                int c;
                while ((c = getchar()) != '\n' && c != EOF);

                Player_Status();

                while (1) {
                    Quick_Background_Regen(); // Don't Remove

                    printf("\n |-----USER INTERFACE-----|\n");
                    printf(" | Player Status (1) \n");
                    printf(" | Player Inventory (2) \n");
                    printf(" | Go To Dungeon (3) \n");
                    printf(" | Go To Shop(Coming Soon) (4) \n");
                    printf(" | Save Game (5) \n");
                    printf(" | Player Devs Mode (6) \n");

                    char USER_INPUT;
                    scanf(" %c",&USER_INPUT);

                    switch (USER_INPUT) {
                        case '1' :
                            Display_Player_Status();
                            break;
                        case '2' :
                            Display_Player_Inventory_Both();
                            break;
                        case '3' :
                            Battle_Start();
                            Auto_Save();
                            break;
                        case '4' :
                            printf("Coming Soon :) \n");
                            break;
                        case '5':
                            Save_Game();
                            break;
                        case '6' :
                            printf(" | Enable Debug Mode (1)\n");
                            printf(" | Add More MOBS (2)\n");
                            printf(" | Add More Items (3)\n");
                            printf(" | Search An Item (4)\n");
                            printf(" | Cheat Mode (5) \n");
                            printf(" | Return (0)\n");

                            char Devs_mode;
                            scanf(" %c",&Devs_mode);
                            switch (Devs_mode) {
                                case '1' :
                                    enable_debug();
                                    break;
                                case '2' :
                                    Display_Current_MOBS();
                                    break;
                                case '3' :
                                    Display_Current_ITEMS();
                                    break;
                                case '4':
                                    printf("Coming Future\n");
                                    break;
                                case '5':
                                    printf("Why Are You Here Huh????\n");
                                    sleep(1);
                                    Cheat_Mode_On();
                                    break;
                                default:
                                    break;
                            }
                    }
                }
                break;
            case '2':
                // Clear the input buffer for load game as well
                while ((c = getchar()) != '\n' && c != EOF);

                Load_Game();
                // ADD THIS LOOP AFTER LOADING THE GAME
                while (1) {
                    Quick_Background_Regen(); // Don't Remove

                    printf("\n |-----USER INTERFACE-----|\n");
                    printf(" | Player Status (1) \n");
                    printf(" | Player Inventory (2) \n");
                    printf(" | Go To Dungeon (3) \n");
                    printf(" | Go To Shop(Coming Soon) (4) \n");
                    printf(" | Save Game (5) \n");
                    printf(" | Player Devs Mode (6) \n");

                    char USER_INPUT;
                    scanf(" %c",&USER_INPUT);

                    switch (USER_INPUT) {
                        case '1' :
                            Display_Player_Status();
                            break;
                        case '2' :
                            Display_Player_Inventory_Both();
                            break;
                        case '3' :
                            Battle_Start();
                            Auto_Save();
                            break;
                        case '4' :
                            printf("Coming Soon :) \n");
                            break;
                        case '5':
                            Save_Game();
                            break;
                        case '6' :
                            printf(" | Enable Debug Mode (1)\n");
                            printf(" | Add More MOBS (2)\n");
                            printf(" | Add More Items (3)\n");
                            printf(" | Search An Item (4)\n");
                            printf(" | Cheat Mode (5) \n");
                            printf(" | Return (0)\n");

                            char Devs_mode;
                            scanf(" %c",&Devs_mode);
                            switch (Devs_mode) {
                                case '1' :
                                    enable_debug();
                                    break;
                                case '2' :
                                    Display_Current_MOBS();
                                    break;
                                case '3' :
                                    Display_Current_ITEMS();
                                    break;
                                case '4':
                                    printf("Coming Future\n");
                                    break;
                                case '5':
                                    printf("Why Are You Here Huh????\n");
                                    sleep(1);
                                    Cheat_Mode_On();
                                    break;
                                default:
                                    break;
                            }
                    }
                }
                break;
        }
    }
}