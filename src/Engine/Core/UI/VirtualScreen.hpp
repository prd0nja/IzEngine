#pragma once
#include "Core/Common.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

namespace IzEngine
{
	enum class Horizontal
	{
		SubLeft,	   // Left edge of a 4:3 screen (safe area not included).
		Left,		   // Left viewable (safe area) edge.
		Center,		   // Center of the screen (reticle).
		Right,		   // Right viewable (safe area) edge.
		Fullscreen,	   // Disregards safe area.
		NoScale,	   // Uses exact parameters.
		To640,		   // Scales a real-screen resolution x down into the 0 - 640 range.
		CenterSafeArea // Center of the safearea.
	};

	enum class Vertical
	{
		SubTop,		   // Top edge of the 4:3 screen (safe area not included).
		Top,		   // Top viewable (safe area) edge.
		Center,		   // Center of the screen (reticle).
		Bottom,		   // Bottom viewable (safe area) edge.
		Fullscreen,	   // Disregards safe area.
		NoScale,	   // Uses exact parameters.
		To480,		   // Scales a real-screen resolution y down into the 0 - 480 range.
		CenterSafeArea // Center of the save area.
	};

	enum class Alignment
	{
		Top = 0,
		Left = 0,
		Middle = 1,
		Bottom = 2,
		Center = 4,
		Right = 8
	};

	/// <summary>
	/// Virtual screen.
	/// </summary>
	class API VirtualScreen
	{
	public:
		vec2 Position;
		vec2 Size;
		vec2 DisplaySize;
		float AdjustedRealWidth = 0;

		vec2 RealMin;
		vec2 RealMax;
		vec2 VirtualMin;
		vec2 VirtualMax;
		vec2 VirtualToReal;
		vec2 VirtualToFull;
		vec2 RealToVirtual;
		vec2 SubScreen;

		/// <summary>
		/// Initialize the virtual screen.
		/// </summary>
		VirtualScreen() = default;

		/// <summary>
		/// Initialize the virtual screen.
		/// </summary>
		/// <param name="size">The size.</param>
		VirtualScreen(const vec2& size);
		~VirtualScreen() = default;

		/// <summary>
		/// Setup the virtual screen.
		/// </summary>
		void Setup();

		/// <summary>
		/// Compute the safe area.
		/// </summary>
		void SafeArea();

		/// <summary>
		/// Virtual to real screen.
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="horizontal">Horizontal aligment.</param>
		/// <param name="vertical">Vertical aligment.</param>
		void Apply(vec2& position, Horizontal horizontal, Vertical vertical);

		/// <summary>
		/// Virtual to real screen.
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="size">The size.</param>
		/// <param name="horizontal">Horizontal aligment.</param>
		/// <param name="vertical">Vertical aligment.</param>
		void Apply(vec2& position, vec2& size, Horizontal horizontal, Vertical vertical);

		/// <summary>
		/// Real to virtual screen.
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="horizontal">Horizontal aligment.</param>
		/// <param name="vertical">Vertical aligment.</param>
		void Reverse(vec2& position, Horizontal horizontal, Vertical vertical);

		/// <summary>
		/// Real to virtual screen.
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="size">The size.</param>
		/// <param name="horizontal">Horizontal aligment.</param>
		/// <param name="vertical">Vertical aligment.</param>
		void Reverse(vec2& position, vec2& size, Horizontal horizontal, Vertical vertical);
	};
}
