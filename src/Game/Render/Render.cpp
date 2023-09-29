#include "Render.hpp"
#include "Game/Game.hpp"
#include "Sys/Memory.hpp"
#include "Utils/Math.hpp"

namespace IW3SR
{
	Render::Render()
	{
		//direct3d_create9_h.Install();
		//RB_EndSceneRendering_h.Install();

		// Disable <developer 1> check for drawing debug lines & collisions
		//Memory::NOP(0x6496D8, 3);
	}

	void Render::Frame() { }
}
