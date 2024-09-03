#include "Widget.hpp"

namespace IzEngine
{
	Widget::Widget() : Window(UUID())
	{
		SetRect(20, 100, 200, 100);
		SetRectAlignment(HORIZONTAL_LEFT, VERTICAL_TOP);
		SetDesigner(true);
		SetFlags(ImGuiWindowFlags_Widget);
	}

	void Widget::Begin()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });
		Window::Begin();
		ImGui::PopStyleVar();
	}
}
