#include "Game.hpp"
#include "Sys/Memory.hpp"
#include "Sys/Environment.hpp"

#include <array>

namespace IW3SR
{
	Game::Game()
	{
		CoD4X();
		Environment::Build();

		Log = std::make_unique<class Log>();
		Render = std::make_unique<class Render>();
		Modules = std::make_unique<class Modules>();
	}

	void Game::Initialize()
	{
		Modules->Initialize();
		Player::Initialize();
	}

	void Game::CoD4X()
	{
		if (!COD4X) return;

		uintptr_t antiHook = COD4X + 0x43580;
		uintptr_t aimAssist = 0x452BFA;
		uintptr_t localTagMatrix = 0x434200;

		Memory::Write(antiHook, "\xC3", 1);
		Memory::Write(aimAssist, "\xE8\xA1\xF9\xFA\xFF", 5);
		Memory::Write(localTagMatrix, "\x51\x53\x8B\x5C\x24", 5);
	}

	void Game::Frame() { }
}
