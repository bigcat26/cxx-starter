cmake_minimum_required(VERSION 3.15)
project(cxx-quickstart)

include(ExternalProject)
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckSymbolExists)
include(CMakeDependentOption)
include(ExternalProject)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_MAP_IMPORTED_CONFIG_DEBUG RELEASE)
set(CMAKE_FIND_PACKAGE_REDIRECTS_DIR ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})


option(BUILD_STATIC "Build static library" ON)
option(ENABLE_TESTS "Enable tests" ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_MAP_IMPORTED_CONFIG_DEBUG RELEASE)
set(CMAKE_FIND_PACKAGE_REDIRECTS_DIR ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(spdlog REQUIRED)

add_subdirectory(lib)
add_subdirectory(app)

if(ENABLE_TESTS)
  add_subdirectory(tests)
endif()
