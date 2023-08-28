cmake_minimum_required(VERSION 3.26)
project(IW3SR VERSION 1.0.0 LANGUAGES CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Env
set(COD4_MILES $ENV{COD4}/miles)

# CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR 7Z)
include(CPack)

# Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Build
add_subdirectory(src)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	message("Windows Build")
	target_link_libraries(IW3SR PRIVATE ${CONAN_LIBS})
else()
	message("Linux Build")

	set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
	set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
	set(CMAKE_SYSTEM_NAME Windows)
	set(CMAKE_CROSSCOMPILING 1)

	target_link_libraries(IW3SR PRIVATE
		${CONAN_LIBS}
		-static-libgcc
		-static-libstdc++
		-static -lwinpthread)

	set_target_properties(IW3SR PROPERTIES
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
		PREFIX ""
		SUFFIX .dll)
endif()
