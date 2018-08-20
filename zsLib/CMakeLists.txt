cmake_minimum_required(VERSION 3.7.2)

option(ZSLIB_STATIC "Build sw lib as a static library" ON)

# Our core file list
if (SW_PLAT_WIN)
	sw_load_sources(zsLibDeps
		EXCLUDE "extras"
		${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.h
	)
else()
	sw_load_sources(zsLibDeps
		${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.h
	)
endif()

# Declare sw lib
if (ZSLIB_STATIC)
	add_library(zsLib STATIC ${zsLibDeps})
	target_compile_definitions(zsLib PUBLIC -DZSLIB_STATIC=1)
else()
	add_library(zsLib SHARED ${zsLibDeps})
endif()

# Setup a useful export file for inclusion in other projects
export(TARGETS zsLib
	FILE zsLibConfig.cmake
	EXPORT_LINK_INTERFACE_LIBRARIES
)

if (SW_PLAT_WIN)
	target_compile_definitions(zsLib PUBLIC -DWIN32_LEAN_AND_MEAN=1)
else()
	target_include_directories(zsLib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/extras)
endif()

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(zsLib PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)

# Include the bin dir for config discovery
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")

# Setup precompiled header
sw_pch(zsLib "zsLib.h")
