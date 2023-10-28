add_library(IW3SR OBJECT)
add_library(IW3SR.ASM OBJECT)
add_library(IW3SR.DLL SHARED)
add_library(IW3SR.API ALIAS IW3SR.DLL)

add_subdirectory(Commands)
add_subdirectory(Game)
add_subdirectory(Modules)
add_subdirectory(Sys)
add_subdirectory(Utils)

target_include_directories(IW3SR PUBLIC .)
target_sources(IW3SR.DLL PRIVATE main.cpp)
target_link_libraries(IW3SR.DLL PUBLIC IW3SR)

get_target_property(SOURCES_IW3SR IW3SR SOURCES)
get_target_property(SOURCES_IW3SR_DLL IW3SR.DLL SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES_IW3SR} ${SOURCES_IW3SR_DLL})
