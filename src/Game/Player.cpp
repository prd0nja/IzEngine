#include "Player.hpp"
#include "Game/Game.hpp"

namespace IW3SR
{
	Player::Player(int index)
	{
		c = &cg_entities[index];
		info = &cgs->bgs.clientinfo[index];
	}

	bool Player::IsSelf()
	{
		return c->nextState.clientNum == cgs->clientNum;
	}

	void Player::Initialize()
	{
		for (int i = 0; i < 64; i++) 
			SR->Players[i] = std::make_shared<Player>(i);
	}

	std::array<std::shared_ptr<Player>, 64> Player::GetAll()
	{
		std::array<std::shared_ptr<Player>, 64> players{ };
		for (int i = 0; i < 64; i++)
		{
			const auto& player = SR->Players[i];
			if (player) players[i] = player;
		}
		return players;
	}

	std::shared_ptr<Player> Player::Get(int index)
	{
		return SR->Players[index];
	}

	Player::operator bool() const
	{
		return c;
	}
}
