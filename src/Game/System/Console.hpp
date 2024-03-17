#pragma once
#include "Game/Base.hpp"

namespace IW3SR::Game
{
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

	/// <summary>
	/// Console class.
	/// </summary>
	class Console
	{
	public:
		/// <summary>
		/// Initialize the console.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Release the console.
		/// </summary>
		static void Release();

		/// <summary>
		/// Write to the console.
		/// </summary>
		/// <param name="channel">The channel.</param>
		/// <param name="msg">The message.</param>
		/// <param name="type">The messsage type.</param>
		static void Write(ConChannel channel, const char* msg, int type);

		/// <summary>
		/// Execute single command.
		/// </summary>
		/// <param name="localClientNum">The local client number.</param>
		/// <param name="controllerIndex">The controller index.</param>
		/// <param name="command">The command.</param>
		static void ExecuteSingleCommand(int localClientNum, int controllerIndex, char* command);

	private:
		/// <summary>
		/// Converts Q3 colors to ANSI.
		/// </summary>
		/// <param name="msg">The message.</param>
		/// <returns></returns>
		static std::string Q3(const std::string& msg);
	};
}
