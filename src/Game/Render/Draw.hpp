#pragma once
#include "Game/Definitions.hpp"
#include <glm/glm.hpp>

namespace IW3SR
{
	/// <summary>
	/// Drawing class.
	/// </summary>
	class Draw
	{
	public:
		/// <summary>
		/// Draw a line.
		/// </summary>
		/// <param name="start">Point A.</param>
		/// <param name="end">Point B.</param>
		/// <param name="color">Line color.</param>
		/// <param name="depthTest">Depth test.</param>
		/// <param name="verts">The verts.</param>
		static int Line(glm::vec3 start, glm::vec3 end, glm::vec4 color, bool depthTest,
			std::vector<GfxPointVertex> verts);
	};
}
