#pragma once
#include "Definitions.hpp"

#include "Game/Engine/GUI.hpp"
#include "Game/Engine/Render.hpp"
#include "Game/Player/Player.hpp"
#include "Game/Sys/Console.hpp"

#include "Engine/Core/Modules.hpp"
#include "Engine/Core/Math.hpp"

namespace IW3SR
{
	/// <summary>
	/// Game client.
	/// </summary>
	class GameClient
	{
	public:
		std::unique_ptr<DLLS> DLLS;
		std::unique_ptr<Features> Features;
		std::unique_ptr<Modules> Modules;
		std::unique_ptr<GUI> GUI;
		std::unique_ptr<Render> Render;
		std::unique_ptr<Console> Console;

		std::array<std::shared_ptr<Player>, 64> Players;

		/// <summary>
		/// Initialize the game.
		/// </summary>
		GameClient();
		~GameClient();

		/// <summary>
		/// Initialize game.
		/// </summary>
		void Initialize();

		/// <summary>
		/// CoD4X patch.
		/// </summary>
		void CoD4X();

		/// <summary>
		/// Hook game.
		/// </summary>
		void Hook();

		/// <summary>
		/// Unhook game.
		/// </summary>
		void Unhook();
	};
}

extern GameClient* GC;
