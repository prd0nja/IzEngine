#pragma once
#include "Core/Base.hpp"
#include "Core/Math.hpp"

namespace IzEngine
{
	/// <summary>
	/// Mouse class.
	/// </summary>
	class API Mouse
	{
	public:
		static inline vec2 Position = { 0, 0 };
		static inline vec2 Delta = { 0, 0 };

		/// <summary>
		/// Register mouse.
		/// </summary>
		static void Register();

		/// <summary>
		/// Process raw input.
		/// </summary>
		/// <param name="msg">The message code.</param>
		/// <param name="state">The mouse state.</param>
		static void Process(uint64_t msg, uint64_t state);
	};
}
