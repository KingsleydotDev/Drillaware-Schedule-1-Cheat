#include "includes.h"
#include "iostream"
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
	
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool show = false;
bool init = false;



void RenderMenu()
{
	ImGui::StyleColorsDark();
	ImGui::SetNextWindowSize(ImVec2(550, 400), ImGuiCond_Always);
	ImGui::Begin("Drillaware Schedule 1");
	{
		if (ImGui::BeginTabBar("MainTabBar")) {
			if (ImGui::BeginTabItem("QoL")) {
				ImGui::Text("Quality Of Life Mods.");
				if (ImGui::Checkbox("Better Trash Grabber", &variables::bBetterTrashGrabber))
					if (variables::bBetterTrashGrabber)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::equippable::TrashGrabberGetCapacity), &hooks::hkGetCapacity, (LPVOID*)&hooks::oGetCapacity);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::equippable::TrashGrabberGetCapacity));
					}
					if (variables::bBetterTrashGrabber)
						ImGui::SliderInt("Max Capacity", &variables::iTrashGrabberCapacityAmount, 100, 9999);
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::equippable::TrashGrabberGetCapacity));
					}
				if (ImGui::Checkbox("Field Of View", &variables::bCustomFieldOfView))
					if (variables::bCustomFieldOfView)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::SetfieldOfView), &hooks::hkSetfieldOfView, (LPVOID*)&hooks::oSetfieldOfView);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::SetfieldOfView));

					}
					if (variables::bCustomFieldOfView)
						ImGui::SliderFloat("Field Of View", &variables::fFieldOfView, 60.0f, 120.0f);
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::SetfieldOfView));
					}
					if (ImGui::Checkbox("Custom Grow Speed", &variables::bBetterGrowTimes))
						if (&variables::bBetterGrowTimes)
						{
							MH_CreateHook((void*)(offsets::GameAssembly + offsets::world::GetAdditiveGrowthMultiplier), &hooks::hkGetAdditiveGrowthMultiplier, (LPVOID*)&hooks::oGetAdditiveGrowthMultiplier);
							MH_EnableHook((void*)(offsets::GameAssembly + offsets::world::GetAdditiveGrowthMultiplier));
						}
					if (variables::bBetterGrowTimes)
						ImGui::SliderFloat("Growth Multiplier", &variables::fGrowMultiplier, 1.0f, 10.0f);
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::world::GetAdditiveGrowthMultiplier));
					}
					if (ImGui::Checkbox("Oven Multiplier", &variables::bBetterOvenTimes))
						if (&variables::bBetterOvenTimes)
						{
							MH_CreateHook((void*)(offsets::GameAssembly + offsets::world::GetCookDuration), &hooks::hkGetCookDuration, (LPVOID*)&hooks::oGetCookDuration);
							MH_EnableHook((void*)(offsets::GameAssembly + offsets::world::GetCookDuration));
							MH_CreateHook((void*)(offsets::GameAssembly + offsets::world::OvenIsReady), &hooks::hkOvenIsReady, (LPVOID*)&hooks::oOvenIsReady);
							MH_EnableHook((void*)(offsets::GameAssembly + offsets::world::OvenIsReady));
						}
					if (variables::bBetterOvenTimes)
						ImGui::SliderFloat("Oven Multiplier", &variables::fOvenMultiplier, 1.0f, 10.0f);
						else
						{
							MH_DisableHook((void*)(offsets::GameAssembly + offsets::world::GetCookDuration));
							MH_DisableHook((void*)(offsets::GameAssembly + offsets::world::OvenIsReady));
						}

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Player")) {
				if (ImGui::Checkbox("Godmode", &variables::bGodMode))
					if (variables::bGodMode)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::CanTakeDamage), &hooks::hkCanTakeDamage, (LPVOID*)&hooks::oCanTakeDamage);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::CanTakeDamage));
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::TakeDamage), &hooks::hkTakeDamage, (LPVOID*)&hooks::oTakeDamage);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::TakeDamage));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::CanTakeDamage));
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::TakeDamage));
					}
				if (ImGui::Checkbox("Increase Stack Size", &variables::bMaxStack))
					if (variables::bMaxStack)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::GetStackLimit), &hooks::hkGetStackLimit, (LPVOID*)&hooks::oGetStackLimit);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::GetStackLimit));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::GetStackLimit));
					}

				if (ImGui::Checkbox("Unlimited Stamina (fighting)", &variables::bUnlimitedSstamina))
					if (variables::bUnlimitedSstamina)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::SetStamina), &hooks::hkSetStamina, (LPVOID*)&hooks::oSetStamina);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::SetStamina));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::SetStamina));
					}
				if (ImGui::Checkbox("Disable Body Search", &variables::bDisableBodySearches))
					if (variables::bDisableBodySearches)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::UpdateSearch), &hooks::hkUpdateSearch, (LPVOID*)&hooks::oUpdateSearch);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::UpdateSearch));
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::AssignTarget), &hooks::hkAssignTarget, (LPVOID*)&hooks::oAssignTarget);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::AssignTarget));
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::DoesPlayerContainItemsOfInterest), &hooks::hkDoesPlayerContainItemsOfInterest, (LPVOID*)&hooks::oDoesPlayerContainItemsOfInterest);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::DoesPlayerContainItemsOfInterest));
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch), &hooks::hkBeginBodySearch, (LPVOID*)&hooks::oBeginBodySearch);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch));
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch_LocalPlayer), &hooks::hkBeginBodySearch_LocalPlayer, (LPVOID*)&hooks::oBeginBodySearch_LocalPlayer);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch_LocalPlayer));
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch_Networked), &hooks::hkBeginBodySearch_Networked, (LPVOID*)&hooks::oBeginBodySearch_Networked);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch_Networked));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::UpdateSearch));
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::AssignTarget));
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::DoesPlayerContainItemsOfInterest));
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch));
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch_LocalPlayer));
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::BeginBodySearch_Networked));
					}

				if (ImGui::Checkbox("Disable Arrest", &variables::bDisableArrest))
					if (variables::bDisableArrest)
					{
							MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::UpdateArrest), &hooks::hkUpdateArrest, (LPVOID*)&hooks::oUpdateArrest);
							MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::UpdateArrest));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::UpdateArrest));
					}
				if (ImGui::Checkbox("One Hit Punch", &variables::bOneHitPunch))
					if (variables::bOneHitPunch)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::PunchControllerUpdate), &hooks::hkPunchControllerUpdate, (LPVOID*)&hooks::oPunchControllerUpdate);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::PunchControllerUpdate));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::PunchControllerUpdate));
					}
				if (ImGui::Checkbox("Movement Modifiers", &variables::bMovementPatchesEnabled))
					if (variables::bMovementPatchesEnabled)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::PlayerMovementUpdate), &hooks::hkPlayerMovementUpdate, (LPVOID*)&hooks::oPlayerMovementUpdate);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::PlayerMovementUpdate));
					}
					if (variables::bMovementPatchesEnabled)
					{
						ImGui::SliderFloat("Speed Multiplier", &variables::fMoveSpeedMultiplierValue, 1.0f, 10.0f);
						ImGui::SliderFloat("Jump Force", &variables::fJumpForceValue, 5.25f, 30.0f);
						ImGui::Checkbox("Infinite Jumps", &variables::bInfiniteJumpEnabled);
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::PlayerMovementUpdate));
					}
				if (ImGui::Checkbox("Skateboard Modifiers", &variables::bSkatingMovementEnabled))
					if (variables::bSkatingMovementEnabled)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::localplayer::SkatingSkateboardUpdate), &hooks::hkSkatingSkateboardUpdate, (LPVOID*)&hooks::oSkatingSkateboardUpdate);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::localplayer::SkatingSkateboardUpdate));
					}
					if (variables::bSkatingMovementEnabled)
					{
						ImGui::SliderFloat("Push Force Multiplier ", &variables::fPushForceMultiplier, 1.0f, 20.0f);
						ImGui::SliderFloat("Jump Force", &variables::fJumpForceSkatingValue, 30.0f, 150.0f);
						ImGui::SliderFloat("Top Speed", &variables::fTopSpeed_Kmh, 50.0f, 200.0f);
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::localplayer::SkatingSkateboardUpdate));
					}

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("World")) {
				if (ImGui::Checkbox("Skateboard Glider", &variables::bSkateboardJump))
					if (&variables::bSkateboardJump)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::world::SkateboardIsGrounded), &hooks::hkSkateboardIsGrounded, (LPVOID*)&hooks::oSkateboardIsGrounded);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::world::SkateboardIsGrounded));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::world::SkateboardIsGrounded));
					}
				if (ImGui::Checkbox("No Curfew", &variables::bNoCurfew))
					if (&variables::bNoCurfew)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::npc::IsCurrentlyActiveWithTolerance), &hooks::hkIsCurrentlyActiveWithTolerance, (LPVOID*)&hooks::oIsCurrentlyActiveWithTolerance);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::npc::IsCurrentlyActiveWithTolerance));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::npc::IsCurrentlyActiveWithTolerance));
					}
				if (ImGui::Checkbox("Always Hit Jackpot", &variables::bAlwaysHitJAckpot))
					if (&variables::bAlwaysHitJAckpot)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::world::GetRandomSymbol), &hooks::hkGetRandomSymbol, (LPVOID*)&hooks::oGetRandomSymbol);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::world::GetRandomSymbol));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::world::GetRandomSymbol));
					}
				if (ImGui::Checkbox("Custom Bet Amount", &variables::bCustomBetAmount))
					if (&variables::bCustomBetAmount)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::world::GetCurrentBetAmount), &hooks::hkGetCurrentBetAmount, (LPVOID*)&hooks::oGetCurrentBetAmount);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::world::GetCurrentBetAmount));
					}
				if (variables::bCustomBetAmount)
					ImGui::SliderInt("Bet Amount", &variables::iBetAmount, 100, 10000);
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::world::GetCurrentBetAmount));
					}
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("NPC"))
			{
				if (ImGui::Checkbox("Always Accept Sample", &variables::bAlwaysAcceptSample))
					if (&variables::bAlwaysAcceptSample)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::npc::GetSampleSuccess), &hooks::hkGetSampleSuccess, (LPVOID*)&hooks::oGetSampleSuccess);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::npc::GetSampleSuccess));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::npc::GetSampleSuccess));
					}
				if (ImGui::Checkbox("Always Accept Order", &variables::bAlwaysAcceptOffer))
					if (&variables::bAlwaysAcceptOffer)
					{
						MH_CreateHook((void*)(offsets::GameAssembly + offsets::npc::GetOfferSuccessChance), &hooks::hkGetOfferSuccessChance, (LPVOID*)&hooks::oGetOfferSuccessChance);
						MH_EnableHook((void*)(offsets::GameAssembly + offsets::npc::GetOfferSuccessChance));
					}
					else
					{
						MH_DisableHook((void*)(offsets::GameAssembly + offsets::npc::GetOfferSuccessChance));
					}
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Credits")) {
				ImGui::Text("xevss.");
				ImGui::Text("yousef029");
				ImGui::Text("by KingsleydotDev.");
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
	}
	ImGui::End();

}

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}
	if (GetAsyncKeyState(VK_INSERT)&1)
	{
		show = !show;
	}
	
	if (GetAsyncKeyState(VK_DELETE)&1)
	{
	kiero::shutdown();
		return 0;
	}

	if (show)
	{
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		RenderMenu();

		ImGui::Render();

		pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
			//AllocConsole();
			FILE * f;
			//freopen_s(&f, "CONOUT$", "w", stdout);
			//std::cout << "Whats up fam this is the debug console" << std::endl;
			//std::cout <<"GameAssembly.dll Module Base: " << std::hex << offsets::base << std::endl;

		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}