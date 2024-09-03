#pragma once
#include "Core/Base.hpp"

namespace IzEngine
{
	/// <summary>
	/// System environment.
	/// </summary>
	class API Environment
	{
	public:
		static inline bool Initialized = false;

		static inline std::filesystem::path BaseDirectory;
		static inline std::filesystem::path AppDirectory;
		static inline std::filesystem::path PluginsDirectory;
		static inline std::filesystem::path ResourcesDirectory;
		static inline std::filesystem::path ReportsDirectory;
		static inline std::filesystem::path FontsDirectory;
		static inline std::filesystem::path ImagesDirectory;

		/// <summary>
		/// Environment binary directory.
		/// </summary>
		static void Binary();

		/// <summary>
		/// Environment local directory.
		/// </summary>
		static void Local();

		/// <summary>
		/// Load json file.
		/// </summary>
		/// <param name="json">The json data.</param>
		/// <param name="filename">The filename.</param>
		static void Load(nlohmann::json& json, const std::string& filename);

		/// <summary>
		/// Save json file.
		/// </summary>
		/// <param name="json">The json data.</param>
		/// <param name="filename">The filename.</param>
		static void Save(const nlohmann::json& json, const std::string& filename);

	private:
		/// <summary>
		/// Initialize the environment.
		/// </summary>
		static void Initialize();
	};
}
