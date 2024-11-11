#pragma once
#include "Core/Base.hpp"

namespace IzEngine
{
	/// <summary>
	/// Bind input class.
	/// </summary>
	class API Bind
	{
	public:
		int Key = 0;

		/// <summary>
		/// Initialize the bind.
		/// </summary>
		Bind() = default;

		/// <summary>
		/// Initialize the bind.
		/// </summary>
		/// <param name="key">The key.</param>
		Bind(int key);
		~Bind() = default;

		/// <summary>
		/// Is up.
		/// </summary>
		/// <returns></returns>
		bool IsUp();

		/// <summary>
		/// Is down.
		/// </summary>
		/// <returns></returns>
		bool IsDown();

		/// <summary>
		/// Is pressed.
		/// </summary>
		/// <returns></returns>
		bool IsPressed();

		SERIALIZE(Bind, Key)
	};
}
