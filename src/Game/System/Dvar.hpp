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
		/// Register int dvar.
		/// </summary>
		/// <param name="name">The dvar name.</param>
		/// <param name="flags">The dvar flags.</param>
		/// <param name="description">The description.</param>
		/// <param name="value">The default value.</param>
		/// <param name="min">The min value.</param>
		/// <param name="max">The max value.</param>
		/// <returns></returns>
		static dvar_s* RegisterInt(const std::string& name, DvarFlags flags, const std::string& description, int value,
			int min, int max)
		{
			return Dvar_RegisterVariant(name.c_str(), DvarType::INTEGER, flags, description.c_str(),
				DvarValue{ .integer{ value } }, DvarLimits{ .integer{ min, max } });
		}

		/// <summary>
		/// Register float dvar.
		/// </summary>
		/// <param name="name">The dvar name.</param>
		/// <param name="flags">The dvar flags.</param>
		/// <param name="description">The description.</param>
		/// <param name="value">The default value.</param>
		/// <param name="min">The min value.</param>
		/// <param name="max">The max value.</param>
		/// <returns></returns>
		static dvar_s* RegisterFloat(const std::string& name, DvarFlags flags, const std::string& description,
			float value, float min, float max)
		{
			return Dvar_RegisterVariant(name.c_str(), DvarType::VALUE, flags, description.c_str(),
				DvarValue{ .value{ value } }, DvarLimits{ .value{ min, max } });
		}

		/// <summary>
		/// Register string dvar.
		/// </summary>
		/// <param name="name">The dvar name.</param>
		/// <param name="flags">The dvar flags.</param>
		/// <param name="description">The description.</param>
		/// <param name="value">The default value.</param>
		/// <returns></returns>
		static dvar_s* RegisterString(const std::string& name, DvarFlags flags, const std::string& description,
			const std::string& value)
		{
			return Dvar_RegisterVariant(name.c_str(), DvarType::STRING, flags, description.c_str(),
				DvarValue{ .string{ value.c_str() } }, DvarLimits{ 0, 0 });
		}

		/// <summary>
		/// Register bool dvar.
		/// </summary>
		/// <param name="name">The dvar name.</param>
		/// <param name="flags">The dvar flags.</param>
		/// <param name="description">The description.</param>
		/// <param name="value">The default value.</param>
		/// <returns></returns>
		static dvar_s* RegisterBool(const std::string& name, DvarFlags flags, const std::string& description,
			bool value)
		{
			return Dvar_RegisterVariant(name.c_str(), DvarType::BOOLEAN, flags, description.c_str(),
				DvarValue{ .enabled{ value } }, DvarLimits{ .integer{ 0, 0 } });
		}

		/// <summary>
		/// Register enum dvar.
		/// </summary>
		/// <param name="name">The dvar name.</param>
		/// <param name="flags">The dvar flags.</param>
		/// <param name="description">The description.</param>
		/// <param name="value">The default value.</param>
		/// <param name="list">The enum list.</param>
		/// <returns></returns>
		static dvar_s* RegisterEnum(const std::string& name, DvarFlags flags, const std::string& description, int value,
			const std::vector<const char*>& list)
		{
			return Dvar_RegisterVariant(name.c_str(), DvarType::ENUMERATION, flags, description.c_str(),
				DvarValue{ .integer{ value } },
				DvarLimits{ .enumeration{ static_cast<int>(list.size()), const_cast<const char**>(list.data()) } });
		}

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
