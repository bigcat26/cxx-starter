project(cxxlib)

file(GLOB_RECURSE src 
  source/*
  interface/*
)

macro(define_library project)
  set_target_properties(${project}
    PROPERTIES
      CXX_STANDARD 11
      CXX_STANDARD_REQUIRED YES
      CXX_EXTENSIONS NO
      POSITION_INDEPENDENT_CODE ON
  )

  target_compile_definitions(${project}
    PRIVATE
      $<$<CONFIG:Debug>:DEBUG>
      $<$<CONFIG:Debug>:_DEBUG>
      $<$<CONFIG:Release>:NDEBUG>
  )

  target_include_directories(${project}
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/interface
  )

  set_target_properties(${project} PROPERTIES PREFIX lib)
endmacro()

if(CONFIG_BUILD_STATIC)
  add_library(${PROJECT_NAME}-static STATIC ${src})
  define_library(${PROJECT_NAME}-static)
endif()

if(CONFIG_BUILD_SHARED)
  add_library(${PROJECT_NAME}-shared SHARED ${src})
  define_library(${PROJECT_NAME}-shared)
  target_link_libraries(${PROJECT_NAME}-shared
    PUBLIC
      $<$<BOOL:${CONFIG_BUILD_SPDLOG}>:spdlog_build>
  )
endif()
