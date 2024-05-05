#include "Device.hpp"
#include "ImGUI/UI.hpp"

namespace IzEngine
{
	void Device::Initialize()
	{
		IZ_ASSERT(OSWindow::Handle, "Device needs a main window.");

		D3D = Direct3DCreate9(D3D_SDK_VERSION);

		D3DPRESENT_PARAMETERS d3dpp = { 0 };
		d3dpp.Windowed = true;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
		d3dpp.BackBufferCount = 1;
		d3dpp.BackBufferWidth = 2560;
		d3dpp.BackBufferHeight = 1440;

		D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, reinterpret_cast<HWND>(OSWindow::Handle),
			D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &D3Device);

		CreateScreen();
	}

	void Device::Shutdown()
	{
		if (D3Device)
			D3Device->Release();
		if (D3D)
			D3D->Release();
	}

	void Device::CreateScreen()
	{
		D3DVIEWPORT9 viewport;
		D3Device->GetViewport(&viewport);
		D3DDISPLAYMODE displayMode;
		D3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);

		const vec2 position(viewport.X, viewport.Y);
		const vec2 size(viewport.Width, viewport.Height);
		const vec2 display(displayMode.Width, displayMode.Height);

		UI::Get().CreateScreen(position, size, display);
	}

	void Device::Swap(IDirect3D9* d3d, IDirect3DDevice9* device)
	{
		D3D = d3d;
		D3Device = device;
	}
}
