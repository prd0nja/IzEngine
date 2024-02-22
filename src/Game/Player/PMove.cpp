#include "PMove.hpp"

namespace IW3SR::Game
{
	void PMove::FinishMove(usercmd_s* cmd)
	{
        CL_FinishMove_h(cmd);
		ModulesCallback(OnFinishMove, cmd);
	}

    void PMove::WalkMove(pmove_t* pm, pml_t* pml)
    {
        ModulesCallback(OnWalkMove, pm, pml);
        PM_WalkMove_h(pm, pml);
    }

    void PMove::AirMove(pmove_t* pm, pml_t* pml)
    {
        ModulesCallback(OnAirMove, pm, pml);
        PM_AirMove_h(pm, pml);
    }

	void PMove::SetYaw(usercmd_s* cmd, const float* angles, const vec3& target)
    {
        float angle = SHORT2ANGLE(cmd->angles[1]);

        float input = Math::AngleDelta(angles[1], angle);
        float to = Math::AngleDelta(angles[1], target[1]);
        float delta = input - to;

        clients->viewangles[1] += delta;
        cmd->angles[1] += ANGLE2SHORT(delta);
    }

    void PMove::SetPitch(usercmd_s* cmd, const float* angles, const vec3& target)
    {
        float angle = SHORT2ANGLE(cmd->angles[0]);

        float input = Math::AngleDelta(angles[0], angle);
        float to = Math::AngleDelta(angles[0], target[0]);
        float delta = input - to;

        clients->viewangles[0] += delta;
        cmd->angles[0] += ANGLE2SHORT(delta);
    }

    void PMove::SetRoll(usercmd_s* cmd, const float* angles, const vec3& target)
    {
        float angle = SHORT2ANGLE(cmd->angles[2]);

        float input = Math::AngleDelta(angles[2], angle);
        float to = Math::AngleDelta(angles[2], target[2]);
        float delta = input - to;

        clients->viewangles[2] += delta;
        cmd->angles[2] += ANGLE2SHORT(delta);
    }

    void PMove::SetAngles(usercmd_s* cmd, const float* angles, const vec3& target)
    {
        SetYaw(cmd, angles, target);
        SetPitch(cmd, angles, target);
        SetRoll(cmd, angles, target);
    }

    bool PMove::OnGround()
    {
        return pmove->ps->groundEntityNum != 1023;
    }

    bool PMove::InAir()
    {
        return pmove->ps->groundEntityNum == 1023;
    }
}
