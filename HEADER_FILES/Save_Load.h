//
// Created by DarkLordG on 11/5/2025.
//

#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_SAVE_LOAD_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_SAVE_LOAD_H

void Save_Player_Data(void);
void Save_Mobs_Data(void);
void Save_Items_Data(void);

void Initialize_Empty_Save_Files(void);
int Load_Mobs_Data(void);
int Load_Items_Data(void);
void Check_Save_Files(void);


// Main Functions
void Save_Game(void); // Saves everything
int Load_Game(void); // Load Everything
void Auto_Save(void); // Auto Save After Every Battle


#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_SAVE_LOAD_H