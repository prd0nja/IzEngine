#pragma once
#include "Plugin.hpp"

namespace IW3SR::Engine
{
	/// <summary>
	/// Plugins class.
	/// </summary>
	class Plugins
	{
	public:
		static inline std::map<std::string, std::unique_ptr<Plugin>> Modules;
		static inline bool IsReloading = false;

		/// <summary>
		/// Initialize the plugins.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// On renderer initialize.
		/// </summary>
		static void Renderer();

		/// <summary>
		/// Shutdown the plugins.
		/// </summary>
		static void Shutdown();
	};
}
