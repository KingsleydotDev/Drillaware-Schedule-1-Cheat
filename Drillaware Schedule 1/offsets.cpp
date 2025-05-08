#pragma once
#include "offsets.h"
#include <Windows.h>

// Offsets namespace for memory-related variables
// updated offsets to v0.3.5f3
namespace offsets {
    uintptr_t base = (uintptr_t)GetModuleHandle(NULL);
    uintptr_t GameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

    namespace localplayer {
        uintptr_t CanTakeDamage = 0x6F98B0; // ScheduleOne.PlayerScripts.Health.PlayerHealth$$get_CanTakeDamage
        uintptr_t TakeDamage = 0x6F8CA0; // ScheduleOne.PlayerScripts.Health.PlayerHealth$$RpcWriter___Observers_TakeDamage_3505310624
        uintptr_t GetStackLimit = 0x8702D0; // ScheduleOne.ItemFramework.ItemInstance$$get_StackLimit
        uintptr_t SetStamina = 0x6DFF50; // ScheduleOne.PlayerScripts.PlayerMovement$$SetStamina
        uintptr_t UpdateArrest = 0x65D7E0; // ScheduleOne.NPCs.Behaviour.PursuitBehaviour$$UpdateArrest
        uintptr_t UpdateSearch = 0x627F60; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$UpdateSearch
        uintptr_t AssignTarget = 0x6250F0; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$AssignTarget
        uintptr_t DoesPlayerContainItemsOfInterest = 0x625E70; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$DoesPlayerContainItemsOfInterest
        uintptr_t BeginBodySearch = 0x599BA0; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch
        uintptr_t BeginBodySearch_LocalPlayer = 0x5999F0; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch.LocalPlayer
        uintptr_t BeginBodySearch_Networked = 0x599A70; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch.Networked
        uintptr_t PunchControllerUpdate = 0x7767C0; // ScheduleOne.Combat.PunchController$$Update
        uintptr_t SetfieldOfView = 0x2C519B0; // UnityEngine.Camera$$set_fieldOfView
        uintptr_t PlayerMovementUpdate = 0x6E11A0; // ScheduleOne.PlayerScripts.PlayerMovement$$Update
        uintptr_t SkatingSkateboardUpdate = 0xA8B0A0; // ScheduleOne.Skating.Skateboard$$Update
    }
    namespace engine {
        uintptr_t CursorsetlockState = 0x2C73700; // UnityEngine.Cursor$$set_lockState
    }
    namespace equippable {
        uintptr_t TrashGrabberGetCapacity = 0x86CB80; // ScheduleOne.Equipping.Equippable.TrashGrabber$$GetCapacity
        uintptr_t UpdateTrashGrabber = 0x86D140; // ScheduleOne.Equipping.Equippable.TrashGrabber$$Update
    }
    namespace world {
        uintptr_t SkateboardIsGrounded = 0xA894B0; // ScheduleOne.Skating.Skateboard$$IsGrounded
        uintptr_t GetCookDuration = 0x9BF270; // ScheduleOne.ObjectScripts.OvenCookOperation$$GetCookDuration
        uintptr_t OvenIsReady = 0x9BF4C0; // ScheduleOne.ObjectScripts.OvenCookOperation$$IsReady
        uintptr_t GetRandomSymbol = 0x7C5250; // ScheduleOne.Casino.SlotMachine$$GetRandomSymbol
        uintptr_t GetCurrentBetAmount = 0x7C7470; // ScheduleOne.Casino.SlotMachine$$get_currentBetAmount
        uintptr_t GetAdditiveGrowthMultiplier = 0x97A030; // ScheduleOne.ObjectScripts.Pot$$GetAdditiveGrowthMultiplier
    }
    namespace npc {
        uintptr_t IsCurrentlyActiveWithTolerance = 0x6B3CD0; // ScheduleOne.Law.CurfewManager$$get_IsCurrentlyActiveWithTolerance
        uintptr_t GetSampleSuccess = 0x71E250; // ScheduleOne.Economy.Customer$$GetSampleSuccess
        uintptr_t GetOfferSuccessChance = 0x71D130; // ScheduleOne.Economy.Customer$$GetOfferSuccessChance
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
    uintptr_t IsGrounded = 0xBC;                // <IsGrounded>k__BackingField
    uintptr_t JumpForceSkating = 0x1D0;
    uintptr_t PushForceMultiplierSkating = 0x218;
    uintptr_t TopSpeed_KmhSkating = 0x214;
}
