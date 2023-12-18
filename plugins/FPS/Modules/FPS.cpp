#include "FPS.hpp"

namespace IW3SR
{
	FPS::FPS() : Module("sr.player.fps", "FPS", "Player")
	{
		FPSText = Text("0", "Arial", 0, 20, 1.4, { 1, 1, 1, 1 });
		FPSText.SetRectAlignment(HORIZONTAL_ALIGN_CENTER, VERTICAL_ALIGN_TOP);
		FPSText.SetAlignment(HUDALIGN_CENTER, HUDALIGN_BOTTOM);

		DrawFpsPlot = false;
	}

	void FPS::OnMenu()
	{	
		ImGui::Checkbox("Draw FPS plot", &DrawFpsPlot);
		FPSText.Menu("Text", true);
	}

	void FPS::OnFrame()
	{
		const int FPS = Dvar::Get<int>("com_maxfps");
		FPSText.Value = std::to_string(FPS);
		FPSText.Render();

		if (!DrawFpsPlot)
			return;

		static std::vector<int> fps, samples;
		fps.push_back(FPS);
		samples.push_back(clients->serverTime);//do not use server time

		if (ImPlot::BeginPlot("FPS"))
		{
			ImPlot::SetupAxis(ImAxis_X1, "Frame number", ImPlotAxisFlags_AutoFit);
		    ImPlot::SetupAxis(ImAxis_Y1, "Frame time");
			ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1000);
			ImPlot::PlotLine("Frame rate", samples.data(), fps.data(), fps.size());
			ImPlot::EndPlot();
		}
	}
}