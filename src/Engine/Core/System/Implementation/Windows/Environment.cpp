#include "Windows/Base.hpp"

#include "Core/System/Environment.hpp"

#include <fstream>

namespace IzEngine
{
	void Environment::Binary()
	{
		TCHAR buffer[MAX_PATH];
		GetModuleFileName(nullptr, buffer, MAX_PATH);
		Directories.insert({ Directory::Base, std::filesystem::path(buffer).parent_path() });
		Initialize();
	}

	void Environment::Local()
	{
		Directories.insert({ Directory::Base, std::filesystem::path(getenv("LOCALAPPDATA")) });
		Initialize();
	}

	void Environment::Initialize()
	{
		Directories.insert({ Directory::App, Directories[Directory::Base] / APPLICATION_ID });
		Directories.insert({ Directory::Plugins, Directories[Directory::App] / "plugins" });
		Directories.insert({ Directory::Resources, Directories[Directory::App] / "resources" });
		Directories.insert({ Directory::Reports, Directories[Directory::App] / "reports" });
		Directories.insert({ Directory::Fonts, Directories[Directory::Resources] / "fonts" });
		Directories.insert({ Directory::Images, Directories[Directory::Resources] / "images" });

		for (const auto& [_, path] : Directories)
			std::filesystem::create_directory(path);

		Initialized = true;
	}

	void Environment::Load(nlohmann::json& json, const std::string& filename)
	{
		IZ_ASSERT(Environment::Initialized, "Environment not initialized.");

		std::ifstream file(Path(Directory::App) / filename);
		if (file.is_open() && file.peek() != std::ifstream::traits_type::eof())
			json = nlohmann::json::parse(file);
	}

	void Environment::Save(const nlohmann::json& json, const std::string& filename)
	{
		IZ_ASSERT(Environment::Initialized, "Environment not initialized.");

		std::ofstream file(Path(Directory::App) / filename);
		file << json.dump(4);
	}

	const std::filesystem::path& Environment::Path(Directory directory)
	{
		IZ_ASSERT(Environment::Initialized, "Environment not initialized.");

		return Directories[directory];
	}
}
