#include "KeyListener.hpp"

namespace IW3SR
{
	KeyListener::KeyListener(int vk)
	{
		Key = vk;
	}

	bool KeyListener::IsDown()
	{
		return Keys[Key] == WM_KEYDOWN;
	}

	bool KeyListener::IsUp()
	{
		return Keys[Key] == WM_KEYUP;
	}

	void KeyListener::Process(UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		switch (Msg)
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			Keys[wParam] = WM_KEYDOWN;
			break;
		case WM_KEYUP:
		case WM_SYSKEYUP:
			Keys[wParam] = WM_KEYUP;
			break;
		}
	}

	void KeyListener::Reset()
	{
		Keys.clear();
	}
}
