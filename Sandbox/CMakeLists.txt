file(GLOB_RECURSE Sandbox_SOURCE
    src/*.cpp
    src/*.hpp
)

add_executable(Sandbox ${Sandbox_SOURCE})

target_include_directories(
	Sandbox
	PRIVATE
		${CMAKE_SOURCE_DIR}/Pine/src
)

target_link_libraries(Sandbox Pine)

set_target_properties(
    Pine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY $(CMAKE_SOURCE_DIR)/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/Pine
    CMAKE_BINARY_DIR $(CMAKE_SOURCE_DIR)/bin-int/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/Pine
    RUNTIME_OUTPUT_DIRECTORY $(CMAKE_SOURCE_DIR)/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/Pine
)