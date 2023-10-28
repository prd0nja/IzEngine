# Build
add_library(Reloader SHARED main.cpp)
target_link_libraries(Reloader PRIVATE IW3SR.API)
set_target_properties(Reloader PROPERTIES FOLDER Plugins)

get_target_property(SOURCES Reloader SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

# Install
install(TARGETS Reloader RUNTIME DESTINATION ${COD4}/iw3sr/plugins)
