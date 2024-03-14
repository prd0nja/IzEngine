#pragma once
#include "Game/Definitions.hpp"

#define FONT_SMALL_DEV  "fonts/smallDevFont"
#define FONT_BIG_DEV    "fonts/bigDevFont"
#define FONT_CONSOLE    "fonts/consoleFont"
#define FONT_BIG        "fonts/bigFont"
#define FONT_SMALL      "fonts/smallFont"
#define FONT_BOLD       "fonts/boldFont"
#define FONT_NORMAL     "fonts/normalFont"
#define FONT_EXTRA_BIG  "fonts/extraBigFont"
#define FONT_OBJECTIVE  "fonts/objectiveFont"

namespace IW3SR::Game
{
	/// <summary>
	/// Assets class.
	/// </summary>
	class API Assets
	{
		CLASS_SINGLETON(Assets)
	public:
		std::unordered_map<std::string, Font_s*> Fonts;
		std::vector<std::string> FontNames;

		/// <summary>
		/// Initialize the assets.
		/// </summary>
		void Initialize();

		/// <summary>
		/// Release the assets.
		/// </summary>
		void Release();

		/// <summary>
		/// Load a font.
		/// </summary>
		/// <param name="name">The font name.</param>
		/// <returns></returns>
		Font_s* LoadFont(const std::string& name);

	private:
		/// <summary>
		/// Initialize assets.
		/// </summary>
		Assets() = default;
		virtual ~Assets() = default;

		/// <summary>
		/// Load fonts.
		/// </summary>
		void LoadFonts();
	};
}
