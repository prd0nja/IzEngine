#pragma once
#include "Sys/Hook.hpp"

// @TODO Move to Game/Definitions.hpp
#define C_EXTERN extern "C"
using namespace IW3SR;
typedef void (*Com_PrintMessage_t)(int channel, const char* msg, int type);
C_EXTERN
{
	void Com_PrintMessage(int channel, const char* msg, int type);
}

namespace IW3SR
{
	/// <summary>
	/// Log class.
	/// </summary>
	class Log
	{
	public:
		static inline Hook<Com_PrintMessage_t> Com_PrintMessage_h;

		/// <summary>
		/// Initialize a new logger.
		/// </summary>
		Log();

		/// <summary>
		/// Release logger.
		/// </summary>
		~Log() = default;
	};
}
