#include "GUI.hpp"
#include "Game/Sys/Sys.hpp"

#include "Engine/Backends/DX9/Device.hpp"

namespace IW3SR::Game
{
	GUI::GUI() : UI(UI::Get())
	{
		OpenKey = KeyListener(VK_F10);

		About = UC::About();
		Binds = UC::Binds();
		Modules = UC::Modules();
		Settings = UC::Settings();
		Toolbar = UC::Toolbar();

		Environment::Deserialize("GUI", *this);
	}

	void GUI::Initialize()
	{
		UI.Initialize();
	}

	void GUI::Release()
	{
		UI.Release();
		Environment::Serialize("GUI", *this);
	}

	void GUI::Render()
	{
		if (OpenKey.IsPressed())
			UI.Open = !UI.Open;

		if (!UI.Open) 
			return;

		Toolbar.Render();
		Binds.Render();
		Modules.Render();
		Settings.Render();
		About.Render();

		UI.Memory.Render();
		UI.Themes.Render();
	}
}
