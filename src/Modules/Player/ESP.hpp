#pragma once
#include "Modules/Module.hpp"
#include <glm/glm.hpp>

namespace IW3SR
{
    /// <summary>
    /// Extra Sensory Perception.
    /// </summary>
    class ESP : public Module
    {
    public:
        glm::vec4 Color;

        /// <summary>
        /// Initialize the module.
        /// </summary>
        ESP();
        virtual ~ESP() = default;

        /// <summary>
        /// Draw callback.
        /// </summary>
        void OnDraw() override;
    };
}
