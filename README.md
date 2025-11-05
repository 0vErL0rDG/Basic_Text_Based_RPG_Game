# Basic Text RPG Battle System

A comprehensive text-based RPG battle system written in C with CMake build system support. This project represents my journey into larger-scale C programming and game development.

<img width="880" height="310" alt="Main_Menu" src="https://github.com/user-attachments/assets/879954e2-d198-4b42-a0c7-ee1408ef170b" />
<img width="500" height="400" alt="Player_Details" src="https://github.com/user-attachments/assets/8ba1fdd1-1a5e-4993-8b8b-ce4ca0a496b9" />
<img width="500" height="400" alt="Inventory" src="https://github.com/user-attachments/assets/37d18eef-7832-4660-8904-2ac8bd28a21b" />

## 🎮 Features

### Core Gameplay
- **Turn-based combat** with strategic depth
- **Random enemy encounters** with 10+ unique mob types **( Can Add Mob Manually Too )**
- **Ability system** with cooldowns and mana management
- **Progression system** with leveling and EXP
- **Economy system** with gold rewards

### Equipment & Inventory
- **Weapon and armor systems** with stat bonuses
- **Multi-slot equipment** (weapon, armor, leggings, boots)
- **Inventory management** with storage capacity
- **Item creation** and customization tools

### Technical Implementation
- **Save/Load system** with auto-save functionality
- **Debug mode** with developer tools ( Need To Update For Better Usages )

# 🎯 Gameplay Overview

# Combat System

- **Turn-based battles** with tactical choices  
- **Attack/Defend mechanics** with damage calculation  
- **Special abilities** with mana costs and cooldowns  
- **Equipment bonuses** that affect combat performance  

## Character Management

- **Stat tracking:** Health, Mana, Stamina  
- **Equipment slots** with visual feedback  
- **Ability progression and management**  
- **Inventory system** with item storage  


<img width="610" height="330" alt="Dungeon" src="https://github.com/user-attachments/assets/412ac4a2-fa33-4763-83a7-84b938270dd6" />


# 🚀 Future Updates

## Planned Enhancements

### Shop System
- Item merchants with gold transactions  
- Equipment upgrades and enhancements  
- Consumable items (potions, scrolls)  
- Dynamic pricing based on player level  

### Enhanced GUI
- Color-coded interfaces for better readability  
- Interactive menus with mouse support  
- Real-time stat displays during combat  
- Customizable UI themes  

### Gameplay Expansions
- Quest system with objectives and rewards  
- Crafting system for item creation  
- Multi-level dungeons with boss encounters  
- Character classes with unique abilities  

### Technical Improvements
- Optimized save system with compression  
- Extended modding support for custom content  
- Performance enhancements for larger battles  
- Extended platform support
```bash

C_FILES/           HEADER_FILES/
├── main.c         ├── Header_Store.h
├── Game_Mechanics.c ├── User_Information.h
├── user_info.c    ├── Items_Properties.h
├── Item_Properties.c ├── Mob.h
├── MOB_LOGIC.c    ├── Game_Mechanics.h
├── Devs_kits.c    ├── Display_Logic.h
├── Display_Logic.c ├── Devs_kit.h
├── ability.c      ├── Battle_Mechanics.h
├── Save_Load.c    ├── Save_Load.h
└── Battle_Mechanics.c └── Predefined_Values.h
```

# 🎓 About the Developer

This project represents my second GitHub repository and first large-scale C programming endeavor. As someone new to C programming, I'm continuously learning and improving my skills day by day.

## Learning Journey
- First major project in C language  
- Trying to clean architecture and modular design  
- Practical application of data structures and memory management  
- Continuous improvement through feedback and refactoring  

## Goals
- Master C programming for system-level development  
- Build foundation for a game development career  
- Learn software architecture and design patterns  
- Contribute to open-source gaming projects  

## 💡 Contributing
While this is primarily a learning project, suggestions and feedback are always welcome! I'm particularly interested in:  
- Code optimization tips  
- Memory management best practices  
- Game design improvements  
- User experience enhancements  

## 📄 License
**MIT License** - feel free to learn from and build upon this code.

#### Disclaimer : Even Tho I Tried To Make It On My own I Indeed Took Help From DeepSeek (AI) , But For Logics , ERROR & Format Files / This .md File...
