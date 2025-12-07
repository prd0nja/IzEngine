add_subdirectory(Implementation)

target_sources(IzEngine PRIVATE
	Font.hpp
	Texture.hpp)

if(BUILD_CEF)
	target_sources(IzEngine PRIVATE Browser.hpp)
endif()
