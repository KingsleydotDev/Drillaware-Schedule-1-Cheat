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


    // TakeDamag
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

    // GetStackLimit
    typedef float(__fastcall* tGetStackLimit)(void* __this);

    // Declare the original function pointer
    extern tGetStackLimit oGetStackLimit;

    // Hook function declaration
    int __fastcall hkGetStackLimit(void* __this);


}
