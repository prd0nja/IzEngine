#pragma once
#include "Game/Definitions.hpp"
#include "Utils/Math.hpp"

#include <vector>

namespace IW3SR
{
	/// <summary>
	/// Rendering class.
	/// </summary>
	class Render
	{
	public:
		/// <summary>
		/// Initialize the rendering class.
		/// </summary>
		Render();
		~Render() = default;
		
		/// <summary>
		/// Draw 3D.
		/// </summary>
		void Draw3D();

		/// <summary>
		/// Draw 2D.
		/// </summary>
		/// <param name="scoreboard">Scoreboard visible.</param>
		void Draw2D(bool scoreboard);

		/// <summary>
		/// Render frame.
		/// </summary>
		void Frame();
	};
}
