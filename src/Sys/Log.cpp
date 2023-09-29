#include "Log.hpp"
#include "Game/Game.hpp"

namespace IW3SR
{
	Log::Log()
	{
		Com_PrintMessage_h.Install();
	}

	void Log::Write(int channel, int type, std::string text)
	{
		std::cout << text;
	}
}
