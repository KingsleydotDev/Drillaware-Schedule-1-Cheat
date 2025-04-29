#pragma once

// Hook declarations for game functions
namespace hooks {
    // QoL
    // 
    // Trash Grabber GetCapacity
    // Typedef for the original GetCapacity function
    typedef void(__fastcall* tGetCapacity)(void* __this, void* damageInfo);
    // Declaration of the original function pointer
    extern tGetCapacity oGetCapacity;
    // Hook function declaration
    int __fastcall hkGetCapacity(void* __this);

    //SetfieldOfView
    // Typedef for SetfieldOfView function
    typedef void(__fastcall* tSetfieldOfView)(void* CameraMain, float fov);

    // Declare the original and hooked function
    extern tSetfieldOfView oSetfieldOfView;
    void __fastcall hkSetfieldOfView(void* CameraMain, float fov);

    // Player
    // 
    // CanTakeDamage
    // Typedef for the CanTakeDamage function signature
    typedef bool(__fastcall* tCanTakeDamage)(void* __this);
    // Pointer to the original CanTakeDamage function
    extern tCanTakeDamage oCanTakeDamage;
    // Hooked version of CanTakeDamage — always returns false (godmode)
    bool __fastcall hkCanTakeDamage(void* __this);

    // TakeDamage
    // Typedef for the original TakeDamage function
    typedef void(__fastcall* tTakeDamage)(void* __this, void* damageInfo);
    // Declaration of the original function pointer
    extern tTakeDamage oTakeDamage;
    // Hook function declaration
    void __fastcall hkTakeDamage(void* __this, void* damageInfo);

    // GetStackLimit
    typedef float(__fastcall* tGetStackLimit)(void* __this);
    // Declare the original function pointer
    extern tGetStackLimit oGetStackLimit;
    // Hook function declaration
    int __fastcall hkGetStackLimit(void* __this);

    // Unlimited stamina
    // Type definition for SetStamina
    typedef void(__fastcall* tSetStamina)(void* __this, float stamina);
    // Pointer to original function
    extern tSetStamina oSetStamina;
    // Our hook function
    void __fastcall hkSetStamina(void* __this, float stamina);

    //Disable body search  by yousef 
    // Hook typedefs
    typedef void(__fastcall* tUpdateSearch)(void* __this);
    typedef void(__fastcall* tAssignTarget)(void* __this);
    typedef bool(__fastcall* tDoesPlayerContainItemsOfInterest)(void* __this);
    typedef void(__fastcall* tBeginBodySearch)(void* __this);
    typedef void(__fastcall* tBeginBodySearch_LocalPlayer)(void* __this);
    typedef void(__fastcall* tBeginBodySearch_Networked)(void* __this);

    // Original function pointers
    extern tUpdateSearch oUpdateSearch;
    extern tAssignTarget oAssignTarget;
    extern tDoesPlayerContainItemsOfInterest oDoesPlayerContainItemsOfInterest;
    extern tBeginBodySearch oBeginBodySearch;
    extern tBeginBodySearch_LocalPlayer oBeginBodySearch_LocalPlayer;
    extern tBeginBodySearch_Networked oBeginBodySearch_Networked;

    // Hook function declarations
    void __fastcall hkUpdateSearch(void* __this);
    void __fastcall hkAssignTarget(void* __this);
    bool __fastcall hkDoesPlayerContainItemsOfInterest(void* __this);
    void __fastcall hkBeginBodySearch(void* __this);
    void __fastcall hkBeginBodySearch_LocalPlayer(void* __this);
    void __fastcall hkBeginBodySearch_Networked(void* __this);
    // end of body search 

    // Anti Arrest - Hook typedef
    typedef void(__fastcall* tUpdateArrest)(void* __this);
    // External original function pointer
    extern tUpdateArrest oUpdateArrest;
    // Hook function declaration
    void __fastcall hkUpdateArrest(void* __this);

    //OneHitPunch
    // Typedef for the PunchControllerUpdate function
    typedef void(__fastcall* tPunchControllerUpdate)(void* __this);
    // Declaration of the original function pointer
    extern tPunchControllerUpdate oPunchControllerUpdate;
    // Hook function declaration
    void __fastcall hkPunchControllerUpdate(void* __this);

    // Function typedef for the hook
    typedef void(__fastcall* tPlayerMovementUpdate)(void* __this);
    // Declaration of original function pointer
    extern tPlayerMovementUpdate oPlayerMovementUpdate;
    // Hook function declaration
    void __fastcall hkPlayerMovementUpdate(void* __this);


    // world
    // 
    // SkateboardIsGrounded
    // Typedef for the SkateboardIsGrounded function signature
    typedef bool(__fastcall* tSkateboardIsGrounded)(void* __this);
    // Pointer to the original SkateboardIsGrounded function
    extern tSkateboardIsGrounded oSkateboardIsGrounded;
    // Hooked version of SkateboardIsGrounded — always returns true bhop
    bool __fastcall hkSkateboardIsGrounded(void* __this);

    //instant oven
    // Typedefs
    typedef void(__fastcall* tGetCookDuration)(void* __this);
    typedef void(__fastcall* tOvenIsReady)(void* __this);

    // Hooked Function Declarations
    int __fastcall hkGetCookDuration(void* __this);
    bool __fastcall hkOvenIsReady(void* __this);

    // Original Function Pointers
    extern tGetCookDuration oGetCookDuration;
    extern tOvenIsReady oOvenIsReady;

    // always hit jackpot
    // Typedef for the original function
    typedef int(__fastcall* tGetRandomSymbol)(void* __this);
    // Declaration of the original function pointer
    extern tGetRandomSymbol oGetRandomSymbol;
    // Declaration of the hook function
    int __fastcall hkGetRandomSymbol(void* __this);

    //bet amount
    // Typedef for the original bet amount function
    typedef int(__fastcall* tGetCurrentBetAmount)(void* __this);
    // Declaration of the original function pointer
    extern tGetCurrentBetAmount oGetCurrentBetAmount;
    // Declaration of the hook function
    int __fastcall hkGetCurrentBetAmount(void* __this);


    //NPC 
    // 
    // IsCurrentlyActiveWithTolerance
    // Typedef for theIsCurrentlyActiveWithTolerance function signature
    typedef bool(__fastcall* tIsCurrentlyActiveWithTolerance)(void* __this);
    // Pointer to the original IsCurrentlyActiveWithTolerance function
    extern tIsCurrentlyActiveWithTolerance oIsCurrentlyActiveWithTolerance;
    // Hooked version of IsCurrentlyActiveWithTolerance — always returns true bhop
    bool __fastcall hkIsCurrentlyActiveWithTolerance(void* __this);

    //GetSampleSuccess
    // Typedef for the function pointer
    typedef float(__fastcall* tGetSampleSuccess)(void* __this);
    // Declaration of the original function pointer
    extern tGetSampleSuccess oGetSampleSuccess;
    // Hook function declaration
    float __fastcall hkGetSampleSuccess(void* __this);

    //GetOfferSuccessChance
    // // Typedef for the function pointer
    typedef float(__fastcall* tGetOfferSuccessChance)(void* __this);
    // Declaration of the original function pointer
    extern tGetOfferSuccessChance oGetOfferSuccessChance;
    // Hook function declaration
    float __fastcall hkGetOfferSuccessChance(void* __this);



}