#pragma once
#include <cstdint>

namespace offsets {
    extern uintptr_t base;
    extern uintptr_t GameAssembly;

    namespace localplayer {
        extern uintptr_t CanTakeDamage;
        extern uintptr_t TakeDamage;
        extern uintptr_t CameraGetFieldOfView;
        extern uintptr_t GetStackLimit;
        extern uintptr_t SetStamina;
        extern uintptr_t CameraSetFieldOfView;
        extern uintptr_t UpdateArrest;
        extern uintptr_t UpdateSearch;
        extern uintptr_t AssignTarget;
        extern uintptr_t DoesPlayerContainItemsOfInterest;
        extern uintptr_t BeginBodySearch;
        extern uintptr_t BeginBodySearch_LocalPlayer;
        extern uintptr_t BeginBodySearch_Networked;
        extern uintptr_t PunchControllerUpdate;
        extern uintptr_t SetfieldOfView;
        extern uintptr_t PlayerMovementUpdate;
        extern uintptr_t SkatingSkateboardUpdate;
    }

    namespace engine {
        extern uintptr_t CursorsetlockState;
    }

    namespace equippable {
        extern uintptr_t TrashGrabberGetCapacity;
    }

    namespace world {
        extern uintptr_t SkateboardIsGrounded;
        extern uintptr_t GetCookDuration;
        extern uintptr_t OvenIsReady;
        extern uintptr_t GetRandomSymbol;
        extern uintptr_t GetCurrentBetAmount;
        extern uintptr_t GetAdditiveGrowthMultiplier;
        extern uintptr_t LaunderingInterfaceMinPass;
    }

    namespace npc {
        extern uintptr_t IsCurrentlyActiveWithTolerance;
        extern uintptr_t GetSampleSuccess;
        extern uintptr_t GetOfferSuccessChance;
    }
}

namespace pointer {
    extern uintptr_t MaxMixQuantity;
    extern uintptr_t MixTimePerItem;
    extern uintptr_t MovementSpeedScale;
    extern uintptr_t CurrentDropTime;
    extern uintptr_t TimeSinceLastDrop;
    extern uintptr_t DropForce;
    extern uintptr_t minsUntilDeaddropReady;
    extern uintptr_t MinPunchDamage;
    extern uintptr_t MaxPunchDamage;
    extern uintptr_t jumpForce;
    extern uintptr_t MoveSpeedMultiplier;
    extern uintptr_t IsGrounded;
    extern uintptr_t JumpForceSkating;
    extern uintptr_t PushForceMultiplierSkating;
    extern uintptr_t TopSpeed_KmhSkating;
}
