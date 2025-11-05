#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_BATTLE_LOGIC_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_BATTLE_LOGIC_H
#include "Mob.h"

// Mob ability functions
void mob_use_ability(mob_details *mob);
void Update_Mob_Ability_Cooldowns(mob_details *mob);

// Regeneration functions
void Auto_Regeneration_Background(void);
void Post_Battle_Regeneration(void);
void Quick_Background_Regen(void);

#endif