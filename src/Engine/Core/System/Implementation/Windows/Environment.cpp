#include "Windows/Base.hpp"

#include "Core/System/Environment.hpp"

#include <fstream>

namespace IzEngine
{
	void Environment::Binary()
	{
		TCHAR buffer[MAX_PATH];
		GetModuleFileName(nullptr, buffer, MAX_PATH);
		BaseDirectory = std::filesystem::path(buffer).parent_path();
		Initialize();
	}

	void Environment::Local()
	{
		BaseDirectory = std::filesystem::path(getenv("LOCALAPPDATA"));
		Initialize();
	}

	void Environment::Initialize()
	{
		AppDirectory = BaseDirectory / APPLICATION_ID;
		PluginsDirectory = AppDirectory / "plugins";
		ResourcesDirectory = AppDirectory / "resources";
		ReportsDirectory = AppDirectory / "reports";
		FontsDirectory = ResourcesDirectory / "fonts";
		ImagesDirectory = ResourcesDirectory / "images";

		std::filesystem::create_directory(AppDirectory);
		std::filesystem::create_directory(PluginsDirectory);
		std::filesystem::create_directory(ResourcesDirectory);
		std::filesystem::create_directory(ReportsDirectory);
		std::filesystem::create_directory(FontsDirectory);
		std::filesystem::create_directory(ImagesDirectory);

		Initialized = true;
	}

	void Environment::Load(nlohmann::json& json, const std::string& filename)
	{
		std::ifstream file(Environment::AppDirectory / filename);
		if (file.peek() != std::ifstream::traits_type::eof())
			json = nlohmann::json::parse(file);
	}

	void Environment::Save(const nlohmann::json& json, const std::string& filename)
	{
		std::ofstream file(Environment::AppDirectory / filename);
		file << json.dump(4);
	}
}
