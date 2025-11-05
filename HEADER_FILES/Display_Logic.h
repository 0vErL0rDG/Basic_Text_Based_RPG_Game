#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_DISPLAY_LOGIC_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_DISPLAY_LOGIC_H

// #define GOOD "Healthy" // Future
// #define BAD "Critical" // Future

void Display_Player_Status(); // Display Player Stats , Health , Mana Etc
void Display_Player_Inventory_Both(); // Display Both Current & inventory List
void Display_Equipped_Items(void); // Display Current Equipped Items On Hand

void draw_bar(const char *label, int current, int max, int width); // Make Auto Update On [ Health , Mana , Stamina Etc ]
void clear_console(void); // Clear Console

void Print_Normal_Status();


#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_DISPLAY_LOGIC_H