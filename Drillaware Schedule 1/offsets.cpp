#pragma once
#include "offsets.h"
#include <Windows.h>

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
        uintptr_t CameraSetFieldOfView = 0x2987C93; // UnityEngine_Camera$$set_fieldOfView proc near
        uintptr_t UpdateArrest = 0x62DAD0; // ScheduleOne.NPCs.Behaviour.PursuitBehaviour$$UpdateArrest proc near
        uintptr_t UpdateSearch = 0x609A90; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$UpdateSearch proc near
        uintptr_t AssignTarget = 0x606E60; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$AssignTarget proc near
        uintptr_t DoesPlayerContainItemsOfInterest = 0x607A70; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$DoesPlayerContainItemsOfInterest proc near
        uintptr_t BeginBodySearch = 0x57BAF0; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch proc near
        uintptr_t BeginBodySearch_LocalPlayer = 0x57B940; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch_LocalPlayer proc near
        uintptr_t BeginBodySearch_Networked = 0x57B9C0; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch_Networked proc near
    }
    namespace equippable {
        uintptr_t TrashGrabberGetCapacity = 0x84F060; // ScheduleOne_Equipping_Equippable_TrashGrabber$$GetCapacity proc near
        uintptr_t UpdateTrashGrabber = 0x84F620; // ScheduleOne.Equipping.Equippable_TrashGrabber$$Update proc near
    }
    namespace world
    {
        uintptr_t SkateboardIsGrounded = 0xA63020; //ScheduleOne_Skating_Skateboard$$IsGrounded proc near
    }
    namespace npc
    {
        uintptr_t IsCurrentlyActiveWithTolerance = 0x69DDE0; // ScheduleOne_Law_CurfewManager$$get_IsCurrentlyActiveWithTolerance proc near
        uintptr_t GetSampleSuccess = 0x6F54F0; // ScheduleOne_Economy_Customer$$GetSampleSuccess proc near
    }
}
namespace pointer {
    uintptr_t MaxMixQuantity = 0x294;
    uintptr_t MixTimePerItem = 0x290;
    uintptr_t MovementSpeedScale = 0x180;
    uintptr_t CurrentDropTime = 0xC0;
    uintptr_t TimeSinceLastDrop = 0xC4;
    uintptr_t DropForce = 0xA4;
    uintptr_t minsUntilDeaddropReady = 0x340;
}