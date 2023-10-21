#include "Modules.hpp"
#include "Modules/Sys/Console.hpp"
#include "Modules/Player/ESP.hpp"
#include "Modules/Player/FPS.hpp"
#include "Modules/Player/Velocity.hpp"

#include "Sys/Environment.hpp"

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
		std::fstream file(Environment::IW3SRDirectory / "modules.json", std::ios::in | std::ios::out | std::ios::app);
		if (file.peek() != std::ifstream::traits_type::eof())
			Serialized = nlohmann::json::parse(file);
	}

	void Modules::Serialize()
	{
		nlohmann::json json;
		for (const auto& [_, entry] : Entries)
			entry->Serialize(json[entry->ID]);

		std::ofstream file(Environment::IW3SRDirectory / "modules.json");
		file << json.dump(4);
		file.close();
	}
}
