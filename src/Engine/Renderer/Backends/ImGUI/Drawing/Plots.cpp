#include "Plots.hpp"

namespace IW3SR::Engine
{
	Plots::Plots()
	{
		SetRect(0, -100, 200, 100);
		SetRectAlignment(HORIZONTAL_LEFT, VERTICAL_BOTTOM);
		SetDesigner(true);
	}
}
