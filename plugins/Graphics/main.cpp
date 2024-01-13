#include "Game/Plugin.hpp"
#include "Features/General.hpp"

PLUGIN void Initialize(DLL* entry)
{
	entry->SetInfos("sr.feature.graphics", "Graphics");

	Features::Load<General>();
}

PLUGIN void GUI()
{
	GUI::ModuleContext();
}

PLUGIN void Shutdown()
{
	Features::Remove("sr.feature.graphics");
}
