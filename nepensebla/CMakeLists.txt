cmake_minimum_required(VERSION 2.8)

# Project-Name
PROJECT(Nepensebla)

#searching for nana
find_package(nana REQUIRED)

# C++ Compiler Definitions
add_definitions(-std=c++14)
add_definitions(-Wall)
add_definitions(-Wextra)


# Nana-Library Definitions
# add_definitions(-DNANA_UNICODE)

# Boost-Definitions
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -DBOOST_NO_AUTO_PTR")

# set debug & release version flags
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")

# set include direcoties
INCLUDE_DIRECTORIES(
                    ${CMAKE_CURRENT_SOURCE_DIR}/../include/
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/
					${CMAKE_CURRENT_SOURCE_DIR}/../nepenlibrary/include/
					# C:/MinGW/include/
					"${nana_INCLUDE_DIRS}"
					)


# set link directories (where the libs are located)
LINK_DIRECTORIES(	${CMAKE_CURRENT_SOURCE_DIR}/../extlib
#					${CMAKE_BINARY_DIR}/bewdb/
					)

# set the files to compile
ADD_EXECUTABLE(Nepensebla
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/nepen_form.cpp
                )


# set libraries to link with
target_link_libraries(Nepensebla
						NepenLibrary
						# boost_program_options
						"${nana_LIBRARY}"
						)
