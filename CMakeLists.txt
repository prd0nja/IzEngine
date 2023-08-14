cmake_minimum_required(VERSION 3.26)
project(SR VERSION 1.0.0 LANGUAGES CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 23)

# CoD4
set(COD4_MILES $ENV{COD4}/miles)

# CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR 7Z)
include(CPack)

# Tests
# include(CTest)
# add_executable(SR.Tests)
# add_test(NAME Tests COMMAND SR.Tests)

# Build
add_library(SR SHARED)
add_subdirectory(src)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("Windows Build")
else()
	message("Linux Build")

	set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
	set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
	set(CMAKE_SYSTEM_NAME Windows)
	set(CMAKE_CROSSCOMPILING 1)

	target_link_libraries(SR PRIVATE
		-static-libgcc
		-static-libstdc++
		-static -lwinpthread)

	set_target_properties(SR PROPERTIES
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
		PREFIX ""
		SUFFIX .dll)
endif()
