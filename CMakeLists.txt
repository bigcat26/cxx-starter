cmake_minimum_required(VERSION 3.10)

include(ExternalProject)
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckSymbolExists)
include(CMakeDependentOption)
include(ExternalProject)

project(cxx-quickstart)

option(CONFIG_BUILD_STATIC "Build static library" ON)
option(CONFIG_BUILD_SHARED "Build shared library" OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif(NOT CMAKE_BUILD_TYPE)

#
# add search path for find_package
#
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(spdlog REQUIRED)
find_package(Catch2 REQUIRED)

add_subdirectory(lib)
add_subdirectory(app)
