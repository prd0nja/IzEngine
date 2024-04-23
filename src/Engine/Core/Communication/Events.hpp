#pragma once
#include "Event.hpp"

namespace IzEngine
{
	class EventPluginInitialize : public Event
	{
		EVENT_CLASS("plugin.initialize")
		EventPluginInitialize() = default;
	};

	class EventConsoleCommand : public Event
	{
		EVENT_CLASS("console.command")
		EventConsoleCommand(std::string command) : command(command) { }
		std::string command;
	};
}
