#pragma once
#include <cstdint>

// Offsets namespace for memory-related variables
namespace offsets {
    // Base address of the main module (usually the executable)
    extern uintptr_t base;

    // Base address of the GameAssembly.dll module
    extern uintptr_t GameAssembly;

    namespace localplayer {
        // Offset to check if the player can take damage
        extern uintptr_t CanTakeDamage;// ScheduleOne_PlayerScripts_Health_PlayerHealth$$get_CanTakeDamage proc near

        extern uintptr_t TakeDamage;
    }
}
