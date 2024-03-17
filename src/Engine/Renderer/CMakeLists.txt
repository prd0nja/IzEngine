add_subdirectory(Backends)
add_subdirectory(Core)
add_subdirectory(Drawing)
add_subdirectory(Resources)

target_sources(IW3SR.Engine PRIVATE
	Common.hpp)
