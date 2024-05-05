#pragma once
#include <string>

namespace IzEngine
{
	/// <summary>
	/// Window class.
	/// </summary>
	class OSWindow
	{
	public:
		static inline void* Handle = nullptr;
		static inline bool Open = false;

		/// <summary>
		/// Initialize window.
		/// </summary>
		/// <param name="name">The window name.</param>
		static void Initialize(const std::string& name);

		/// <summary>
		/// Shutdown window.
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// Window swap pointers.
		/// </summary>
		/// <param name="handle">The window handle.</param>
		static void Swap(void* handle);

		/// <summary>
		/// Update callback.
		/// </summary>
		/// <param name="handle">The handle.</param>
		/// <param name="msg">The message.</param>
		/// <param name="wParam">The w param.</param>
		/// <param name="lParam">The l param.</param>
		/// <returns></returns>
		static int Update(void* handle, int msg, int wParam, int lParam);

		/// <summary>
		/// Window frame.
		/// </summary>
		static void Frame();
	};
}
