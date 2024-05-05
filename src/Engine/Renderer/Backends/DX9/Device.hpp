#pragma once
#include "DX9/Base.hpp"

#include "Core/System/Window.hpp"

namespace IzEngine
{
	/// <summary>
	/// Graphics device.
	/// </summary>
	class API Device
	{
	public:
		static inline IDirect3D9* D3D = nullptr;
		static inline IDirect3DDevice9* D3Device = nullptr;

		/// <summary>
		/// Initialize the device.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Shutdown the device.
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// Create the screen.
		/// </summary>
		static void CreateScreen();

		/// <summary>
		/// Swap pointers.
		/// </summary>
		/// <param name="d3d">The instance.</param>
		/// <param name="device">The device.</param>
		static void Swap(IDirect3D9* d3d, IDirect3DDevice9* device);
	};
}
