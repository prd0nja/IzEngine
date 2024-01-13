#pragma once
#include "Engine/Backends/DX9.hpp"

namespace IW3SR
{
	/// <summary>
	/// Texture class.
	/// </summary>
	class API Texture
	{
	public:
		IDirect3DTexture9* Base;
		IDirect3DSurface9* BaseSurface;

		/// <summary>
		/// Initialize a new Texture.
		/// </summary>
		Texture() = default;
		~Texture() = default;

		/// <summary>
		/// Reset resources.
		/// </summary>
		void Reset();
	};
}
