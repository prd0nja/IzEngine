add_subdirectory(Backends)
add_subdirectory(Core)
add_subdirectory(Sys)

target_precompile_headers(IW3SR PRIVATE
	API.hpp
	Plugin.hpp)

target_sources(IW3SR PRIVATE
	API.hpp
	Plugin.hpp)
