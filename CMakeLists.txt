# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(audiovolume)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/audio.cpp
    src/main.cpp
)

# Add an executable with the above sources
add_executable(audiovolume ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(audiovolume
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/includes
)

# Specify the output directory for the executable
set_target_properties(audiovolume PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Print out compiler ID
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")

# Set compiler and linker optimization flags for Release build
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(audiovolume PRIVATE "-Os" "-flto")
    endif()

    # Set linker optimization flags
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        set_target_properties(audiovolume PROPERTIES LINK_FLAGS "-flto")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set_target_properties(audiovolume PROPERTIES LINK_FLAGS "-flto=thin")
    endif()
endif()