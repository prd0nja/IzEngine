#include "Windows/Base.hpp"

#include "Core/Input/Input.hpp"
#include "Core/Input/Mouse.hpp"
#include "Core/System/Window.hpp"

namespace IzEngine
{
	void Mouse::Register()
	{
		IZ_ASSERT(Window::Handle, "Window is not initialized.");

		RAWINPUTDEVICE rid;
		rid.usUsagePage = 0x01;
		rid.usUsage = 0x02;
		rid.dwFlags = 0;
		rid.hwndTarget = reinterpret_cast<HWND>(Window::Handle);

		if (!RegisterRawInputDevices(&rid, 1, sizeof(rid)))
			Log::WriteLine(Channel::Error, "Failed to register raw input device.");
	}

	void Mouse::Process(uint64_t msg, uint64_t state)
	{
		IZ_ASSERT(Window::Handle, "Window is not initialized.");

		if (msg == WM_INPUT)
		{
			HWND hWnd = reinterpret_cast<HWND>(Window::Handle);
			HRAWINPUT hRaw = reinterpret_cast<HRAWINPUT>(state);
			RAWINPUT raw = { 0 };
			UINT size = 0;

			if (GetRawInputData(hRaw, RID_INPUT, nullptr, &size, sizeof(RAWINPUTHEADER)) == -1)
				return;
			if (size > sizeof(RAWINPUT))
				return;
			if (GetRawInputData(hRaw, RID_INPUT, &raw, &size, sizeof(RAWINPUTHEADER)) != size)
				return;
			if (raw.header.dwType != RIM_TYPEMOUSE)
				return;

			Delta = vec2(raw.data.mouse.lLastX, raw.data.mouse.lLastY);
			AccumulatedDelta.x += Delta.x;
			AccumulatedDelta.y += Delta.y;

			POINT position;
			GetCursorPos(&position);
			ScreenToClient(hWnd, &position);
			Position = vec2(position.x, position.y);

			if (raw.data.mouse.usButtonFlags & RI_MOUSE_BUTTON_1_DOWN)
				Input::Inputs[Button_Left].State = INPUT_DOWN;
			if (raw.data.mouse.usButtonFlags & RI_MOUSE_BUTTON_1_UP)
				Input::Inputs[Button_Left].State = INPUT_UP;
			if (raw.data.mouse.usButtonFlags & RI_MOUSE_BUTTON_2_DOWN)
				Input::Inputs[Button_Right].State = INPUT_DOWN;
			if (raw.data.mouse.usButtonFlags & RI_MOUSE_BUTTON_2_UP)
				Input::Inputs[Button_Right].State = INPUT_UP;
			if (raw.data.mouse.usButtonFlags & RI_MOUSE_BUTTON_3_DOWN)
				Input::Inputs[Button_Middle].State = INPUT_DOWN;
			if (raw.data.mouse.usButtonFlags & RI_MOUSE_BUTTON_3_UP)
				Input::Inputs[Button_Middle].State = INPUT_UP;
		}
	}
}
