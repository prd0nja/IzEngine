#pragma once
#include "Core/Memory/Function.hpp"

#include <string>

namespace IzEngine
{
	class Plugin : public IObject
	{
	public:
		void* Instance = nullptr;
		std::string FilePath;
		bool Loaded = false;
		bool Active = false;

		static const char* Extension;

		Plugin() = default;
		Plugin(std::string filePath);
		virtual ~Plugin();

		void Initialize();
		void Shutdown();

	private:
		Function<void()> CallbackInitialize;
		Function<void()> CallbackShutdown;
	};
}
