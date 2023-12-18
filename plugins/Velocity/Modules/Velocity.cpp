#include "Velocity.hpp"
#include "Game/Game.hpp"

namespace IW3SR
{
	Velocity::Velocity() : Module("sr.player.velocity", "Velocity", "Player")
	{
		VelocityText = Text("0", "Arial", 0, 2, 1.4, { 0, 1, 1, 1 });
		VelocityText.SetRectAlignment(HORIZONTAL_ALIGN_CENTER, VERTICAL_ALIGN_TOP);
		VelocityText.SetAlignment(HUDALIGN_CENTER, HUDALIGN_BOTTOM);

		DrawVelocityPlot = false;
	}

	void Velocity::OnMenu()
	{
		ImGui::Checkbox("Draw velocity plot", &DrawVelocityPlot);
		VelocityText.Menu("Text", true);
	}

	void Velocity::OnFrame()
	{
		const int velocity = vec2(pmove->ps->velocity).Length();
		VelocityText.Value = std::to_string(velocity);
		VelocityText.Render();

		if (!DrawVelocityPlot)
			return;

		static std::vector<int> vel, samples;
		vel.push_back(velocity);
		samples.push_back(clients->serverTime);// do not use server time

		if (ImPlot::BeginPlot("Velocity"))
		{
			ImPlot::SetupAxis(ImAxis_X1, "Frame velocity", ImPlotAxisFlags_AutoFit);
			ImPlot::SetupAxis(ImAxis_Y1, "Frame time");
			ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 4000);
			ImPlot::PlotLine("Player speed", samples.data(), vel.data(), vel.size());
			ImPlot::EndPlot();
		}
	}
}
