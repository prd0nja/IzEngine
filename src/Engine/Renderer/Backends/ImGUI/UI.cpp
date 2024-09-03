#include "UI.hpp"

#include "Drawing/Notification.hpp"
#include "UI/Memory.hpp"
#include "UI/Themes.hpp"

#include "Core/System/Environment.hpp"
#include "Core/System/System.hpp"

namespace IzEngine
{
	void UI::Initialize()
	{
		IZ_ASSERT(!Active, "UI already initialized.");

		ImGui::SetAllocatorFunctions(&Allocator, &Free, &Data);
		Context = ImGui::CreateContext();
		PlotContext = ImPlot::CreateContext();

		ImGui::SetCurrentContext(Context);
		ImPlot::SetImGuiContext(Context);
		ImPlot::SetCurrentContext(PlotContext);

		Environment::Load(Serialized, "ui.json");

		CreateWindow<UC::Themes>();
		CreateWindow<UC::Memory>();

		Active = true;
	}

	void UI::CreateScreen(const vec2& position, const vec2& size, const vec2& display)
	{
		Screen = VirtualScreen(position, size, display);
		Size = Screen.VirtualToReal.y * Scale;
	}

	void UI::Shutdown()
	{
		IZ_ASSERT(Active, "UI already shutdown.");

		ImGui::DestroyContext(Context);
		ImPlot::DestroyContext(PlotContext);

		for (const auto& [_, window] : Windows)
		{
			window->Serialize(Serialized[window->Name]);
			window->Release();
		}
		Environment::Save(Serialized, "ui.json");
		Windows.clear();

		Active = false;
	}

	void UI::Begin()
	{
		ImGui::NewFrame();
		UC::Themes::ComputeRainbow();
		Notifications::Render();
	}

	void UI::End()
	{
		ImGui::Render();
	}

	double UI::Time()
	{
		return GImGui->Time;
	}

	float UI::DeltaTime()
	{
		return ImGui::GetIO().DeltaTime;
	}

	int UI::DeltaTimeMS()
	{
		return ImGui::GetIO().DeltaTime * 1000;
	}

	void UI::InitializeContext()
	{
		ImGui::SetAllocatorFunctions(UI::Allocator, UI::Free, UI::Data);
		ImGui::SetCurrentContext(UI::Context);
		ImPlot::SetImGuiContext(UI::Context);
		ImPlot::SetCurrentContext(UI::PlotContext);
	}

	void* UI::Allocator(size_t size, void* data)
	{
		return malloc(size);
	}

	void UI::Free(void* ptr, void* data)
	{
		free(ptr);
	}

	void UI::Dispatch(Event& event)
	{
		for (const auto& [_, window] : Windows)
			window->OnEvent(event);
	}
}
