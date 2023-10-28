#include "Sys/DLL.hpp"

#include "Modules/Modules.hpp"
#include "Modules/ESP.hpp"

namespace IW3SR
{
	PLUGIN void Initialize(DLL* entry)
	{
		entry->ID = "sr.private";
		entry->Name = "Private";

		Modules::Load<ESP>();
	}

	PLUGIN void GUI()
	{
		ImGui::SetCurrentContext(GUI::Context);
		ImGui::SetAllocatorFunctions(GUI::Allocator, GUI::Free, GUI::Data);
	}

	PLUGIN void Shutdown() { }
}
