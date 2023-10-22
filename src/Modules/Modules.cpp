#include "Modules.hpp"
#include "Modules/Sys/Console.hpp"
#include "Modules/Player/ESP.hpp"
#include "Modules/Player/FPS.hpp"
#include "Modules/Player/Velocity.hpp"

namespace IW3SR
{
	Modules::Modules()
	{
		Deserialize();
	}

	Modules::~Modules()
	{
		Serialize();
	}

	void Modules::Initialize()
	{
		Load<Console>();
		Load<ESP>();
		Load<FPS>();
		Load<Velocity>();
		LoadDynamic();
	}

	void Modules::LoadDynamic()
	{

	}

	void Modules::Enable(const std::string& id)
	{
		auto entry = Entries.find(id);
		if (entry != Entries.end() && !entry->second->IsEnabled)
		{
			entry->second->IsEnabled = true;
			entry->second->Initialize();
		}
	}

	void Modules::Disable(const std::string& id)
	{
		auto entry = Entries.find(id);
		if (entry != Entries.end() && entry->second->IsEnabled)
		{
			entry->second->IsEnabled = false;
			entry->second->Shutdown();
		}
	}

	void Modules::Deserialize()
	{
		Environment::GetSettings("modules", *this);

		std::fstream file(Environment::IW3SRDirectory / "modules.json", std::ios::in | std::ios::out | std::ios::app);
		if (file.peek() != std::ifstream::traits_type::eof())
			Serialized = nlohmann::json::parse(file);
	}

	void Modules::Serialize()
	{
		Environment::SetSettings("modules", *this);

		for (const auto& [_, entry] : Entries)
			entry->Serialize(Serialized[entry->ID]);

		std::ofstream file(Environment::IW3SRDirectory / "modules.json");
		file << Serialized.dump(4);
		file.close();
	}

	void Modules::Frame()
	{
		if (!MenuOpen) return;

		vec2 menuPos = { -20, 20 };
		vec2 menuSize = { 200, 100 };
		ImGui::Begin("Modules", &MenuOpen);
		ImGui::SetWindowAlignment(menuPos, menuSize, HUDALIGN_RIGHT, HUDALIGN_TOP);
		ImGui::SetWindowVirtual(menuPos, menuSize, HORIZONTAL_ALIGN_RIGHT, VERTICAL_ALIGN_TOP);
		ImGui::SetWindowPos(menuPos, ImGuiCond_FirstUseEver);
		ImGui::SetWindowSize(menuSize, ImGuiCond_FirstUseEver);
		const float frameWidth = menuSize.x - 30;

		for (const auto& [_, entry] : Entries)
		{
			const char* name = entry->Name.c_str();

			// Enable/Disable module
			if (ImGui::ToggleButton(entry->ID + "toggle", 20, &entry->IsEnabled))
				entry->IsEnabled ? entry->Initialize() : entry->Shutdown();
			ImGui::SameLine();
			ImGui::Text(name);
			ImGui::SameLine(frameWidth);

			// Draw module menus
			ImGui::ButtonId(ICON_FA_GEAR, entry->ID + "menu", &entry->MenuOpen);
			if (entry->MenuOpen)
			{
				ImGui::Begin(name, &entry->MenuOpen);
				ImGui::SetWindowSize(entry->MenuSize ? entry->MenuSize : menuSize, ImGuiCond_FirstUseEver);
				ImGui::SetWindowPos(entry->MenuPosition ? entry->MenuPosition : menuPos, ImGuiCond_FirstUseEver);
				entry->MenuSize = ImGui::GetWindowSize();
				entry->MenuPosition = ImGui::GetWindowPos();
				entry->OnMenu();
				ImGui::End();
			}
		}
		ImGui::End();
	}
}
