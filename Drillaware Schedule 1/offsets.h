#pragma once
#include <cstdint>

// Offsets namespace for memory-related variables
namespace offsets {
    // Base address of the main module (usually the executable)
    extern uintptr_t base;

    // Base address of the GameAssembly.dll module
    extern uintptr_t GameAssembly;

    namespace localplayer {
        //QoL
        // 
        // 
        // Player 
        // Offset to check if the player can take damage
        extern uintptr_t CanTakeDamage;// ScheduleOne_PlayerScripts_Health_PlayerHealth$$get_CanTakeDamage proc near
        // offset to take damage
        extern uintptr_t TakeDamage; // ScheduleOne_PlayerScripts_Health_PlayerHealth$$RpcWriter___Observers_TakeDamage_3505310624 proc near
        // offset to set camera field of view
        extern uintptr_t CameraGetFieldOfView; // UnityEngine_Camera$$get_fieldOfView proc near
        // offset for imtem stack size
        extern uintptr_t GetStackLimit;// ScheduleOne_ItemFramework_ItemInstance$$get_StackLimit proc near
        // offset for SetStamina
        extern uintptr_t SetStamina; //ScheduleOne_PlayerScripts_PlayerMovement$$SetStamina proc near
    }
    namespace equippable {
        // QoL
        // offset for max items in trash grabber
        extern uintptr_t TrashGrabberGetCapacity; // ScheduleOne_Equipping_Equippable_TrashGrabber$$GetCapacity proc near
    }
}    