target_precompile_headers(IW3SR.Engine PRIVATE
	Base.hpp)

target_sources(IW3SR.Engine PRIVATE
	Base.hpp
	Console.cpp
	Environment.cpp
	Keyboard.cpp
	Memory.cpp
	Plugin.cpp
	Signature.cpp
	System.cpp)
