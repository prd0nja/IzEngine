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
        ~ESP();

        /// <summary>
        /// Initialize the module.
        /// </summary>
        void Initialize() override;

        /// <summary>
        /// Shutdown the module.
        /// </summary>
        void Shutdown() override;
    };
}
