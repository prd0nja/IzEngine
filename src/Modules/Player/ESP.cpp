#include "ESP.hpp"
#include "Game/Game.hpp"

namespace IW3SR
{
    ESP::ESP()
    {
        ID = "sr.player.esp";
        Name = "ESP";

        Color = { 0, 0, 1, 1 };
    }

    void ESP::OnFrame()
    {
        for (const auto& player : Player::GetAll())
        {
            if (player->IsSelf())
                continue;
        }
    }
}
