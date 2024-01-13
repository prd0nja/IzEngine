#include "Texture.hpp"

namespace IW3SR
{
	void Texture::Reset()
	{
		Base->Release();
		BaseSurface->Release();
	}
}
