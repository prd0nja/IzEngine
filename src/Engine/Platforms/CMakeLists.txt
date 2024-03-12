if(PLATFORM_WINDOWS)
	add_subdirectory(Windows)
endif()

target_include_directories(IW3SR.Engine PUBLIC .)
