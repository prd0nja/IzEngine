#pragma once
#include "Plugin.hpp"

#include <string>
#include <unordered_map>

namespace IzEngine
{
	class Plugins
	{
	public:
		static inline std::unordered_map<std::string, Scope<Plugin>> Modules;
		static inline bool IsReloading = false;

		static void Load();
		static void Free();

		static void Initialize();
		static void Shutdown();
	};
}
