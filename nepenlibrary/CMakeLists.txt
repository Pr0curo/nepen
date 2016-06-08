cmake_minimum_required(VERSION 3.3)

# Project-Name
PROJECT(NepenLibrary)

# C++ Compiler Definitions
add_definitions(-std=c++14)
add_definitions(-Wall)


# set debug & release version flags
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")


# set include direcoties
INCLUDE_DIRECTORIES(C:/MinGW/include/
					${CMAKE_CURRENT_SOURCE_DIR}/include/
                    ${CMAKE_CURRENT_SOURCE_DIR}/date/
					)

# set the files to compile
ADD_LIBRARY(NepenLibrary
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/nepen.cpp
                    )

add_subdirectory(unittests)



# set libraries to link with
target_link_libraries(NepenLibrary boost_regex)

