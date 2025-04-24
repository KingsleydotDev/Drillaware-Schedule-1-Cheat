#include "includes.h"

namespace hooks {
    // QoL
    // 
    // Initialize the original function pointer to nullptr
    tGetCapacity oGetCapacity = nullptr;
    // The hook function - returns the amount you can pick up
    int __fastcall hkGetCapacity(void* __this) {
        // returns max amount capcity for trash grabber
        return variables::iTrashGrabberCapacityAmount;
    }

    // Player
    // 
    // Initialize the original function pointer to nullptr
    tCanTakeDamage oCanTakeDamage = nullptr;
    // Forces return value to false, making the player invulnerable
    bool __fastcall hkCanTakeDamage(void* __this) {
        return false;
    }

    // Initialize the original function pointer to nullptr
    tTakeDamage oTakeDamage = nullptr;
    // The hook function - disables damage
    void __fastcall hkTakeDamage(void* __this, void* damageInfo) {
        // No call to the original function, meaning damage is ignored
    }

    // unlimited Stamina
    tSetStamina oSetStamina = nullptr;
    void __fastcall hkSetStamina(void* __this, float stamina) {
        // Unlimited stamina: do nothing
    }

    // hooked version of GetFieldOfView
    // Define the original function pointer
    tGetFieldOfView oGetFieldOfView = nullptr;
    // Hook function
    float __fastcall hkGetFieldOfView(void* __this) {
        if (oGetFieldOfView) {
            oGetFieldOfView( __this);
        }
        return variables::fFieldOfView;
    }

    // hooked version of SetFieldOfView
    // Define the original function pointer
    tSetFieldOfView oSetFieldOfView = nullptr;
    // Hook function
    float __fastcall hkSetFieldOfView(void* __this) {
        return variables::fFieldOfView;
    }

    // hooked version ofItem instance get stack limit
    // Define the original function pointer
    tGetStackLimit oGetStackLimit = nullptr;
    // Hook function
    int __fastcall hkGetStackLimit(void* __this) {
        return 9999;
    }

    //Disable body search 
    // Original function pointers
    tUpdateSearch oUpdateSearch = nullptr;
    tAssignTarget oAssignTarget = nullptr;
    tDoesPlayerContainItemsOfInterest oDoesPlayerContainItemsOfInterest = nullptr;
    tBeginBodySearch oBeginBodySearch = nullptr;
    tBeginBodySearch_LocalPlayer oBeginBodySearch_LocalPlayer = nullptr;
    tBeginBodySearch_Networked oBeginBodySearch_Networked = nullptr;

    // Hook implementations

    void __fastcall hkUpdateSearch(void* __this) {
        // Skip updating the search
        return;
    }

    void __fastcall hkAssignTarget(void* __this) {
        // Skip assigning target
        return;
    }

    bool __fastcall hkDoesPlayerContainItemsOfInterest(void* __this) {
        // Always return false to indicate no interesting items
        return false;
    }

    void __fastcall hkBeginBodySearch(void* __this) {
        // Skip body search
        return;
    }

    void __fastcall hkBeginBodySearch_LocalPlayer(void* __this) {
        // Skip local player body search
        return;
    }

    void __fastcall hkBeginBodySearch_Networked(void* __this) {
        // Skip networked body search
        return;
    }
    // end of body search 

    // Original function pointer definition
    tUpdateArrest oUpdateArrest = nullptr;
    // Hook implementation
    void __fastcall hkUpdateArrest(void* __this) {
        // Prevent the arrest from being processed
        return;
    }


    // world 
    // Initialize the original function pointer to nullptr
    tSkateboardIsGrounded oSkateboardIsGrounded = nullptr;
    // Hooked version of SkateboardIsGrounded
    // Forces return value to true, making the skateboard glide
    bool __fastcall hkSkateboardIsGrounded(void* __this) {
        return true;
    }

    //NPC
    // 
    // Initialize the original function pointer to nullptr
    tIsCurrentlyActiveWithTolerance oIsCurrentlyActiveWithTolerance = nullptr;
    // Hooked version of IsCurrentlyActiveWithTolerance
    bool __fastcall hkIsCurrentlyActiveWithTolerance(void* __this) {
        return false; // set to false so people thaink it's not curfew
    }

    //GetSampleSuccess
    // Initialize the original function pointer to nullptr
    tGetSampleSuccess oGetSampleSuccess = nullptr;
    // Hook function definition
    float __fastcall hkGetSampleSuccess(void* __this) {
        return 1.0f;
    }

    //GetOfferSuccessChance
    // Initialize the original function pointer to nullptr
    tGetOfferSuccessChance oGetOfferSuccessChance = nullptr;
    // Hook function definition
    float __fastcall hkGetOfferSuccessChance(void* __this) {
        if (oGetOfferSuccessChance)
            oGetOfferSuccessChance(__this); // call the original function to maintain the function
        return 1.0f; // return 100% chance
    }

}
