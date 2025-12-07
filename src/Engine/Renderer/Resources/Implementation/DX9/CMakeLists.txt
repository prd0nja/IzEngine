target_sources(IzEngine PRIVATE
	Font.cpp
	Texture.cpp)

if(BUILD_CEF)
	target_sources(IzEngine PRIVATE Browser.cpp)
endif()
