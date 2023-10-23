#pragma once
#include "Game/Definitions.hpp"
#include "Utils/Math.hpp"

#include "Sys/Fonts/IconsFontAwesome6.hpp"
#include "Sys/Fonts/IconsFontAwesome6Brands.hpp"

#include <nlohmann/json.hpp>

namespace ImGui
{
	/// <summary>
	/// Create a button with a specific id.
	/// </summary>
	/// <param name="label">The button label.</param>
	/// <param name="id">The unique id.</param>
	/// <param name="v">Toggle state.</param>
	/// <param name="size">The button size.</param>
	/// <returns></returns>
	bool ButtonId(const std::string& label, const std::string& id, bool* v, const ImVec2& size = ImVec2(0, 0));

	/// <summary>
	/// Toggle button.
	/// </summary>
	/// <param name="id">The ID.</param>
	/// <param name="v">Toggle state.</param>
	/// <return></returns>
	bool ToggleButton(const std::string& id, float size, bool* v);
}
