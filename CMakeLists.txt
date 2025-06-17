cmake_minimum_required(VERSION 3.21)
project(PineEngine)

set(CMAKE_CXX_STANDARD 20)

if(WIN32)
	set(PINE_PLATFORM_WINDOWS ON)
endif()

find_package(glfw3 REQUIRED)

add_subdirectory(Pine)
add_subdirectory(Sandbox)