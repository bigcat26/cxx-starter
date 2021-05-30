project(cxxlib)

file(GLOB_RECURSE src 
  source/*
  interface/*
)

add_library(${PROJECT_NAME} ${src})

add_dependencies(${PROJECT_NAME}
  $<$<CONFIG_BUILD_SPDLOG>:spdlog_build>
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE ON
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    cjson
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)

install(
  TARGETS 
    ${PROJECT_NAME} 
  ARCHIVE DESTINATION 
    lib
)

install(
  DIRECTORY
    ${PROJECT_SOURCE_DIR}/interface
  DESTINATION 
    include
)
