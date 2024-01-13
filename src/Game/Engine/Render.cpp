#include "Render.hpp"
#include "Assets.hpp"
#include "Drawing/Draw2D.hpp"
#include "Drawing/Draw3D.hpp"

#include "Engine/Backends/DX9/Assets.hpp"

namespace IW3SR
{
	Render::Render()
	{
		Patch();
	}

	void Render::Patch()
	{
		// Disable <developer 1> check for drawing debug lines & collisions
		Memory::NOP(0x6496D8, 3);

		// Increase fps cap to 125 for menus and loadscreen
		Memory::Set<char>(0x500176, 8);
		Memory::Set<char>(0x500179, 8);
	}

	void Render::Initialize()
	{
		R_Init_h();
		Assets::Initialize();
		Game::Assets::Initialize();
	}

	void Render::Shutdown(int window)
	{
		Game::Assets::Shutdown();
		Assets::Shutdown();
		R_Shutdown_h(window);
	}

	void Render::Draw3D(GfxCmdBufInput* cmd, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)
	{
		GameCallback(OnDraw3D);
		Game::Draw3D::Frame();
		RB_EndSceneRendering_h(cmd, viewInfo, src, buf);
	}

	void Render::Draw2D(int localClientNum)
	{
		GameCallback(OnDraw2D);
		CG_DrawCrosshair_h(localClientNum);
	}

	void Render::Frame()
	{
		GUI::Begin();
		if (Player::CanRender())
			GameCallback(OnFrame);
		GUI::End();
	}
}
