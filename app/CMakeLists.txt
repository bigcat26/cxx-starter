project(cxx)

file(GLOB src *)

add_executable(${PROJECT_NAME} ${src})
add_dependencies(${PROJECT_NAME} lib)

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
    lib
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<NOT:$<BOOL:${WIN32}>>:pthread>
)
