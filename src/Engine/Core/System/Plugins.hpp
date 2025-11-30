#pragma once
#include "Plugin.hpp"

#include <string>
#include <unordered_map>

namespace IzEngine
{
	/// <summary>
	/// Plugins class.
	/// </summary>
	class Plugins
	{
	public:
		static inline std::unordered_map<std::string, Scope<Plugin>> Modules;
		static inline bool IsReloading = false;

		/// <summary>
		/// Load the plugins.
		/// </summary>
		static void Load();

		/// <summary>
		/// Free the plugins.
		/// </summary>
		static void Free();

		/// <summary>
		/// Initialize the plugins.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Shutdown the plugins.
		/// </summary>
		static void Shutdown();
	};
}
