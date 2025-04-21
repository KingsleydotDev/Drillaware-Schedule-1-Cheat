#pragma once

// Hook declarations for game functions
namespace hooks {
    // Typedef for the CanTakeDamage function signature
    typedef bool(__fastcall* tCanTakeDamage)(void* __this);

    // Pointer to the original CanTakeDamage function
    extern tCanTakeDamage oCanTakeDamage;

    // Hooked version of CanTakeDamage — always returns false (godmode)
    bool __fastcall hkCanTakeDamage(void* __this);
}
