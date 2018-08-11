cmake_minimum_required(VERSION 3.7.2)

# Our core file list
sw_load_sources(zsLibTestDeps
	EXCLUDE ${EXLUDED_FOLDERS}
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

# Declare the executable
add_executable(zsLibTest ${zsLibTestDeps})

# Link to zsLib
target_link_libraries(zsLibTest PRIVATE zsLib)

# Setup precompiled header
sw_pch(zsLibTest "testing.h")
