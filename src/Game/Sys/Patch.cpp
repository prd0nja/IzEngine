#include "Patch.hpp"

#define COD4X if (COD4X_HANDLE)

namespace IW3SR::Game
{
	void Patch::Initialize()
	{
		Definitions();
		Renderer();
	}

	void Patch::Definitions()
	{
		// Variables
		COD4X bg_weaponNames = Signature(COD4X_HANDLE, 0x443DDE0);

		// Hooks
		COD4X MainWndProc_h < Signature(COD4X_BIN, "55 89 E5 53 81 EC 84 00 00 00 C7 04 24 02");
		COD4X R_RenderAllLeftovers_h < Signature(COD4X_BIN, "55 89 E5 83 EC 38 89 45 E4 8B 45 E4 89 45 F4");
	}

	void Patch::Renderer()
	{
		// Disable <developer 1> check for debug rendering
		Memory::NOP(0x6496D8, 3);

		// Increase fps cap for menus and loadscreen
		Memory::NOP(0x5001A8, 2);
		COD4X Memory::NOP(Signature(COD4X_BIN, "72 ?? 83 ?? 00 F9 C5 00 07"), 2);
	}
}
