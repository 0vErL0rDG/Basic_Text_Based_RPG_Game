cmake_minimum_required(VERSION 4.0)
project(Basic_Text_RPG_Battle_System)

set(CMAKE_CXX_STANDARD 26)

# Include header directories
include_directories(HEADER_FILES)

add_executable(Basic_Text_RPG_Battle_System
        C_FILES/main.c
        C_FILES/Game_Mechanics.c
        C_FILES/user_info.c
        C_FILES/Item_Properties.c
        C_FILES/MOB_LOGIC.c
        C_FILES/Devs_kits.c
        C_FILES/Display_Logic.c
        C_FILES/ability.c
        C_FILES/Save_Load.c
        C_FILES/Battle_Mechanics.c
)