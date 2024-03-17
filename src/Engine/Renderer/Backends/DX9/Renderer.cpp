#include "Renderer/Common.hpp"

#include "Core/System/System.hpp"
#include "Core/System/Plugins.hpp"
#include "Device.hpp"

namespace IW3SR::Engine
{
	void Renderer::Initialize()
	{
		Textures::Initialize();
		Fonts::Initialize();

		ImGui_ImplWin32_Init(System::MainWindow);
		ImGui_ImplDX9_Init(Device::D3Device);
		UI::Get().Initialize();

		EventPluginRenderer event;
		Plugins::Dispatch(event);
	}

	void Renderer::Shutdown()
	{
		ImGui_ImplWin32_Shutdown();
		ImGui_ImplDX9_Shutdown();
		UI::Get().Release();

		Fonts::Release();
		Textures::Release();
	}

	void Renderer::Begin()
	{
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		UI::Get().Begin();
	}

	void Renderer::End()
	{
		UI::Get().End();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		KeyListener::Reset();
	}
}
