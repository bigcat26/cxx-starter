project(app)

file(GLOB src *)

add_executable(${PROJECT_NAME} ${src})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED YES)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS YES)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    cxxlib-static
    spdlog::spdlog_header_only
    Catch2::Catch2
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<NOT:$<BOOL:${WIN32}>>:pthread>
)
