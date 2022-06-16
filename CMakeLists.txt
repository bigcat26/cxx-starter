cmake_minimum_required(VERSION 3.10)

include(ExternalProject)
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckSymbolExists)
include(CMakeDependentOption)
include(ExternalProject)
include(cmake/conan.cmake)

project(cxx-quickstart)

option(CONFIG_BUILD_STATIC "Build static library" ON)
option(CONFIG_BUILD_SHARED "Build shared library" ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif(NOT CMAKE_BUILD_TYPE)

conan_cmake_configure(
  REQUIRES
    spdlog/1.9.2
    catch2/2.13.8
  GENERATORS 
    cmake_find_package
  IMPORTS
    lib,*.so*->${CMAKE_BINARY_DIR}/lib
)

conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    SETTINGS 
                      ${settings}
                    PROFILE_HOST
                      default
                    PROFILE_BUILD
                      default
                    OPTIONS
                      spdlog:header_only=True
                      catch2:with_main=True
)

add_subdirectory(lib)
add_subdirectory(app)
