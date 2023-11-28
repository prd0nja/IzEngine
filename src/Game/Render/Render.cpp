#include "Render.hpp"
#include "Game/Game.hpp"

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
		if (Active) return;
		Active = true;

		Assets::Initialize();
		Engine::Assets::Initialize();
	}

	void Render::Shutdown()
	{
		Active = false;

		Assets::Shutdown();
		Engine::Assets::Shutdown();
	}

	void Render::Draw3D(GfxCmdBufInput* cmd, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)
	{
		ModuleCallback(OnDraw3D);
		Engine::Draw3D::Frame();
		RB_EndSceneRendering_h(cmd, viewInfo, src, buf);
	}

	void Render::Draw2D(int localClientNum)
	{
		ModuleCallback(OnDraw2D);
		CG_DrawCrosshair_h(localClientNum);
	}

	void Render::Frame()
	{
		GUI::Begin();
		if (Player::CanRender())
			ModuleCallback(OnFrame);
		GUI::End();
	}
}
