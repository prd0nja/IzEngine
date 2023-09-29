#pragma once
#include "Game/Definitions.hpp"

#include <glm/glm.hpp>
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
		/// Render frame.
		/// </summary>
		void Frame();
	};
}
