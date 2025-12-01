#pragma once
#include "Core/Common.hpp"

namespace IzEngine
{
	class API Keyboard
	{
	public:
		static void Register();
		static void Process(uint64_t msg, uint64_t input);
	};
}
