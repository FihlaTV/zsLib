cmake_minimum_required(VERSION 3.7.2)

option(ZSLIB_STATIC "Build sw lib as a static library" ON)

# Our core file list
if (SW_PLAT_WIN)
	message("Loading without extras")
	sw_load_sources(zsLibDeps
		EXCLUDE "extras"
		${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.h
	)
else()
	message("Loading with extras")
	sw_load_sources(zsLibDeps
		EXCLUDE "gen_uuid_nt.c"
		${CMAKE_CURRENT_SOURCE_DIR}/*.c
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

	# Perform posix config
	sw_target_check_include_file(zsLib PRIVATE unistd.h HAVE_UNISTD_H)
	sw_target_check_include_file(zsLib PRIVATE stdlib.h HAVE_STDLIB_H)
	sw_target_check_include_file(zsLib PRIVATE sys/time.h HAVE_SYS_TIME_H)
	sw_target_check_include_file(zsLib PRIVATE sys/file.h HAVE_SYS_FILE_H)
	sw_target_check_include_file(zsLib PRIVATE sys/ioctl.h HAVE_SYS_IOCTL_H)
	sw_target_check_include_file(zsLib PRIVATE sys/socket.h HAVE_SYS_SOCKET_H)
	sw_target_check_include_file(zsLib PRIVATE sys/un.h HAVE_SYS_UN_H)
	sw_target_check_include_file(zsLib PRIVATE sys/sockio.h HAVE_SYS_SOCKIO_H)
	sw_target_check_include_file(zsLib PRIVATE net/if.h HAVE_NET_IF_H)
	sw_target_check_include_file(zsLib PRIVATE netinet/in.h HAVE_NETINET_IN_H)
	sw_target_check_include_file(zsLib PRIVATE net/if_dl.h HAVE_NET_IF_DL_H)
	sw_target_check_include_file(zsLib PRIVATE sys/syscall.h HAVE_SYS_SYSCALL_H)
	sw_target_check_include_file(zsLib PRIVATE sys/resource.h HAVE_SYS_RESOURCE_H)
	sw_target_check_function_exists(zsLib PRIVATE getrlimit HAVE_GETRLIMIT)
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
