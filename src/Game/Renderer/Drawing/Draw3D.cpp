#include "Draw3D.hpp"

namespace IW3SR::Game
{
	void Draw3D::Box(const vec3& position, const vec3& size, const vec4& color)
    {
        BufferLines.AddBox(position, size, color);
    }

    void Draw3D::Line(const vec3& start, const vec3& end, const vec4& color)
    {
        BufferLines.Add(start, end, color);
    }

    void Draw3D::Render()
    {
        BufferLines.Render();
    }
}
