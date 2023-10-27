#include "Assets.hpp"

#include <d3dx9.h>

namespace IW3SR
{
	void Assets::Initialize()
	{
		std::cout << "[Assets]: Initialize." << std::endl;
	}

	void Assets::Shutdown()
	{
		std::cout << "[Assets]: Shutdown." << std::endl;

		Images.clear();
	}

	IDirect3DTexture9* Assets::LoadTexture(const std::filesystem::path& filePath, UINT width, UINT height)
	{
		if (!std::filesystem::exists(filePath))
			throw std::runtime_error("Couldn't find texture path.");

		IDirect3DTexture9* texture = nullptr;
		D3DXCreateTextureFromFileExA(dx->device, filePath.string().c_str(),
			width, height, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT,
			D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture);

		Images.insert({ filePath.filename().string(), texture });

		return texture;
	}
}