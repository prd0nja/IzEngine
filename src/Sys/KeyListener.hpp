#pragma once
#include <Windows.h>

namespace IW3SR
{
	/// <summary>
	/// Key listener.
	/// </summary>
	class KeyListener
	{
	public:
		int Key = 0;
		int Delay = 0;
		int LastTime = 0;

		/// <summary>
		/// Initialize the KeyLister.
		/// </summary>
		/// <param name="vk">The vk code.</param>
		KeyListener(int vk);
		~KeyListener() = default;

		/// <summary>
		/// Initialize the KeyListener.
		/// </summary>
		/// <param name="vk">The vk code.</param>
		/// <param name="delay">The delay in ms.</param>
		KeyListener(int vk, int delay);

		/// <summary>
		/// Is key pressed.
		/// </summary>
		/// <returns></returns>
		bool IsPressed();
	};
}
