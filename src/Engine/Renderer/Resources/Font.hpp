#pragma once
#include "Core/Common.hpp"

#define FONT_OPENSANS "OpenSans-Regular"
#define FONT_SPACERANGER "Space Ranger"

namespace IzEngine
{
	class API Font : public IObject
	{
	public:
		void* Data = nullptr;

		Font() = default;
		virtual ~Font();

		static Ref<Font>& Create(const std::string& name, int height);
		static Ref<Font>& Create(const std::filesystem::path& path, int height);
		static Ref<Font>& Default();
	};

	class Fonts
	{
	public:
		static inline std::unordered_map<std::string, Ref<Font>> List;
		static inline std::vector<std::string> Names;

		static void Initialize();
		static void Shutdown();
	};
}
