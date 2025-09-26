#pragma once
#include "ImGUI/Drawing/Frame.hpp"

#include <tuple>

namespace IzEngine::UC
{
	/// <summary>
	/// Themes frame.
	/// </summary>
	class Themes : public Frame
	{
	public:
		static inline std::tuple<ImColor, ImColor> Rainbow;
		static inline ImGui::MarkdownConfig Markdown;

		static inline ImFont* H1 = nullptr;
		static inline ImFont* H2 = nullptr;
		static inline ImFont* H3 = nullptr;

		ImGuiStyle Style;
		ImPlotStyle PlotStyle;

		/// <summary>
		/// Initialize the themes frame.
		/// </summary>
		Themes();
		virtual ~Themes() = default;

		/// <summary>
		/// Initialize themes.
		/// </summary>
		void Initialize() override;

		/// <summary>
		/// Render frame.
		/// </summary>
		void OnRender() override;

		/// <summary>
		/// Compute rainbow color.
		/// </summary>
		static void ComputeRainbow();

	private:
		/// <summary>
		/// Default theme.
		/// </summary>
		void Default();

		/// <summary>
		/// Apply theme.
		/// </summary>
		void Apply();

		/// <summary>
		/// Markdown link callback.
		/// </summary>
		/// <param name="data">The data.</param>
		static void MarkdownLink(ImGui::MarkdownLinkCallbackData data);

		/// <summary>
		/// Markdown image callback.
		/// </summary>
		/// <param name="data">The data.</param>
		/// <returns></returns>
		static ImGui::MarkdownImageData MarkdownImage(ImGui::MarkdownLinkCallbackData data);

		/// <summary>
		/// Markdown format callback.
		/// </summary>
		/// <param name="info">The format info.</param>
		/// <param name="start">Is the start of the token.</param>
		static void MarkdownFormat(const ImGui::MarkdownFormatInfo& info, bool start);

		SERIALIZE_POLY(Themes, Frame, Style, PlotStyle)
	};
}
