#include "Environment.hpp"
#include "Game/Definitions.hpp"

#include <Windows.h>

namespace IW3SR
{
	void Environment::Build()
	{
		BuildProcessPath();
		IW3SRDirectory = BaseDirectory / "iw3sr";
		ModulesDirectory = IW3SRDirectory / "modules";
		PluginsDirectory = IW3SRDirectory / "plugins";
		ResourcesDirectory = IW3SRDirectory / "resources";
		FontsDirectory = ResourcesDirectory / "fonts";
		ImagesDirectory = ResourcesDirectory / "images";
	}

	void Environment::BuildProcessPath()
	{
		TCHAR buffer[MAX_PATH];
		DWORD bufferLength = GetModuleFileName(NULL, buffer, MAX_PATH);
		BaseDirectory = std::filesystem::path(buffer).parent_path();
	}
}
