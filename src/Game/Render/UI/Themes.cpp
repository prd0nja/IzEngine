#include "Themes.hpp"

namespace IW3SR
{
	Themes::Themes() : Window("Themes") { }
	
	void Themes::Frame() 
	{
		if (!Open) return;

		Begin();
		ImGui::ShowStyleEditor();
		End();
	}
}
