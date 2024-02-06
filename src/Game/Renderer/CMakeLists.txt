add_subdirectory(Backends)
add_subdirectory(Drawing)
add_subdirectory(Features)
add_subdirectory(Modules)
add_subdirectory(UI)

target_sources(IW3SR PRIVATE
	Assets.hpp
	Assets.cpp
	GUI.hpp
	GUI.cpp
	Renderer.hpp
	Renderer.cpp)
