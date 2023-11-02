#include "KeyListener.hpp"

namespace IW3SR
{
	KeyListener::KeyListener(int vk)
	{
		Key = vk;
	}

	KeyListener::KeyListener(int vk, int delay)
	{
		Key = vk;
		Delay = delay;
	}

	bool KeyListener::IsPressed()
	{
		bool pressed = GetAsyncKeyState(Key) & 0x8000;
		if (!Delay) return pressed;

		int time = timeGetTime();
		if (LastTime + Delay >= time)
			return false;
		LastTime = timeGetTime();
		return pressed;
	}
}
