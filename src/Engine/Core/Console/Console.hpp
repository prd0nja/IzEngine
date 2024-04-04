#pragma once
#include <string>

namespace IW3SR::Engine
{
	/// <summary>
	/// Console class.
	/// </summary>
	class Console
	{
	public:
		static inline void* Handle = nullptr;
		static inline void* OutputHandle = nullptr;
		static inline int Mode = 0;

		/// <summary>
		/// Initialize the console.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Shutdown the console.
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// Set the console title.
		/// </summary>
		/// <param name="title">The title.</param>
		static void SetTile(const std::string& title);
	};
}
