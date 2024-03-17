#pragma once

namespace IW3SR::Engine
{
	/// <summary>
	/// Renderer class.
	/// </summary>
	class Renderer
	{
	public:
		/// <summary>
		/// Initialize renderer.
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Shutdown renderer.
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// Begin frame.
		/// </summary>
		static void Begin();

		/// <summary>
		/// End frame.
		/// </summary>
		static void End();
	};
}
