#pragma once
#include "ImGUI/Base.hpp"

namespace IzEngine
{
	/// <summary>
	/// Frame drawing.
	/// </summary>
	class API Frame : public IObject
	{
	public:
		std::string Name = UUID();
		vec2 Position = { 20, 20 };
		vec2 Size = { 250, 140 };
		vec2 RenderPosition;
		vec2 RenderSize;
		bool Open = false;
		bool Designer = false;

		ImGuiWindowFlags Flags = ImGuiWindowFlags_NoCollapse;
		Horizontal HorizontalAlign = Horizontal::Left;
		Vertical VerticalAlign = Vertical::Top;

		/// <summary>
		/// Create a frame.
		/// </summary>
		Frame() = default;
		virtual ~Frame();

		/// <summary>
		/// Create a frame.
		/// </summary>
		/// <param name="name">The frame name.</param>
		Frame(const std::string& name);

		/// <summary>
		/// Initialize frame.
		/// </summary>
		virtual void Initialize();

		/// <summary>
		/// Release frame.
		/// </summary>
		/// <returns></returns>
		virtual void Release();

		/// <summary>
		/// Set the frame position and size.
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="size">The size.</param>
		virtual void SetRect(const vec2& position, const vec2& size);

		/// <summary>
		/// Set the frame position and size.
		/// </summary>
		/// <param name="x">X value.</param>
		/// <param name="y">Y value.</param>
		/// <param name="w">The width.</param>
		/// <param name="h">The height.</param>
		virtual void SetRect(float x, float y, float w, float h);

		/// <summary>
		/// Set the rect alignment.
		/// </summary>
		/// <param name="horizontal">Horizontal aligment.</param>
		/// <param name="vertical">Vertical alignment.</param>
		virtual void SetRectAlignment(Horizontal horizontal, Vertical vertical);

		/// <summary>
		/// Set designer edition.
		/// </summary>
		/// <param name="state">The state.</param>
		virtual void SetDesigner(bool state);

		/// <summary>
		/// Set frame flags.
		/// </summary>
		/// <param name="flags">The frame flags.</param>
		virtual void SetFlags(ImGuiWindowFlags flags);

		/// <summary>
		/// Render menu.
		/// </summary>
		/// <param name="label">The label.</param>
		/// <param name="open">Default open.</param>
		virtual void Menu(const std::string& label, bool open = false);

		/// <summary>
		/// Begin drawing.
		/// </summary>
		virtual void Begin();

		/// <summary>
		/// End drawing.
		/// </summary>
		virtual void End();

		/// <summary>
		/// Render frame.
		/// </summary>
		virtual void OnRender();

		/// <summary>
		/// On event.
		/// </summary>
		/// <param name="event">The event.</param>
		virtual void OnEvent(Event& event);

		SERIALIZE_POLY_BASE(Frame, Position, Size, Open, HorizontalAlign, VerticalAlign)
	};
}
