#pragma once
#include "DX9/Base.hpp"

namespace IzEngine
{
	class API Device
	{
	public:
		static inline IDirect3D9* D3D = nullptr;
		static inline IDirect3DDevice9* D3Device = nullptr;
		static inline IDirect3D9Ex* D3DEX = nullptr;
		static inline IDirect3DDevice9Ex* D3DeviceEx = nullptr;
		static inline D3DPRESENT_PARAMETERS PresentParameters;

		static void Initialize();
		static void Swap(IDirect3D9* d3d, IDirect3DDevice9* device);
		static void Shutdown();

		static void Reset();
		static void Resize(const vec2& size);

		static void Begin();
		static void End();

	private:
		static inline bool Swapped = false;
	};
}
