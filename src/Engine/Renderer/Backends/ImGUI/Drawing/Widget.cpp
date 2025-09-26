#include "Widget.hpp"

namespace IzEngine
{
	Widget::Widget()
	{
		SetRect(20, 100, 200, 100);
		SetRectAlignment(HORIZONTAL_LEFT, VERTICAL_TOP);
		SetDesigner(true);
		SetFlags(ImGuiWindowFlags_Widget);
	}

	void Widget::Begin()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });
		Frame::Begin();
		ImGui::PopStyleVar();
	}
}
