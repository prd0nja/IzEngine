#pragma once
#include "Core/Common.hpp"

namespace IzEngine
{
	/// <summary>
	/// Mouse class.
	/// </summary>
	class API Mouse
	{
	public:
		static inline vec2 Position;
		static inline vec2 Delta;
		static inline vec2 AccumulatedDelta;

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
