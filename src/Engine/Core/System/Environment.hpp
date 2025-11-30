#pragma once
#include "Engine/Base.hpp"

#include "Core/Interfaces/ISerializable.hpp"

#include <filesystem>
#include <string>
#include <unordered_map>

namespace IzEngine
{
	/// <summary>
	/// Environment directories.
	/// </summary>
	enum class Directory
	{
		Base,
		App,
		Plugins,
		Resources,
		Reports,
		Fonts,
		Images,
	};

	/// <summary>
	/// System environment.
	/// </summary>
	class API Environment
	{
	public:
		static inline bool Initialized = false;

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

		/// <summary>
		/// Get path.
		/// </summary>
		/// <param name="directory">The directory.</param>
		/// <returns></returns>
		static const std::filesystem::path& Path(Directory directory);

	private:
		static inline std::unordered_map<Directory, std::filesystem::path> Directories;

		/// <summary>
		/// Initialize the environment.
		/// </summary>
		static void Initialize();
	};
}
