#include "Core/Console/Console.hpp"
#include "Core/System/Crash.hpp"
#include "Core/System/Environment.hpp"
#include "Core/System/System.hpp"
#include "Core/System/Window.hpp"

#include "DX9/Common.hpp"
#include "ImGUI/Common.hpp"
#include "Renderer/Common.hpp"

void Application::Start()
{
	Crash::Setup();
	Environment::Binary();

	Console::Initialize("IzEngine");
	Window::Initialize("IzEngine");
	Device::Initialize();
	Renderer::Initialize();

	UI::Open = true;
	UI::Frames["Memory"]->Open = true;

	while (Window::Open)
	{
		Window::Frame();
		Renderer::Frame();
	}
	Shutdown();
}

void Application::Shutdown()
{
	Renderer::Shutdown();
	Device::Shutdown();
	Window::Shutdown();
	Console::Shutdown();
}

void Application::Dispatch(Event& event)
{
	UI::Dispatch(event);
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	Application::Start();
	return 0;
}
