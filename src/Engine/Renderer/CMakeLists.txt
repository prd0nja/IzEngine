add_subdirectory(Backends)
add_subdirectory(Base)
add_subdirectory(Drawing)
add_subdirectory(Resources)

target_sources(IzEngine PRIVATE
	Common.hpp)
