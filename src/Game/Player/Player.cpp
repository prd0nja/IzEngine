#include "Player.hpp"
#include "Game/Game.hpp"

namespace IW3SR::Game
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

	bool Player::IsAlive()
	{
		return c->isAlive;
	}

	bool Player::OnGround()
	{
		return c->nextState.groundEntityNum != 1023;
	}

	bool Player::InAir()
	{
		return c->nextState.groundEntityNum == 1023;
	}

	void Player::Allocates()
	{
		for (int i = 0; i < Players.size(); i++)
			Players[i] = std::make_shared<Player>(i);
	}

	void Player::Predict(int localClientNum)
	{
		CG_PredictPlayerState_Internal_h(localClientNum);

		const centity_s* cent = &cg_entities[cgs->predictedPlayerState.groundEntityNum];
		const entityType_t eType = cent->nextState.eType;
		const float fromTime = cgs->snap->serverTime;
		const float toTime = cgs->time;

		if (eType == ET_SCRIPTMOVER || eType == ET_PLANE)
		{
			vec3 angles, oldAngles;
			BG_EvaluateTrajectory(&cent->currentState.apos, fromTime, oldAngles);
			BG_EvaluateTrajectory(&cent->currentState.apos, toTime, angles);

			vec3 deltaAngles = angles - oldAngles;
			cgs->predictedPlayerState.viewangles[0] += deltaAngles.x;
			cgs->predictedPlayerState.viewangles[1] += deltaAngles.y;
			cgs->predictedPlayerState.viewangles[2] += deltaAngles.z;
			cgs->predictedPlayerState.delta_angles[1] += deltaAngles.y;
		}
	}

	std::array<std::shared_ptr<Player>, 64>& Player::GetAll()
	{
		return Players;
	}

	std::shared_ptr<Player>& Player::Get(int index)
	{
		return Players[index];
	}

	std::shared_ptr<Player>& Player::Self()
	{
		return Players[cgs->clientNum];
	}

	Player::operator bool() const
	{
		return c;
	}
}
