#include "System.hpp"

namespace IW3SR::Game
{
	HWND System::CreateMainWindow(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y,
		int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
	{
		HWND hwnd = CreateWindowExA_h(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
			hMenu, hInstance, lpParam);

		std::string windowName = std::string{ lpWindowName };
		if (windowName != "Call of Duty 4" && windowName != "Call of Duty 4 X")
			return hwnd;

		return reinterpret_cast<HWND>(Engine::System::MainWindow = hwnd);
	}

	LRESULT System::MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		auto& UI = UI::Get();
		KeyListener::Process(Msg, wParam, lParam);

		if (!UI.Active)
			return MainWndProc_h(hWnd, Msg, wParam, lParam);

		ImGuiIO& io = ImGui::GetIO();
		if (UI.Open)
		{
			if (KeyListener::IsPressed(VK_ESCAPE))
				UI.Open = false;
			ImGui_ImplWin32_WndProcHandler(hWnd, Msg, wParam, lParam);
			io.MouseDrawCursor = true;
			return true;
		}
		io.MouseDrawCursor = false;
		return MainWndProc_h(hWnd, Msg, wParam, lParam);
	}
}
