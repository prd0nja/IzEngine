#include "Sys/Log.hpp"

#include "Modules/Modules.hpp"
#include "Modules/ESP.hpp"

namespace IW3SR
{
	EXPORT void Initialize()
	{
		Log::WriteLine("[Private] Initialize");

		Modules::Load<ESP>();
	}

	EXPORT void Shutdown()
	{
		Log::WriteLine("[Private] Shutdown");
	}
}
