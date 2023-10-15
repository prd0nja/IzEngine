#pragma once
#include "Game/Game.hpp"

#include <string>

namespace IW3SR
{
	class Dvar
	{
	public:
		/// <summary>
		/// Find the dvar.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="name">The dvar name.</param>
		template <typename T>
		static T Find(const std::string& name)
		{
			dvar_s* dvar = Dvar_FindVar(name.c_str());
			if (!dvar)
			{
				throw std::runtime_error("dvar not found");
				return 0;
			}
			return *reinterpret_cast<T*>(&dvar->current.value);
		}

		/// <summary>
		/// Set the dvar to desired value.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="name">The dvar name.</param>
		/// <param name="value">The value you want the dvar to be.</param>
		template <typename T>
		static void Set(const std::string& name, T value)
		{
			dvar_s* dvar = Dvar_FindVar(name.c_str());
			if (!dvar)
			{
				throw std::runtime_error("dvar not found");
				return;
			}
			Memory::Assign<T>(dvar->current.value, value);
		}
	};
}
