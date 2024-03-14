target_sources(IW3SR.Engine PRIVATE
	Common.hpp)

if(PLATFORM_WINDOWS)
	add_subdirectory(Windows)
endif()

target_include_directories(IW3SR.Engine PUBLIC .)
