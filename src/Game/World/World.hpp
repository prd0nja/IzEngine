#pragma once
#include "Game/Base.hpp"

namespace IW3SR::Game
{
	/// <summary>
	/// World class.
	/// </summary>
	class API World
	{
	public:
		/// <summary>
		/// Converts a 3D position to screen space.
		/// </summary>
		/// <param name="position">The 3D position.</param>
		/// <returns></returns>
		static vec2 ToScreen(const vec3& position);
	};
}
