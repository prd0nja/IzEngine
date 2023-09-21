#include "Log.hpp"
#include "Game/Game.hpp"

void Com_PrintMessage2(int channel, const char* msg, int type);

namespace IW3SR
{
	Log::Log()
	{
		Sleep(2000);
		// @TODO member variable not updated after Remove()
		Com_PrintMessage_h = Hook<Com_PrintMessage_t>(0x4FCA50, Com_PrintMessage);
		Com_PrintMessage2_h = Hook<Com_PrintMessage_t>(0x4FCA50, Com_PrintMessage2);
		//Com_PrintMessage_h.Remove();
	}

	void Log::Write(int channel, int type, std::string text)
	{
		std::cout << text;
	}
}

void Com_PrintMessage(int channel, const char* msg, int type)
{
	std::cout << "[A] " << msg;
	//SR->Log->Write(channel, type, msg);
	SR->Log->Com_PrintMessage_h.Call(channel, msg, type);
}

void Com_PrintMessage2(int channel, const char* msg, int type)
{
	std::cout << "[B] " << msg;
	//SR->Log->Write(channel, type, msg);
	SR->Log->Com_PrintMessage2_h.Call(channel, msg, type);
}
