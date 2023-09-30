#pragma once
#include "Modules/Module.hpp"

namespace IW3SR
{
    /// <summary>
    /// Extra Sensory Perception.
    /// </summary>
    class ESP : public Module
    {
    public:
        /// <summary>
        /// Initialize the module.
        /// </summary>
        ESP();
        virtual ~ESP() = default;

        /// <summary>
        /// Render frame callback.
        /// </summary>
        void OnFrame() override;
    };
}
