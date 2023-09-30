#include "Module.hpp"
#include <iostream>

namespace IW3SR
{
	Module::~Module()
	{
		Shutdown();
	}

	void Module::Initialize() { }
	void Module::Shutdown() { }
	void Module::OnFrame() { }
}
