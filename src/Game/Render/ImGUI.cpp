#include "ImGUI.hpp"

namespace ImGui
{
	bool ButtonId(const std::string& label, const std::string& id, const ImVec2& size)
	{
		ImGui::PushID(id.c_str());
		bool state = ImGui::Button(label.c_str(), size);
		ImGui::PopID();
		return state;
	}
}
