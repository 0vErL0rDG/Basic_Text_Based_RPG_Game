#include "../HEADER_FILES/Header_Store.h"

// Background regeneration - call this periodically
void Auto_Regeneration_Background(void) {
    if (p == NULL) return;

    // Health regeneration
    if (p->Health < p->MAX_Health) {
        p->Health += 3;
        if (p->Health > p->MAX_Health) {
            p->Health = p->MAX_Health;
        }
    }

    // Mana regeneration
    if (p->Mana < p->MAX_Mana) {
        p->Mana += 3;
        if (p->Mana > p->MAX_Mana) {
            p->Mana = p->MAX_Mana;
        }
    }
}

// Fast background regeneration after battle
void Post_Battle_Regeneration(void) {
    if (p == NULL) return;

    printf("\nRegenerating...\n");

    while (p->Health < p->MAX_Health || p->Mana < p->MAX_Mana) {
        Auto_Regeneration_Background();
        sleep(1); // Wait 1 second
    }

    printf("Fully regenerated!\n");
}

// Call this in your main loop or whenever you want background regen
void Quick_Background_Regen(void) {
    if (p == NULL) return;
    Auto_Regeneration_Background();
}