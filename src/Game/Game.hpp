#pragma once
#include "Definitions.hpp"
#include "Game/Render/Render.hpp"
#include "Modules/Modules.hpp"

#include "Sys/Log.hpp"
#include "Sys/Render/D3D9EX.hpp"

#include <memory>

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

		/// <summary>
		/// Initialize the game.
		/// </summary>
		Game();
		~Game();

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
