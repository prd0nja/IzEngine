# Tests
if(BUILD_TESTING)
	add_executable(IW3SR.Private.Tests)

	target_link_libraries(IW3SR.Private.Tests PRIVATE
		IW3SR.Private
		GTest::gtest
		GTest::gtest_main
		GTest::gmock
		GTest::gmock_main)

	add_test(NAME PrivateTests COMMAND IW3SR.Private.Tests)
endif()

# Build
add_library(IW3SR.Private SHARED private.cpp)
target_link_libraries(IW3SR.Private PUBLIC IW3SR.API)

# add_subdirectory(Modules)

get_target_property(SOURCES IW3SR.Private SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
