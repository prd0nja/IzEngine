#pragma once
#include "Game/Base.hpp"

namespace IW3SR::Game
{
	// clang-format off
	constexpr std::array<ConColor, 10> Q3Colors = {
		ConColor::Default,
		ConColor::Red,
		ConColor::Green,
		ConColor::Yellow,
		ConColor::Blue,
		ConColor::Cyan,
		ConColor::Magenta,
		ConColor::Default,
		ConColor::Default,
		ConColor::Default
	};
	// clang-format on

	/// <summary>
	/// Console class.
	/// </summary>
	class GConsole
	{
	public:
		/// <summary>
		/// Initialize the console.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Shutdown the console.
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// Write to the console.
		/// </summary>
		/// <param name="channel">The channel.</param>
		/// <param name="msg">The message.</param>
		/// <param name="type">The messsage type.</param>
		static void Write(ConChannel channel, const char* msg, int type);

	private:
		/// <summary>
		/// Converts Q3 colors to ANSI.
		/// </summary>
		/// <param name="msg">The message.</param>
		/// <returns></returns>
		static std::string Q3(const std::string& msg);
	};
}
