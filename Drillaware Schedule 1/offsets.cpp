#pragma once
#include "includes.h"

// Offsets namespace for memory-related variables
namespace offsets {
    uintptr_t base = (uintptr_t)GetModuleHandle(NULL);
    uintptr_t GameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

    namespace localplayer {
        uintptr_t CanTakeDamage = 0x6BE170; // ScheduleOne_PlayerScripts_Health_PlayerHealth$$get_CanTakeDamage proc near
        uintptr_t TakeDamage = 0x6BD560; // ScheduleOne_PlayerScripts_Health_PlayerHealth$$RpcWriter___Observers_TakeDamage_3505310624 proc near
        uintptr_t CameraGetFieldOfView = 0x29870E0; // UnityEngine_Camera$$get_fieldOfView proc near
        uintptr_t GetStackLimit = 0x8527B0; // ScheduleOne_ItemFramework_ItemInstance$$get_StackLimit proc near
        uintptr_t SetStamina = 0x6C6670; // ScheduleOne_PlayerScripts_PlayerMovement$$SetStamina proc near
    }
    namespace equippable {
        uintptr_t TrashGrabberGetCapacity = 0x84F060; // ScheduleOne_Equipping_Equippable_TrashGrabber$$GetCapacity proc near
    }
}