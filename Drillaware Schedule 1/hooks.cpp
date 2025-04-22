#include "includes.h"

namespace hooks {
    // QoL

    // Initialize the original function pointer to nullptr
    tGetCapacity oGetCapacity = nullptr;

    // The hook function - returns the amount you can pick up
    int __fastcall hkGetCapacity(void* __this) {
        // returns max amount capcity for trash grabber
        return variables::iTrashGrabberCapacityAmount;
    }




    // Player
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


    // hooked version of GetFieldOfView
    // Define the original function pointer
    tGetFieldOfView oGetFieldOfView = nullptr;

    // Hook function
    float __fastcall hkGetFieldOfView(void* __this) {
        return variables::fFieldOfView;
    }
}
