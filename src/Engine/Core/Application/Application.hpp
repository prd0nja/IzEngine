#pragma once
#include "Core/Communication/Event.hpp"

namespace IzEngine
{
	/// <summary>
	/// Application client.
	/// </summary>
	class Application
	{
	public:
		/// <summary>
		/// Start the application.
		/// </summary>
		static void Start();

		/// <summary>
		/// Shutdown the application.
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// Dispatch event.
		/// </summary>
		/// <param name="event">The event.</param>
		static void Dispatch(Event& event);
	};
}
