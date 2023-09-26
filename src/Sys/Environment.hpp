#pragma once
#include <filesystem>
#include <cstdlib>

namespace IW3SR
{
	/// <summary>
	/// System environment.
	/// </summary>
	class Environment
	{
	public:
		static inline std::filesystem::path BaseDirectory;
		static inline std::filesystem::path IW3SRDirectory;
		static inline std::filesystem::path PluginsDirectory;
		static inline std::filesystem::path RessourcesDirectory;
		static inline std::filesystem::path ModDirectory;

		/// <summary>
		/// Build the environment.
		/// </summary>
		static void Build();
	};
}
