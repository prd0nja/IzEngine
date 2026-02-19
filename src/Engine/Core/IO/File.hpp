#pragma once
#include "Engine/Base.hpp"

namespace IzEngine
{
	class API File
	{
	public:
		std::filesystem::path Path;
		std::vector<uint8_t> Data;

		bool IsValid() const;
	};
}
