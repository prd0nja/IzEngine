#include "ImGUI/UI.hpp"
#include "Windows/Base.hpp"

#include "Core/Input/Keyboard.hpp"
#include "Core/System/Window.hpp"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return OSWindow::Update(hWnd, uMsg, wParam, lParam);
}

namespace IzEngine
{
	void OSWindow::Initialize(const std::string& name)
	{
		HINSTANCE instance = GetModuleHandle(nullptr);
		const int width = 2560;
		const int height = 1440;

		WNDCLASS wc = { 0 };
		wc.lpfnWndProc = WndProc;
		wc.hInstance = instance;
		wc.lpszClassName = "WindowClass";
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		RegisterClass(&wc);

		HWND hwnd = CreateWindowEx(0, wc.lpszClassName, name.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			width, height, nullptr, nullptr, instance, nullptr);
		ShowWindow(hwnd, SW_SHOW);

		Handle = hwnd;
		Open = Handle;
	}

	void OSWindow::Shutdown()
	{
		if (Handle)
			DestroyWindow(reinterpret_cast<HWND>(Handle));
	}

	void OSWindow::Swap(void* handle)
	{
		Handle = handle;
		Open = Handle;
	}

	int OSWindow::Update(void* handle, int msg, int wParam, int lParam)
	{
		const HWND hwnd = reinterpret_cast<HWND>(handle);
		auto& UI = UI::Get();

		switch (msg)
		{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			Open = false;
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
			Keyboard::Process(msg, wParam);
			break;
		}
		if (!UI.Active)
			return DefWindowProc(hwnd, msg, wParam, lParam);

		ImGuiIO& io = ImGui::GetIO();
		if (UI.Open)
		{
			if (Keyboard::IsPressed(Key_Escape))
				UI.Open = false;

			io.MouseDrawCursor = true;
			ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);
			return true;
		}
		io.MouseDrawCursor = false;
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	void OSWindow::Frame()
	{
		MSG msg = { 0 };
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
