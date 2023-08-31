#include "Render.hpp"
#include "Game/Game.hpp"

namespace IW3SR
{
	Render::Render()
	{

	}

	void Render::Frame()
	{

	}

	void Render::DrawLine(glm::vec3 from, glm::vec3 to, glm::vec4 color)
	{

	}
}

void RB_EndSceneRendering(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)
{
	SR->Render->Frame();
}
