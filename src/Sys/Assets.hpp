#pragma once
#include "Game/Game.hpp"

namespace IW3SR
{
	class Assets
	{
	public:
		static inline std::map<std::string, IDirect3DTexture9*> Images;

		/// <summary>
		/// Initialize.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Shutdown.
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// Loads texture from directx.
		/// </summary>
		/// <param name="filePath">The file path.</param>
		/// <param name="width">The texture width.</param>
		/// <param name="height">The texture height.</param>
		static IDirect3DTexture9* LoadTexture(const std::filesystem::path& filePath, UINT width, UINT height);
	};
}