#include "FPS.hpp"
#include "Sys/Dvar.hpp"

namespace IW3SR
{
	FPS::FPS()
	{
		ID = "sr.player.fps";
		Name = "FPS";

		Color = { 1, 0, 0, 1 };
		Pos = { 0, 10 };

		FPSText = Text("0", FONT_SMALL_DEV, Pos, 1, Color);
		FPSText.SetRectAlignment(HORIZONTAL_ALIGN_CENTER, VERTICAL_ALIGN_CENTER);
		FPSText.SetAlignment(HUDALIGN_CENTER, HUDALIGN_BOTTOM);
	}

	void FPS::OnDraw2D()
	{
		int FPS = Dvar::Find<int>("com_maxfps");
		Dvar::Set("com_maxfps", 500);

		FPSText.Value = std::to_string(FPS) + " FPS";
		FPSText.Render();
	}
}