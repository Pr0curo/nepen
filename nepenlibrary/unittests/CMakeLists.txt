cmake_minimum_required(VERSION 2.8)

# Project-Name
PROJECT(NepenLibraryUnitTests)

# C++ Compiler Definitions
add_definitions(-std=c++14)


IF(MINGW)
	set(gtest_disable_pthreads ON)
ENDIF()

add_subdirectory(googletest/googletest)

# set include direcoties
INCLUDE_DIRECTORIES(C:/MinGW/include/
                    ${CMAKE_CURRENT_SOURCE_DIR}/../include/
					)

# set the files to compile
ADD_EXECUTABLE(NepenLibraryUnitTests
                    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/test_nepen.cpp
                    # ${CMAKE_CURRENT_SOURCE_DIR}/test_time.cpp
                )


# set libraries to link with
target_link_libraries(NepenLibraryUnitTests NepenLibrary gtest gtest_main)
