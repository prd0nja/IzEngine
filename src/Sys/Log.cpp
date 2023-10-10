#include "Log.hpp"
#include "Game/Game.hpp"

namespace IW3SR
{
	Log::Log()
	{
		Com_PrintMessage_h.Install();
	}

	void Log::Write(int channel, int type, std::string msg)
	{
		Write(channel, msg.c_str(), type);
	}

	void Log::Write(int channel, const char* msg, int type)
	{
		std::cout << msg;
		Com_PrintMessage_h(channel, msg, type);
	}
}
