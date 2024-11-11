#include "Windows/Base.hpp"

#include "Core/Input/Bind.hpp"
#include "Core/Input/Keyboard.hpp"
#include "Core/Input/Mouse.hpp"

namespace IzEngine
{
	Bind::Bind(int key)
	{
		Key = key;
	}

	bool Bind::IsUp()
	{
		return Keyboard::IsUp(Key);
	}

	bool Bind::IsDown()
	{
		return Keyboard::IsDown(Key);
	}

	bool Bind::IsPressed()
	{
		return Keyboard::IsPressed(Key);
	}
}
