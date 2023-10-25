#pragma once
#include <nlohmann/json.hpp>
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
		static inline nlohmann::json Settings;
		static inline std::filesystem::path BaseDirectory;
		static inline std::filesystem::path IW3SRDirectory;
		static inline std::filesystem::path PluginsDirectory;
		static inline std::filesystem::path ResourcesDirectory;
		static inline std::filesystem::path FontsDirectory;
		static inline std::filesystem::path ImagesDirectory;

		/// <summary>
		/// Load the environment.
		/// </summary>
		static void Load();

		/// <summary>
		/// Save environment.
		/// </summary>
		static void Save();

		/// <summary>
		/// Deserialize settings.
		/// </summary>
		static void Deserialize();

		/// <summary>
		/// Get the settings.
		/// </summary>
		/// <typeparam name="T">The class implementing serialization.</typeparam>
		/// <param name="id">The settings id.</param>
		/// <param name="instance">The class instance.</param>
		template <typename T>
		static void GetSettings(const std::string& id, T& instance)
		{
			if (Settings.contains(id))
				nlohmann::from_json(Settings[id], instance);
		}

		/// <summary>
		/// Set the settings.
		/// </summary>
		/// <typeparam name="T">The class implementing serialization.</typeparam>
		/// <param name="id">The settings id.</param>
		/// <param name="instance">The class instance.</param>
		template <typename T>
		static void SetSettings(const std::string& id, const T& instance)
		{
			nlohmann::to_json(Settings[id], instance);
		}
	};
}
