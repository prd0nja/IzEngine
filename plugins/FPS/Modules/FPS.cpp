#include "FPS.hpp"

namespace IW3SR
{
	FPS::FPS() : Module("sr.player.fps", "FPS", "Player")
	{
		FPSText = Text("0", "Arial", 0, 20, 1.4, { 1, 1, 1, 1 });
		FPSText.SetRectAlignment(HORIZONTAL_ALIGN_CENTER, VERTICAL_ALIGN_TOP);
		FPSText.SetAlignment(HUDALIGN_CENTER, HUDALIGN_BOTTOM);
	}

	void FPS::OnMenu()
	{	
		FPSText.Menu("Text", true);
	}

	void FPS::OnFrame()
	{
		int FPS = Dvar::Get<int>("com_maxfps");
		FPSText.Value = std::to_string(FPS);
		FPSText.Render();
	}
}