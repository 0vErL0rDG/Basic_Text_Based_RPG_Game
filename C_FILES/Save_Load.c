#include "../HEADER_FILES/Header_Store.h"
#include <sys/stat.h>  // For directory creation

// Add these extern declarations at the top
extern player_details *p;
extern int player_ability_count;
extern ability_details *player_abilities;
extern MobList *PREDEFINED_MOBS_HEAD;

// Save player data to separate file - ALWAYS creates file
void Save_Player_Data(void) {
    const char* filepath = "player_data.dat";

    FILE *file = fopen(filepath, "wb");
    if (!file) {
        printf("Error: Cannot create player save file at %s!\n", filepath);
        perror("fopen failed");
        return;
    }

    printf("Saving player data...\n");

    // If no player data, create empty file and return
    if (p == NULL) {
        printf("No player data to save, creating empty file.\n");
        fclose(file);
        return;
    }

    // Save player basic stats
    size_t written = fwrite(p, sizeof(player_details), 1, file);
    if (written != 1) {
        printf("Error writing player stats!\n");
    }

    // Save equipped items
    written = fwrite(&p->p_on_hand_inv, sizeof(player_on_hand_inventory), 1, file);
    if (written != 1) {
        printf("Error writing player inventory!\n");
    }

    // Save player abilities
    written = fwrite(&player_ability_count, sizeof(int), 1, file);
    if (written != 1) {
        printf("Error writing ability count!\n");
    }

    if (player_ability_count > 0 && player_abilities != NULL) {
        written = fwrite(player_abilities, sizeof(ability_details), player_ability_count, file);
        if (written != player_ability_count) {
            printf("Error writing abilities!\n");
        }
    }

    fclose(file);
    DBG_SUCCESS("Player data saved successfully to %s!\n", filepath);
}

// Save mobs data to separate file - ALWAYS creates file
void Save_Mobs_Data(void) {
    const char* filepath = "mobs_data.dat";

    FILE *file = fopen(filepath, "wb");
    if (!file) {
        printf("Error: Cannot create mobs save file at %s!\n", filepath);
        perror("fopen failed");
        return;
    }

    // Save mob count first (even if 0)
    short mob_count = 0;

    // Only count mobs if the list exists and has mobs
    if (PREDEFINED_MOBS_HEAD != NULL) {
        mob_count = Mob_Counter();
    }

    printf("Saving %d mobs...\n", mob_count);

    size_t written = fwrite(&mob_count, sizeof(short), 1, file);
    if (written != 1) {
        printf("Error writing mob count!\n");
    }

    // Save each mob if they exist
    if (mob_count > 0 && PREDEFINED_MOBS_HEAD != NULL) {
        MobList *current = PREDEFINED_MOBS_HEAD;
        int mobs_saved = 0;
        while (current != NULL && mobs_saved < mob_count) {
            // Don't save pointers - they're invalid on reload
            mob_details mob_to_save = current->mob;
            // Clear pointers before saving
            mob_to_save.MOB_Weapon = NULL;
            mob_to_save.MOB_Armor = NULL;
            mob_to_save.MOB_Leggings = NULL;
            mob_to_save.MOB_BOOTS = NULL;
            mob_to_save.abilities = NULL;

            written = fwrite(&mob_to_save, sizeof(mob_details), 1, file);
            if (written != 1) {
                printf("Error writing mob: %s\n", current->mob.Name);
            } else {
                mobs_saved++;
            }
            current = current->next;
        }
        printf("Mobs data saved successfully to %s! (%d/%d mobs)\n", filepath, mobs_saved, mob_count);
    } else {
        printf("Mobs data saved successfully to %s! (0 mobs - empty file)\n", filepath);
    }

    fclose(file);
}

// Save items data to separate file - ALWAYS creates file
void Save_Items_Data(void) {
    const char* filepath = "items_data.dat";

    FILE *file = fopen(filepath, "wb");
    if (!file) {
        printf("Error: Cannot create items save file at %s!\n", filepath);
        perror("fopen failed");
        return;
    }

    printf("Saving items data...\n");

    // Always write inventory size (even if 0)
    int inventory_size = 0;

    // Get actual inventory size if player exists and has inventory
    if (p != NULL && p->s_inv != NULL) {
        inventory_size = p->inventory_size;
    }

    printf("Saving %d items...\n", inventory_size);

    // Save inventory size (this is what the load function expects first)
    size_t written = fwrite(&inventory_size, sizeof(int), 1, file);
    if (written != 1) {
        printf("Error writing inventory size!\n");
    }

    // Save inventory items if they exist
    if (inventory_size > 0 && p != NULL && p->s_inv != NULL) {
        // Save each item individually to avoid pointer issues
        for (int i = 0; i < inventory_size; i++) {
            written = fwrite(&p->s_inv[i], sizeof(itemlist), 1, file);
            if (written != 1) {
                printf("Error writing item %d! Wrote %zu/1\n", i, written);
                break;
            }
        }
        printf("Items data saved successfully to %s! (%d items)\n", filepath, inventory_size);
    } else {
        printf("Items data saved successfully to %s! (0 items - empty file)\n", filepath);
    }

    fclose(file);
}

// Load player data from file - handles empty files gracefully
int Load_Player_Data(void) {
    const char* filepath = "player_data.dat";

    FILE *file = fopen(filepath, "rb");
    if (!file) {
        printf("No player save file found at %s!\n", filepath);
        return 0;
    }

    // Check if file is empty
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_size == 0) {
        printf("Player save file is empty at %s!\n", filepath);
        fclose(file);
        return 0;
    }

    printf("Loading player data from %s...\n", filepath);

    // Allocate player if needed
    if (p == NULL) {
        p = malloc(sizeof(player_details));
        if (!p) {
            printf("Memory allocation failed for player!\n");
            fclose(file);
            return 0;
        }
    }

    // Load player basic stats
    size_t read = fread(p, sizeof(player_details), 1, file);
    if (read != 1) {
        printf("Error reading player stats!\n");
        fclose(file);
        return 0;
    }

    // Load equipped items
    read = fread(&p->p_on_hand_inv, sizeof(player_on_hand_inventory), 1, file);
    if (read != 1) {
        printf("Error reading player inventory!\n");
        fclose(file);
        return 0;
    }

    // Load player abilities
    read = fread(&player_ability_count, sizeof(int), 1, file);
    if (read != 1) {
        printf("Error reading ability count!\n");
        fclose(file);
        return 0;
    }

    // Clear any existing abilities
    if (player_abilities != NULL) {
        free(player_abilities);
        player_abilities = NULL;
    }

    if (player_ability_count > 0) {
        player_abilities = malloc(player_ability_count * sizeof(ability_details));
        if (!player_abilities) {
            printf("Memory allocation failed for abilities!\n");
            fclose(file);
            return 0;
        }

        read = fread(player_abilities, sizeof(ability_details), player_ability_count, file);
        if (read != player_ability_count) {
            printf("Error reading abilities! Read %zu/%d\n", read, player_ability_count);
            free(player_abilities);
            player_abilities = NULL;
            player_ability_count = 0;
            fclose(file);
            return 0;
        }
    } else {
        player_abilities = NULL;
    }

    // Initialize pointers that weren't saved
    p->ability = NULL; // This needs to be set up separately
    p->s_inv = NULL; // This will be loaded by Load_Items_Data

    fclose(file);
    printf("Player data loaded successfully! Abilities: %d\n", player_ability_count);
    return 1;
}

// Load mobs data from file - handles empty files gracefully
int Load_Mobs_Data(void) {
    const char* filepath = "mobs_data.dat";

    FILE *file = fopen(filepath, "rb");
    if (!file) {
        printf("No mobs save file found at %s!\n", filepath);
        return 0;
    }

    // Check if file is empty
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_size == 0) {
        printf("Mobs save file is empty at %s!\n", filepath);
        fclose(file);
        return 0;
    }

    printf("Loading mobs data from %s...\n", filepath);

    // Load mob count
    short mob_count;
    size_t read = fread(&mob_count, sizeof(short), 1, file);
    if (read != 1) {
        printf("Error reading mob count!\n");
        fclose(file);
        return 0;
    }

    printf("Loading %d mobs...\n", mob_count);

    // Load each mob and update the linked list
    if (mob_count > 0 && PREDEFINED_MOBS_HEAD != NULL) {
        MobList *current = PREDEFINED_MOBS_HEAD;
        int mobs_loaded = 0;

        for (int i = 0; i < mob_count && current != NULL; i++) {
            mob_details loaded_mob;
            read = fread(&loaded_mob, sizeof(mob_details), 1, file);
            if (read != 1) {
                printf("Error reading mob %d!\n", i);
            } else {
                // Copy the data but preserve the pointers (they need to be set up separately)
                current->mob.MOB_ID = loaded_mob.MOB_ID;
                strcpy(current->mob.Name, loaded_mob.Name);
                current->mob.Health = loaded_mob.Health;
                current->mob.MAX_Health = loaded_mob.MAX_Health;
                current->mob.Mana = loaded_mob.Mana;
                current->mob.MAx_Mana = loaded_mob.MAx_Mana;
                current->mob.Stamina = loaded_mob.Stamina;
                current->mob.Max_Stamina = loaded_mob.Max_Stamina;
                current->mob.DROP_GOLD = loaded_mob.DROP_GOLD;
                current->mob.DROP_EXP = loaded_mob.DROP_EXP;
                current->mob.Attack_DMG = loaded_mob.Attack_DMG;
                current->mob.MOB_Turn = loaded_mob.MOB_Turn;
                // Note: Pointers (MOB_Weapon, MOB_Armor, etc.) need to be reinitialized separately

                mobs_loaded++;
            }
            current = current->next;
        }
        printf("Mobs data loaded successfully! (%d/%d mobs)\n", mobs_loaded, mob_count);
    } else {
        printf("Mobs data loaded successfully! (0 mobs - empty file)\n");
    }

    fclose(file);
    return 1;
}

// Load items data from file - handles empty files gracefully
int Load_Items_Data(void) {
    const char* filepath = "items_data.dat";

    FILE *file = fopen(filepath, "rb");
    if (!file) {
        printf("No items save file found at %s!\n", filepath);
        return 0;
    }

    // Check if file is empty
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_size == 0) {
        printf("Items save file is empty at %s!\n", filepath);
        fclose(file);
        return 0;
    }

    printf("Loading items data from %s...\n", filepath);

    if (p == NULL) {
        printf("Error: No player to load items for!\n");
        fclose(file);
        return 0;
    }

    // Load inventory size
    int inventory_size;
    size_t read = fread(&inventory_size, sizeof(int), 1, file);
    if (read != 1) {
        printf("Error reading inventory size!\n");
        fclose(file);
        return 0;
    }

    p->inventory_size = inventory_size;
    printf("Loading %d items...\n", p->inventory_size);

    // Load inventory items
    if (p->inventory_size > 0) {
        // Free existing inventory if it exists
        if (p->s_inv != NULL) {
            free(p->s_inv);
        }

        // Allocate new inventory
        p->s_inv = malloc(p->inventory_size * sizeof(itemlist));
        if (!p->s_inv) {
            printf("Memory allocation failed for inventory!\n");
            p->inventory_size = 0;
            fclose(file);
            return 0;
        }

        // Load each item individually
        int items_loaded = 0;
        for (int i = 0; i < p->inventory_size; i++) {
            read = fread(&p->s_inv[i], sizeof(itemlist), 1, file);
            if (read != 1) {
                printf("Error reading item %d! Read %zu/1\n", i, read);
                break;
            }
            items_loaded++;
        }

        if (items_loaded != p->inventory_size) {
            printf("Warning: Loaded %d/%d items\n", items_loaded, p->inventory_size);
            p->inventory_size = items_loaded; // Adjust to actual loaded count
        }

        printf("Items data loaded successfully! (%d items)\n", items_loaded);
    } else {
        // No items, ensure inventory is NULL
        if (p->s_inv != NULL) {
            free(p->s_inv);
            p->s_inv = NULL;
        }
        printf("Items data loaded successfully! (0 items - empty file)\n");
    }

    fclose(file);
    return 1;
}

// Debug function to check if files exist
void Check_Save_Files(void) {
    printf("\n=== Checking Save Files ===\n");

    struct stat st = {0};
    const char* files[] = {"player_data.dat", "mobs_data.dat", "items_data.dat"};

    for (int i = 0; i < 3; i++) {
        if (stat(files[i], &st) == 0) {
            printf("✓ %s exists (%ld bytes)\n", files[i], st.st_size);
        } else {
            printf("✗ %s does not exist\n", files[i]);
        }
    }
}

// Main save function - saves everything
void Save_Game(void) {
    printf("\n=== Saving Game ===\n");
    Save_Player_Data();
    Save_Mobs_Data();
    Save_Items_Data();
    Check_Save_Files(); // Debug: show what files were created
    printf("=== Game Saved Successfully ===\n");
}

// Main load function - loads everything
int Load_Game(void) {
    printf("\n=== Loading Game ===\n");

    int success = 1;

    // Load in specific order to handle dependencies
    if (!Load_Player_Data()) {
        printf("Failed to load player data!\n");
        success = 0;
    }
    if (!Load_Mobs_Data()) {
        printf("Failed to load mobs data!\n");
        success = 0;
    }
    if (!Load_Items_Data()) {
        printf("Failed to load items data!\n");
        success = 0;
    }

    if (success) {
        printf("=== Game Loaded Successfully ===\n");
    } else {
        printf("=== Game Loaded with Some Errors ===\n");
    }

    return success;
}

// Quick save - call this automatically
void Auto_Save(void) {
    printf("Auto-saving player data...\n");
    Save_Player_Data(); // Only save player data for quick saves
}

// Initialize empty save files with proper structure
void Initialize_Empty_Save_Files(void) {
    printf("Initializing empty save files with proper structure...\n");

    // Create mobs file with 0 mob count
    const char* mob_filepath = "mobs_data.dat";
    FILE *mob_file = fopen(mob_filepath, "wb");
    if (mob_file) {
        short zero_mobs = 0;
        fwrite(&zero_mobs, sizeof(short), 1, mob_file);
        fclose(mob_file);
        printf("Created empty mobs file with proper structure\n");
    }

    // Create items file with 0 inventory size
    const char* item_filepath = "items_data.dat";
    FILE *item_file = fopen(item_filepath, "wb");
    if (item_file) {
        int zero_items = 0;
        fwrite(&zero_items, sizeof(int), 1, item_file);
        fclose(item_file);
        printf("Created empty items file with proper structure\n");
    }

    // Create empty player file
    const char* player_filepath = "player_data.dat";
    FILE *player_file = fopen(player_filepath, "wb");
    if (player_file) {
        fclose(player_file);
        printf("Created empty player file\n");
    }

    printf("All save files initialized with proper structure!\n");
}