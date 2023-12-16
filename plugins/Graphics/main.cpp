#include "Game/Sys/Features.hpp"
#include "Features/Graphics.hpp"
#include "Sys/Modules/DLL.hpp"
#include "Game/Render/GUI.hpp"

PLUGIN void Initialize(DLL* entry)
{
	entry->SetInfos("sr.feature.graphics", "Graphics");

	Features::Load<Graphics>();
}

PLUGIN void GUI()
{
	GUI::ModuleContext();
}

PLUGIN void Shutdown()
{
	Features::Remove("sr.feature.graphics");
}
