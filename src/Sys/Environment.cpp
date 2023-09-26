#include "Environment.hpp"
#include "Game/Definitions.hpp"

namespace IW3SR
{
	void Environment::Build()
	{
		BaseDirectory = Dvar_FindVar("fs_basepath")->current.string;
		IW3SRDirectory = BaseDirectory / "iw3sr";
		PluginsDirectory = IW3SRDirectory / "plugins";
		RessourcesDirectory = IW3SRDirectory / "ressources";
		ModDirectory = BaseDirectory / Dvar_FindVar("fs_gameDir")->current.string;
	}
}
