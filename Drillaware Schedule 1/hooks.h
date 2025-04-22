#pragma once

// Hook declarations for game functions
namespace hooks {
    // QoL
    // Trash Grabber GetCapacity
    // Typedef for the original GetCapacity function
    typedef void(__fastcall* tGetCapacity)(void* __this, void* damageInfo);

    // Declaration of the original function pointer
    extern tGetCapacity oGetCapacity;

    // Hook function declaration
    int __fastcall hkGetCapacity(void* __this);


    // Player
    // CanTakeDamage
    // Typedef for the CanTakeDamage function signature
    typedef bool(__fastcall* tCanTakeDamage)(void* __this);

    // Pointer to the original CanTakeDamage function
    extern tCanTakeDamage oCanTakeDamage;

    // Hooked version of CanTakeDamage — always returns false (godmode)
    bool __fastcall hkCanTakeDamage(void* __this);


    // TakeDamage
    // Typedef for the original TakeDamage function
    typedef void(__fastcall* tTakeDamage)(void* __this, void* damageInfo);

    // Declaration of the original function pointer
    extern tTakeDamage oTakeDamage;

    // Hook function declaration
    void __fastcall hkTakeDamage(void* __this, void* damageInfo);


    // GetFieldOfView
    // Correct typedef for a __fastcall function that returns float
    typedef float(__fastcall* tGetFieldOfView)(void* __this);

    // Declare the original function pointer
    extern tGetFieldOfView oGetFieldOfView;

    // Hook function declaration
    float __fastcall hkGetFieldOfView(void* __this);
     

    // SetFieldOfView
    // Correct typedef for a __fastcall function that returns float
    typedef float(__fastcall* tSetFieldOfView)(void* __this);

    // Declare the original function pointer
    extern tSetFieldOfView oSetFieldOfView;

    // Hook function declaration
    float __fastcall hkSetFieldOfView(void* __this);


    // GetStackLimit
    typedef float(__fastcall* tGetStackLimit)(void* __this);

    // Declare the original function pointer
    extern tGetStackLimit oGetStackLimit;

    // Hook function declaration
    int __fastcall hkGetStackLimit(void* __this);


    // Unlimited stamina
    // Type definition for SetStamina
    typedef void(__fastcall* tSetStamina)(void* __this, float stamina);
    // Pointer to original function
    extern tSetStamina oSetStamina;
    // Our hook function
    void __fastcall hkSetStamina(void* __this, float stamina);


    //Disable body search  by yousef 
    // Hook typedefs
    typedef void(__fastcall* tUpdateSearch)(void* __this);
    typedef void(__fastcall* tAssignTarget)(void* __this);
    typedef bool(__fastcall* tDoesPlayerContainItemsOfInterest)(void* __this);
    typedef void(__fastcall* tBeginBodySearch)(void* __this);
    typedef void(__fastcall* tBeginBodySearch_LocalPlayer)(void* __this);
    typedef void(__fastcall* tBeginBodySearch_Networked)(void* __this);

    // Original function pointers
    extern tUpdateSearch oUpdateSearch;
    extern tAssignTarget oAssignTarget;
    extern tDoesPlayerContainItemsOfInterest oDoesPlayerContainItemsOfInterest;
    extern tBeginBodySearch oBeginBodySearch;
    extern tBeginBodySearch_LocalPlayer oBeginBodySearch_LocalPlayer;
    extern tBeginBodySearch_Networked oBeginBodySearch_Networked;

    // Hook function declarations
    void __fastcall hkUpdateSearch(void* __this);
    void __fastcall hkAssignTarget(void* __this);
    bool __fastcall hkDoesPlayerContainItemsOfInterest(void* __this);
    void __fastcall hkBeginBodySearch(void* __this);
    void __fastcall hkBeginBodySearch_LocalPlayer(void* __this);
    void __fastcall hkBeginBodySearch_Networked(void* __this);
    // end of body search 


}