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
        uintptr_t GetStackLimit = 0x8527B0; // ScheduleOne_ItemFramework_ItemInstance$$get_StackLimit proc near
        uintptr_t SetStamina = 0x6C6670; // ScheduleOne_PlayerScripts_PlayerMovement$$SetStamina proc nea
        uintptr_t UpdateArrest = 0x62DAD0; // ScheduleOne.NPCs.Behaviour.PursuitBehaviour$$UpdateArrest proc near
        uintptr_t UpdateSearch = 0x609A90; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$UpdateSearch proc near
        uintptr_t AssignTarget = 0x606E60; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$AssignTarget proc near
        uintptr_t DoesPlayerContainItemsOfInterest = 0x607A70; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$DoesPlayerContainItemsOfInterest proc near
        uintptr_t BeginBodySearch = 0x57BAF0; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch proc near
        uintptr_t BeginBodySearch_LocalPlayer = 0x57B940; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch_LocalPlayer proc near
        uintptr_t BeginBodySearch_Networked = 0x57B9C0; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch_Networked proc near
        uintptr_t PunchControllerUpdate = 0x76F220; //ScheduleOne_Combat_PunchController$$Update proc near
        uintptr_t SetfieldOfView = 0x2987CA0; //UnityEngine_Camera$$set_fieldOfView proc near
        uintptr_t PlayerMovementUpdate = 0x6C78C0; // ScheduleOne.PlayerScripts.PlayerMovement$$Update
    }
    namespace equippable {
        uintptr_t TrashGrabberGetCapacity = 0x84F060; // ScheduleOne_Equipping_Equippable_TrashGrabber$$GetCapacity proc near
        uintptr_t UpdateTrashGrabber = 0x84F620; // ScheduleOne.Equipping.Equippable_TrashGrabber$$Update proc near
    }
    namespace world
    {
        uintptr_t SkateboardIsGrounded = 0xA63020; //ScheduleOne_Skating_Skateboard$$IsGrounded proc near
        uintptr_t GetCookDuration = 0x99F590; // ScheduleOne.ObjectScripts.OvenCookOperation$$GetCookDuration proc near
        uintptr_t OvenIsReady = 0x99F7E0; // ScheduleOne.ObjectScripts.OvenCookOperation$$IsReady proc near
        uintptr_t GetRandomSymbol = 0x7881A0; // ScheduleOne.Casino.SlotMachine$$GetRandomSymbol proc near
        uintptr_t GetCurrentBetAmount = 0x78A3C0; // ScheduleOne.Casino.SlotMachine$$get_currentBetAmount proc near
    }
    namespace npc
    {
        uintptr_t IsCurrentlyActiveWithTolerance = 0x69DDE0; // ScheduleOne_Law_CurfewManager$$get_IsCurrentlyActiveWithTolerance proc near
        uintptr_t GetSampleSuccess = 0x6F54F0; // ScheduleOne_Economy_Customer$$GetSampleSuccess proc near
        uintptr_t GetOfferSuccessChance = 0x6F45C0; // ScheduleOne_Economy_Customer$$GetOfferSuccessChance proc near
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
    uintptr_t MinPunchDamage = 0x30;            // ScheduleOne.Combat.PunchController
    uintptr_t MaxPunchDamage = 0x34;            // ScheduleOne.Combat.PunchController
    uintptr_t jumpForce = 0x44;                 // ScheduleOne.PlayerScripts.PlayerMovement
    uintptr_t MoveSpeedMultiplier = 0x3C;       // ScheduleOne.PlayerScripts.PlayerMovement
    uintptr_t IsGrounded = 0xBC;               // <IsGrounded>k__BackingField
}