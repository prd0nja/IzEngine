#include "ESP.hpp"
#include "Game/Render/Draw.hpp"
#include "Game/Player.hpp"

#include <iostream>

namespace IW3SR
{
    ESP::ESP()
    {
        ID = "sr.player.esp";
        Name = "ESP";

        Color = glm::vec4{ 1, 0, 0, 1 };
    }

    void ESP::OnDraw()
    {
        for (const auto& player : Player::GetAll())
        {
            if (player->IsSelf())
                continue;

            auto& pos = player->c->pose.origin;
            Draw::Rect2D(Color, pos[0], pos[1], 10, 10);
        }
    }
}
