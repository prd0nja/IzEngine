add_library(IW3SR SHARED)

add_subdirectory(Commands)
add_subdirectory(Game)
add_subdirectory(Modules)
add_subdirectory(Sys)
add_subdirectory(Utils)

target_sources(IW3SR PRIVATE main.cpp)
target_include_directories(IW3SR PUBLIC .)
get_target_property(SOURCES IW3SR SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
