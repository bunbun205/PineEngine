file(GLOB_RECURSE Pine_SOURCE
    src/*.cpp
    src/*.hpp
)

set(PINE_BUILD_SHARED ON)

add_library(Pine SHARED ${Pine_SOURCE})

target_precompile_headers(
    Pine
    PRIVATE
        src/pinepch.hpp
)

target_include_directories(
	Pine
	PRIVATE
		${CMAKE_SOURCE_DIR}/Pine/src
        ${CMAKE_SOURCE_DIR}/extern/spdlog/include
)

set_target_properties(
    Pine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY $(CMAKE_SOURCE_DIR)/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/Pine
    CMAKE_BINARY_DIR $(CMAKE_SOURCE_DIR)/bin-int/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/Pine
    RUNTIME_OUTPUT_DIRECTORY $(CMAKE_SOURCE_DIR)/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/Pine
)
