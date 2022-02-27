project(cxxlib)

file(GLOB_RECURSE src 
  source/*
  interface/*
)

add_library(${PROJECT_NAME}-obj OBJECT ${src})
set_target_properties(${PROJECT_NAME}-obj
  PROPERTIES
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE ON
)

target_compile_features(${PROJECT_NAME}-obj 
  PUBLIC 
    cxx_std_17
)

target_compile_definitions(${PROJECT_NAME}-obj
  PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)

target_include_directories(${PROJECT_NAME}-obj
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)


if(CONFIG_BUILD_STATIC)
  add_library(${PROJECT_NAME}-static STATIC)
  set_target_properties(${PROJECT_NAME}-static PROPERTIES PREFIX lib)
  target_link_libraries(${PROJECT_NAME}-static ${PROJECT_NAME}-obj)
endif()

if(CONFIG_BUILD_SHARED)
  add_library(${PROJECT_NAME}-shared SHARED)
  set_target_properties(${PROJECT_NAME}-shared PROPERTIES PREFIX lib)
  target_link_libraries(${PROJECT_NAME}-shared ${PROJECT_NAME}-obj)
endif()
