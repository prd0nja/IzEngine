#pragma once
#include "ImGUI/Drawing/Window.hpp"

namespace IW3SR::Engine
{
	/// <summary>
	/// Widget class.
	/// </summary>
	class API Widget : public Window
	{
	public:
		/// <summary>
		/// Create widget.
		/// </summary>
		Widget();
		virtual ~Widget() = default;

		/// <summary>
		/// Begin drawing.
		/// </summary>
		/// <param name="flags">Window flags.</param>
		void Begin(ImGuiWindowFlags flags = 0) override;
	};
}
