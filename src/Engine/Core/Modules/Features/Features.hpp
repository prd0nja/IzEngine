#pragma once
#include "Feature.hpp"
#include "Engine/Core/Modules.hpp"

namespace IW3SR
{
	/// <summary>
	/// Game features.
	/// </summary>
	class API Features : public Modules
	{
	public:
		static inline std::map<std::string, std::unique_ptr<Module>> Entries;
		static inline nlohmann::json Serialized;

		/// <summary>
		/// Initialize the features.
		/// </summary>
		Features();
		virtual ~Features();
		
		/// <summary>
		/// Load a feature.
		/// </summary>
		/// <typeparam name="F">The feature type.</typeparam>
		template <class F = Feature>
		static void Load()
		{
			std::unique_ptr<F> entry = std::make_unique<F>();
			bool isSerialized = Serialized.contains(entry->ID);

			if (isSerialized)
			{
				try { entry->Deserialize(Serialized[entry->ID]); }
				catch (...) {}
			}
			Entries.insert({ entry->ID, std::move(entry) });
		}

		/// <summary>
		/// Remove a feature.
		/// </summary>
		/// <param name="id">The feature id.</param>
		static void Remove(const std::string& id);

		/// <summary>
		/// Dispatch callback.
		/// </summary>
		/// <typeparam name="Func">The callback type.</typeparam>
		/// <param name="callback">The function callback.</param>
		template <typename Func>
		void Callback(Func callback)
		{
			for (const auto& [_, entry] : Entries)
			{
				if (entry->IsEnabled)
					callback(entry);
			}
		}

		/// <summary>
		/// Load the features.
		/// </summary>
		void Deserialize() override;

		/// <summary>
		/// Serialize the features.
		/// </summary>
		void Serialize() override;
	};
}
