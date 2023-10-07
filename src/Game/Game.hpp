#pragma once
#include "Definitions.hpp"

#include "Game/Render/Render.hpp"
#include "Game/Render/GUI.hpp"
#include "Game/Player.hpp"
#include "Modules/Modules.hpp"

#include "Sys/Log.hpp"
#include "Sys/Render/D3D9EX.hpp"
#include "Utils/Math.hpp"

#include <memory>
#include <array>

namespace IW3SR
{
	/// <summary>
	/// IW3SR Game client.
	/// </summary>
	class Game
	{
	public:
		std::unique_ptr<Log> Log;
		std::unique_ptr<Render> Render;
		std::unique_ptr<Modules> Modules;
		std::unique_ptr<GUI> GUI;

		std::array<std::shared_ptr<Player>, 64> Players;

		/// <summary>
		/// Initialize the game.
		/// </summary>
		Game();
		~Game() = default;

		/// <summary>
		/// Initialize game.
		/// </summary>
		void Initialize();

		/// <summary>
		/// CoD4X patch.
		/// </summary>
		void CoD4X();

		/// <summary>
		/// Game frame.
		/// </summary>
		void Frame();
	};
}

extern std::unique_ptr<Game> SR;
