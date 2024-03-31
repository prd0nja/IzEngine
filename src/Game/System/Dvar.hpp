#pragma once
#include "Game/Base.hpp"

namespace IW3SR::Game
{
	/// <summary>
	/// Game dvars.
	/// </summary>
	class API Dvar
	{
	public:
		/// <summary>
		/// Get dvar.
		/// </summary>
		/// <typeparam name="T">The value type.</typeparam>
		/// <param name="name">The dvar name.</param>
		template <typename T>
		static T Get(const std::string& name)
		{
			dvar_s* dvar = Dvar_FindVar(name.c_str());
			if (!dvar)
				throw std::runtime_error("Dvar not found");
			return *reinterpret_cast<T*>(&dvar->current);
		}

		/// <summary>
		/// Set dvar.
		/// </summary>
		/// <typeparam name="T">The value type.</typeparam>
		/// <param name="name">The dvar name.</param>
		/// <param name="value">The value.</param>
		template <typename T>
		static void Set(const std::string& name, T value)
		{
			dvar_s* dvar = Dvar_FindVar(name.c_str());
			if (!dvar)
				throw std::runtime_error("Dvar not found");

			*reinterpret_cast<T*>(&dvar->current) = value;
			*reinterpret_cast<T*>(&dvar->latched) = value;
		}

		/// <summary>
		/// Set dvar latched.
		/// </summary>
		/// <typeparam name="T">The value type.</typeparam>
		/// <param name="name">The dvar name.</param>
		/// <param name="value">The value.</param>
		template <typename T>
		static void SetLatched(const std::string& name, T value)
		{
			dvar_s* dvar = Dvar_FindVar(name.c_str());
			if (!dvar)
				throw std::runtime_error("Dvar not found");

			*reinterpret_cast<T*>(&dvar->latched) = value;
		}
	};
}
