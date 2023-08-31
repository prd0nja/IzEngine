#include "Log.hpp"
#include "Game/Game.hpp"

namespace IW3SR
{
	Log::Log()
	{
		Com_PrintMessage_h = Hook<Com_PrintMessage_t>(0x4FCA50, Com_PrintMessage);
	}

	void Log::Write(int channel, int type, std::string text)
	{
		std::cout << text;
		Com_PrintMessage_h.Call(channel, text.c_str(), type);
	}
}

void Com_PrintMessage(int channel, const char* msg, int type)
{
	SR->Log->Write(channel, type, msg);
}
