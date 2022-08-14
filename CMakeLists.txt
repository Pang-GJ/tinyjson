cmake_minimum_required(VERSION 3.14...3.23)

project(HelloProject
  VERSION
    1.0
  DESCRIPTION
    "a Hello Project!"
  LANGUAGES
    CXX
)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
  message(FATAL_ERROR "You cannot build in a source directory 
  (or any directory with a CMakeLists.txt file). 
  Please make a build subdirectory. 
  Feel free to remove CMakeCache.txt and CMakeFiles."
  )
endif()

# For clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# Options
option(BUILD_TESTS "Build test executable" OFF)

# TODO: set you target name!
set(LIBRARY_NAME mylib)

# 3rdparty dir:
set(PROJECT_TRDPARTY_DIR ${PROJECT_SOURCE_DIR}/3rdparty)

add_subdirectory(src)

if (BUILD_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(tests)
endif (BUILD_TESTS)

add_subdirectory(example)

# cmake module
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(FormatAndTidy)
