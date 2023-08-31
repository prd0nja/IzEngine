#include "ESP.hpp"
#include <iostream>

namespace IW3SR
{
    ESP::ESP()
    {
        ID = "sr.player.esp";
        Name = "ESP";

        Initialize();
    }

    ESP::~ESP()
    {
        Shutdown();
    }

    void ESP::Initialize()
    {
        
    }

    void ESP::Shutdown()
    {
        
    }
}
