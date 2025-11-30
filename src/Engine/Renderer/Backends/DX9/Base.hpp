#pragma once
#include "Core/Common.hpp"

#ifdef PLATFORM_WINDOWS
	#include "Windows/Base.hpp"
#endif

#pragma warning(push)
#pragma warning(disable : 26495)

#include <d3d9.h>
#include <d3dx9.h>

#pragma warning(pop)
