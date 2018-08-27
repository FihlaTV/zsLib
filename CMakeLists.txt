cmake_minimum_required(VERSION 3.7.2)

# Declare our project and version
project(zsLib VERSION 1.0 LANGUAGES C CXX)

# Load the zsLib library
add_subdirectory(zsLib)

# Load the zsLib test suite
add_subdirectory(zsLibTest)
