#include "variables.h"

namespace variables
{
	// QoL
	bool bBetterTrashGrabber = false;
	int iTrashGrabberCapacityAmount = 100;
	bool bCustomFieldOfView = false;
	float fFieldOfView = 80.0f;
	bool bBetterGrowTimes = false;
	float fGrowMultiplier = 1.0f;
	bool bBetterOvenTimes = false;
	float fOvenMultiplier = 1.0f;
	bool bMaxStack = false;

	bool debug = false;
	int debug_1 = 1;

	// Player
	bool bGodMode = false;
	bool bUnlimitedSstamina = false;
	bool bDisableBodySearches = false;
	bool bDisableArrest = false;

	bool bOneHitPunch = false;
	float foriginalMinDamage = 0.0f;
	float foriginalMaxDamage = 0.0f;
	bool bOneHitPunchStored = false;

	bool bMovementPatchesEnabled = false;
	bool bInfiniteJumpEnabled = false;
	float fMoveSpeedMultiplierValue = 1.0f;
	float fJumpForceValue = 5.25f;

	bool bSkatingMovementEnabled = false;
	float fJumpForceSkatingValue = 35.0f;
	float fTopSpeed_Kmh = 50.0f;
	float fPushForceMultiplier = 1.0f;
	bool bIsGroundedSkating = false;



	//world 
	bool bSkateboardJump = false;
	bool bNoCurfew = false;
	bool bInstantOven = false;
	bool bAlwaysHitJAckpot = false;
	bool bCustomBetAmount = false;
	int iBetAmount = 500;

	//NPC
	bool bAlwaysAcceptSample = false;
	bool bAlwaysAcceptOffer = false;
}