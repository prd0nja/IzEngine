add_subdirectory(Backends)
add_subdirectory(Base)
add_subdirectory(Drawing)
add_subdirectory(Resources)
add_subdirectory(UI)

target_sources(IzEngine PRIVATE
	Common.hpp)
