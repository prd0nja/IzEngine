#pragma once
#include "ImGUI/Drawing/Frame.hpp"

namespace IzEngine
{
	/// <summary>
	/// Widget class.
	/// </summary>
	class API Widget : public Frame
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
		void Begin() override;
	};
}
