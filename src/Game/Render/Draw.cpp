#include "Draw.hpp"
#include "Sys/Memory.hpp"

namespace IW3SR
{
    void Draw::Line(const vec3& start, const vec3& end, const vec4& color)
    {
		if (LinesCount + 2 > 2735)
			LinesCount = 0;

		R_ConvertColorToBytes(color, LinesVerts[LinesCount].color);
		Memory::Assign<int>(LinesVerts[LinesCount + 1].color, LinesVerts[LinesCount].color);
		Memory::Assign<3, float>(LinesVerts[LinesCount].xyz, start);
		Memory::Assign<3, float>(LinesVerts[LinesCount + 1].xyz, end);

		LinesCount += 2;
    }

	void Draw::HUD(float x, float y, float w, float h, const vec4& color)
	{
		FillRect(x, y, w, h, color);
	}

    void Draw::Box2D(const vec3& position, const vec3& size, const vec4& color, int thickness)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        vec3 tfl3 = { position.x + size.x, position.y - size.y, position.z + size.z };
        vec3 tfr3 = { position.x + size.x, position.y + size.y, position.z + size.z };
        vec3 tbl3 = { position.x - size.x, position.y + size.y, position.z + size.z };
        vec3 tbr3 = { position.x - size.x, position.y - size.y, position.z + size.z };

        vec2 tfl = WorldToScreen(tfl3);
        vec2 tfr = WorldToScreen(tfr3);
        vec2 tbl = WorldToScreen(tbl3);
        vec2 tbr = WorldToScreen(tbr3);

        vec3 bfl3 = { position.x + size.x, position.y - size.y, position.z };
        vec3 bfr3 = { position.x + size.x, position.y + size.y, position.z };
        vec3 bbl3 = { position.x - size.x, position.y + size.y, position.z };
        vec3 bbr3 = { position.x - size.x, position.y - size.y, position.z };

        vec2 bfl = WorldToScreen(bfl3);
        vec2 bfr = WorldToScreen(bfr3);
        vec2 bbl = WorldToScreen(bbl3);
        vec2 bbr = WorldToScreen(bbr3);

        draw->AddLine(tbl, tfr, color, thickness);
        draw->AddLine(tfl, tfr, color, thickness);
        draw->AddLine(tfl, tbr, color, thickness);
        draw->AddLine(tbl, tbr, color, thickness);

        draw->AddLine(bbl, bfr, color, thickness);
        draw->AddLine(bfr, bfl, color, thickness);
        draw->AddLine(bfl, bbr, color, thickness);
        draw->AddLine(bbr, bbl, color, thickness);

        draw->AddLine(bbr, tbr, color, thickness);
        draw->AddLine(bbl, tbl, color, thickness);
        draw->AddLine(bfr, tfr, color, thickness);
        draw->AddLine(bfl, tfl, color, thickness);
    }

	void Draw::Frame()
	{
		RB_DrawLines3D(LinesCount / 2, LinesWidth, LinesVerts.data(), LinesDepthTest);
		LinesCount = 0;
	}
}
