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
        // offset for set field
        extern uintptr_t CameraSetFieldOfView; // UnityEngine_Camera$$set_fieldOfView proc near
        //offset for update arrest
        extern uintptr_t UpdateArrest; // ScheduleOne.NPCs.Behaviour.PursuitBehaviour$$UpdateArrest proc near
        // offset for update search
        extern uintptr_t UpdateSearch; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$UpdateSearch proc near
        // offset for assign target
        extern uintptr_t AssignTarget; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$AssignTarget proc near
        // offset for DoesPlayerContainItemsOfInterest
        extern uintptr_t DoesPlayerContainItemsOfInterest; // ScheduleOne.NPCs.Behaviour.BodySearchBehaviour$$DoesPlayerContainItemsOfInterest proc near
       // offset for BeginBodySearch
        extern uintptr_t BeginBodySearch; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch proc near
        // offset for BeginBodySearch_LocalPlayer
        extern uintptr_t BeginBodySearch_LocalPlayer; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch_LocalPlayer proc near
        //offset for BeginBodySearch_LocalPlayer
        extern uintptr_t BeginBodySearch_Networked; // ScheduleOne.Police.PoliceOfficer$$BeginBodySearch_Networked proc near
        //offset for PunchController
        extern uintptr_t PunchControllerUpdate; //ScheduleOne_Combat_PunchController$$Update proc near
        //offset for SetFov
        extern uintptr_t SetFov;
    }
    namespace equippable {
        // QoL
        // offset for max items in trash grabber
        extern uintptr_t TrashGrabberGetCapacity; // ScheduleOne_Equipping_Equippable_TrashGrabber$$GetCapacity proc near
    }
    namespace world
    {
        extern uintptr_t SkateboardIsGrounded;//ScheduleOne_Skating_Skateboard$$IsGrounded proc near
    }
    namespace npc
    {
        extern uintptr_t IsCurrentlyActiveWithTolerance; // ScheduleOne_Law_CurfewManager$$get_IsCurrentlyActiveWithTolerance proc near
        extern uintptr_t GetSampleSuccess;//ScheduleOne_Economy_Customer$$GetSampleSuccess proc near
        extern uintptr_t GetOfferSuccessChance; // ScheduleOne_Economy_Customer$$GetOfferSuccessChance proc near
    }
}    
namespace pointer {
    extern uintptr_t MaxMixQuantity;
    extern uintptr_t MixTimePerItem;
    extern uintptr_t MovementSpeedScale;;
    extern uintptr_t CurrentDropTime;
    extern uintptr_t TimeSinceLastDrop;
    extern uintptr_t DropForce;
    extern uintptr_t minsUntilDeaddropReady;
    extern uintptr_t MinPunchDamage;            // ScheduleOne.Combat.PunchController
    extern uintptr_t MaxPunchDamage;            // ScheduleOne.Combat.PunchController
}