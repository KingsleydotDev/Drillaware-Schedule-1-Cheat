#include "hooks.h"

namespace hooks {
    // Initialize the original function pointer to nullptr
    tCanTakeDamage oCanTakeDamage = nullptr;

    // Hooked version of CanTakeDamage
    // Forces return value to false, making the player invulnerable
    bool __fastcall hkCanTakeDamage(void* __this) {
        return false; // godmode: player cannot take damage
    }

    // Initialize the original function pointer to nullptr
    tTakeDamage oTakeDamage = nullptr;

    // The hook function - disables damage
    void __fastcall hkTakeDamage(void* __this, void* damageInfo) {
        // No call to the original function, meaning damage is ignored
    }

}
