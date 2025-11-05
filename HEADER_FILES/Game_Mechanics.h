#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_GAME_LOGIC_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_GAME_LOGIC_H
#include "Mob.h"
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif
// Battle Related Mechanics

void init_random(void);
mob_details *Random_MOB_Gen(void);

void Battle_Start();

void EXP_UPDATE(void);
ability_details* Use_Ability_In_Battle(void);
void add_ability_to_player(short ability_id);
void Update_Ability_Cooldowns(void);

#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_GAME_LOGIC_H