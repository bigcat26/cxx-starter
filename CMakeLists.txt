cmake_minimum_required(VERSION 3.10)

include(ExternalProject)
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckSymbolExists)
include(CMakeDependentOption)
include(ExternalProject)

project(cxx-scaffold)

option(CONFIG_BUILD_STATIC "Build static library" ON)
option(CONFIG_BUILD_SHARED "Build shared library" ON)
option(CONFIG_BUILD_SPDLOG "Build SPDLOG library" OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/prefix CACHE PATH "prefix" FORCE)
endif()

add_subdirectory(third_party)
add_subdirectory(lib)
add_subdirectory(app)
