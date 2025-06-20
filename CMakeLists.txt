cmake_minimum_required(VERSION 3.15)
project(cxx-quickstart)

include(CTest)
include(GoogleTest)
include(ExternalProject)
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckSymbolExists)
include(CMakeDependentOption)

include(cmake/GetGitVersion.cmake)
get_git_version(GIT_VERSION)

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

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${GIT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION "A C++ starter project")
set(CPACK_PACKAGE_VENDOR "bigcat26")
set(CPACK_PACKAGE_CONTACT "bigcat26@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A C++ starter project")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/bigcat26/cxx-starter")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")

include(CPack)