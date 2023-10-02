#include "Draw.hpp"
#include "Sys/Memory.hpp"

namespace IW3SR
{
    void Draw::Line(glm::vec3 start, glm::vec3 end, glm::vec4 color)
    {
		float colorArray[4];

		if (LinesCount + 2 > 2735)
			LinesCount = 0;
		glm::set_float4(colorArray, color);
		R_ConvertColorToBytes(colorArray, LinesVerts[LinesCount].color);
		Memory::Reinterpret<int>(LinesVerts[LinesCount + 1].color, LinesVerts[LinesCount].color);

		glm::set_float3(LinesVerts[LinesCount].xyz, start);
		glm::set_float3(LinesVerts[LinesCount + 1].xyz, end);

		LinesCount += 2;
    }

	void Draw::Rect2D(glm::vec4 color, float x, float y, float w, float h)
	{
		float c[4];
		glm::set_float4(c, color);
		CG_FillRect(x, y, w, h, c);
	}

	void Draw::Frame()
	{
		RB_DrawLines3D(LinesCount / 2, LinesWidth, LinesVerts.data(), LinesDepthTest);
		LinesCount = 0;
	}
}
