#include "variables.h"

namespace variables
{
	// QoL
	bool bBetterTrashGrabber = false;
	int iTrashGrabberCapacityAmount = 100;
	bool bCustomFieldOfView = false;
	float fFieldOfView = 80.0f;

	// Player
	bool bGodMode = false;
	bool bMaxStack = false;
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



	//world 
	bool bSkateboardJump = false;
	bool bNoCurfew = false;
	bool bInstantOven = false;
	bool bAlwaysHitJAckpot = false;
	bool bCustomBetAmount = false;
	int iBetAmount = 500;

	//NPC
	bool bAlwaysAcceptSample = false;
	bool bOffersNeverExpire = false;
	bool bAlwaysAcceptOffer = false;
}