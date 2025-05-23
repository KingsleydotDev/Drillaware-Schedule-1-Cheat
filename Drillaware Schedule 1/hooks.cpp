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

    // Define the original function pointer
    tSetfieldOfView oSetfieldOfView = nullptr;
    // Hooked function
    void __fastcall hkSetfieldOfView(void* CameraMain, float fov)
    {
        float newFov = variables::fFieldOfView;

        // You can add logic here to conditionally change FOV if needed
        oSetfieldOfView(CameraMain, newFov);
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

    // hooked version ofItem instance get stack limit
    // Define the original function pointer
    tGetStackLimit oGetStackLimit = nullptr;
    // Hook function
    int __fastcall hkGetStackLimit(void* __this) {
        return 100; // better stack amount 
    }

    tCursorsetlockState oCursorsetlockState = nullptr;
    // Hook function
    int __fastcall hkCursorsetlockState(void* __this) {
        if (oCursorsetlockState)
            oCursorsetlockState(__this);
        return variables::debug_1; //
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

    // Initialize the original function pointer
    tPunchControllerUpdate oPunchControllerUpdate = nullptr;
    // Hook function definition
    void __fastcall hkPunchControllerUpdate(void* __this) {
        if (oPunchControllerUpdate) {
            if (!variables::bOneHitPunchStored) {
                variables::foriginalMinDamage = *(float*)((uintptr_t)__this + pointer::MinPunchDamage);
                variables::foriginalMaxDamage = *(float*)((uintptr_t)__this + pointer::MaxPunchDamage);
                variables::bOneHitPunchStored = true;
            }

            if (variables::bOneHitPunch) {
                *(float*)((uintptr_t)__this + pointer::MinPunchDamage) = 10000.0f;
                *(float*)((uintptr_t)__this + pointer::MaxPunchDamage) = 1000000.0f;
            }
            else {
                *(float*)((uintptr_t)__this + pointer::MinPunchDamage) = variables::foriginalMinDamage;
                *(float*)((uintptr_t)__this + pointer::MaxPunchDamage) = variables::foriginalMaxDamage;
            }
        }

        if (oPunchControllerUpdate) {
            oPunchControllerUpdate(__this);
        }
    }

    // Definition of original function pointer
    tPlayerMovementUpdate oPlayerMovementUpdate = nullptr;
    void __fastcall hkPlayerMovementUpdate(void* __this) {
        if (variables::bInfiniteJumpEnabled) {
            *(bool*)((uintptr_t)__this + pointer::IsGrounded) = true; // IsGrounded
        }
        *(float*)((uintptr_t)__this + pointer::MoveSpeedMultiplier) = variables::fMoveSpeedMultiplierValue; // MoveSpeedMultiplier
        *(float*)((uintptr_t)__this + pointer::jumpForce) = variables::fJumpForceValue; // jumpForce


        // Call the original function
        if (oPlayerMovementUpdate) {
            oPlayerMovementUpdate(__this);
        }
    }

    // Definition of original function pointer
    tSkatingSkateboardUpdate oSkatingSkateboardUpdate = nullptr;
    void __fastcall hkSkatingSkateboardUpdate(void* __this) {
        *(float*)((uintptr_t)__this + pointer::JumpForceSkating) = variables::fJumpForceSkatingValue; // jump force
        *(float*)((uintptr_t)__this + pointer::PushForceMultiplierSkating) = variables::fPushForceMultiplier; // push force
        *(float*)((uintptr_t)__this + pointer::TopSpeed_KmhSkating) = variables::fTopSpeed_Kmh; // top speed
        // Call the original function
        if (oSkatingSkateboardUpdate) {
            oSkatingSkateboardUpdate(__this);
        }
    }




    // world 
    // Initialize the original function pointer to nullptr
    tSkateboardIsGrounded oSkateboardIsGrounded = nullptr;
    // Hooked version of SkateboardIsGrounded
    // Forces return value to true, making the skateboard glide
    bool __fastcall hkSkateboardIsGrounded(void* __this) {
        if (oSkateboardIsGrounded)
            oSkateboardIsGrounded(__this);
        return true;
    }

    // Initialize original function pointers to nullptr
    tGetCookDuration oGetCookDuration = nullptr;
    tOvenIsReady oOvenIsReady = nullptr;
    // Hook implementations
    int __fastcall hkGetCookDuration(void* __this) {
        return variables::fOvenMultiplier; // better oven times
    }
    bool __fastcall hkOvenIsReady(void* __this) {
        return true; // Always ready
    }

    // Define the original function pointer
    tGetRandomSymbol oGetRandomSymbol = nullptr;
    // Hook function that always returns jackpot
    int __fastcall hkGetRandomSymbol(void* __this) {
        return 5;  // 5 = Jackpot value
    }

    // Define the original function pointer
    tGetCurrentBetAmount oGetCurrentBetAmount = nullptr;
    // Hook function that always returns a huge bet
    int __fastcall hkGetCurrentBetAmount(void* __this) {
        return variables::iBetAmount;  //bet amount
    }

    // Definition of original function pointer
    tGetAdditiveGrowthMultiplier oGetAdditiveGrowthMultiplier = nullptr;
    // Hook function definition
    float __cdecl hkGetAdditiveGrowthMultiplier(void* __this, void* method) {
        return variables::fGrowMultiplier; 
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
