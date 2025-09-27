#include "Plugins.hpp"

#include "Core/System/Environment.hpp"

namespace IzEngine
{
	void Plugins::Initialize()
	{
		for (const auto& entry : std::filesystem::directory_iterator(Environment::Path(Directory::Plugins)))
		{
			if (entry.path().extension() != Plugin::Extension)
				continue;

			auto mod = CreateScope<Plugin>(entry.path().string());
			if (!mod->Loaded)
				continue;

			Modules.insert({ entry.path().filename().string(), std::move(mod) });
		}
	}

	void Plugins::Shutdown()
	{
		Modules.clear();
	}
}
