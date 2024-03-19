#pragma once
#include "ImGUI/Drawing/Widget.hpp"

namespace IW3SR::Engine
{
	/// <summary>
	/// Plots drawing.
	/// </summary>
	class API Plots : public Widget
	{
	public:
		/// <summary>
		/// Create plots.
		/// </summary>
		Plots();
		virtual ~Plots() = default;
	};
}
