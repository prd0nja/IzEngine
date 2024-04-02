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

	void System::ExecuteSingleCommand(int localClientNum, int controllerIndex, char* command)
	{
		if (std::string(command) == "openscriptmenu cj load")
		{
			EventPlayerLoadPosition event;
			Application::Get().Dispatch(event);
		}
		Cmd_ExecuteSingleCommand_h(localClientNum, controllerIndex, command);
	}

	void System::ScriptMenuResponse(int localClientNum, itemDef_s* item, const char** args) 
	{ 
		Script_ScriptMenuResponse_h(localClientNum, item, args);

		std::string command;
		EventScriptMenuResponse event(item->parent->window.name, command);
		Application::Get().Dispatch(event);

		// Log::WriteLine(Channel::Game, "Response: {} {}", item->parent->window.name, command);
	}
}
