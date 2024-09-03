#include "Window.hpp"
#include "ImGUI/UI.hpp"

namespace IzEngine
{
	Window::Window(const std::string& name)
	{
		Name = name;
	}

	Window::~Window()
	{
		Release();
	}

	void Window::Initialize() { }
	void Window::Release() { }

	void Window::SetRect(const vec2& position, const vec2& size)
	{
		SetRect(position.x, position.y, size.x, size.y);
	}

	void Window::SetRect(float x, float y, float w, float h)
	{
		Position = { x, y };
		Size = { w, h };
	}

	void Window::SetRectAlignment(Horizontal horizontal, Vertical vertical)
	{
		HorizontalAlign = horizontal;
		VerticalAlign = vertical;
	}

	void Window::SetDesigner(bool state)
	{
		Designer = state;
	}

	void Window::SetFlags(ImGuiWindowFlags flags)
	{
		Flags = flags;
	}

	void Window::Menu(const std::string& label, bool open)
	{
		if (!ImGui::CollapsingHeader(label, open))
			return;

		ImGui::PushID(label.c_str());

		ImGui::DragFloat2("Position", Position);
		ImGui::DragFloat2("Size", Size);
		ImGui::ComboAlignRect(&HorizontalAlign, &VerticalAlign);

		ImGui::PopID();
	}

	void Window::Begin()
	{
		vec2 position = Position;
		vec2 size = Size;

		UI::Screen.Apply(position, size, HorizontalAlign, VerticalAlign);
		RenderPosition = position;
		RenderSize = size;

		ImGui::Begin(Name.c_str(), &Open, Flags);

		if (ImGui::IsWindowChanged())
		{
			position = ImGui::GetWindowPos();
			size = ImGui::GetWindowSize();

			UI::Screen.Reverse(position, size, HorizontalAlign, VerticalAlign);
			Position = position;
			Size = size;
		}
		else
		{
			ImGui::SetWindowPos(position);
			ImGui::SetWindowSize(size);
		}
		if (Designer)
			ImGui::Movable(ID, Position, Size, RenderPosition, RenderSize);
	}

	void Window::End()
	{
		ImGui::End();
	}

	void Window::OnRender() { }

	void Window::OnEvent(Event& event)
	{
		if (!UI::Open || !Open)
			return;

		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<EventRendererRender>(EVENT_BIND_VOID(OnRender));
	}
}
