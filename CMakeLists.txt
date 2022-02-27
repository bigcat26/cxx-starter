cmake_minimum_required(VERSION 3.10)

include(ExternalProject)
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckSymbolExists)
include(CMakeDependentOption)
include(ExternalProject)
include(cmake/conan.cmake)

project(cxx-scaffold)

option(CONFIG_BUILD_STATIC "Build static library" ON)
option(CONFIG_BUILD_SHARED "Build shared library" ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/prefix CACHE PATH "prefix" FORCE)
endif()

conan_cmake_run(
  REQUIRES
    spdlog/1.9.2
  SETTINGS
    build_type=Release
  PROFILE
    ${CONAN_PROFILE}
  OPTIONS
    spdlog:header_only=True
    ${CONAN_OPTIONS}
  IMPORTS
    lib,*.so*->${CMAKE_INSTALL_PREFIX}/lib
  BASIC_SETUP CMAKE_TARGETS
  BUILD missing
  )

add_subdirectory(lib)
add_subdirectory(app)
