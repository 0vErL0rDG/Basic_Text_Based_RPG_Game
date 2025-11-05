#ifndef BASIC_TEXT_RPG_BATTLE_SYSTEM_DEVS_KIT_H
#define BASIC_TEXT_RPG_BATTLE_SYSTEM_DEVS_KIT_H

#define DEBUG_MODE_ON 1
#define DEBUG_MODE_OFF 0


extern short DEBUG_STATUS;

void enable_debug();
void disable_debug(void);


// CUSTOM DEBUG COMMANDS

#define DBG_NEW_LINE(...) \
    do{ \
if (DEBUG_STATUS == DEBUG_MODE_ON){ \
        printf("\n"); \
        printf(__VA_ARGS__); \
    } \
}while (0)

#define DBG_ARMORS(...) \
    do { \
        if (DEBUG_STATUS == DEBUG_MODE_ON) { \
            printf("[DEBUG Armor Section] "); \
            printf(__VA_ARGS__); \
        } \
    }while (0)

#define DBG_WEAPONS(...) \
    do { \
        if (DEBUG_STATUS == DEBUG_MODE_ON) {\
            printf("[DEBUG Weapon Section] "); \
            printf(__VA_ARGS__); \
        }\
    }while (0)


// DEBUG MACRO FOR MOBS

#define DBG_MOBS(...) \
    do { \
        if (DEBUG_STATUS == DEBUG_MODE_ON) { \
            printf("[DEBUG Mob Section] "); \
            printf(__VA_ARGS__); \
        } \
    }while (0)

#define DBG_MOBS_INIT(...) \
do { \
if (DEBUG_STATUS == DEBUG_MODE_ON) { \
printf("[DEBUG Mob Section] "); \
printf(__VA_ARGS__); \
} \
}while (0)

// Something Wrong For Any Function
#define DBG_PROBLEM(...) \
    do { \
        if(DEBUG_STATUS == DEBUG_MODE_ON){ \
           printf("[DEBUG MODE] Problem At -> "); \
           printf(__VA_ARGS__); \
        } \
}while(0)

#define DBG_SUCCESS(...) \
    do { \
        if (DEBUG_STATUS == DEBUG_MODE_ON) { \
            printf("[Success] "); \
            printf(__VA_ARGS__); \
        } \
} while (0)


void Display_Current_MOBS(void);
void Display_Current_ITEMS(void);
void Cheat_Mode_On(void);

#endif //BASIC_TEXT_RPG_BATTLE_SYSTEM_DEVS_KIT_H