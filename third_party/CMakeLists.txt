
if(CONFIG_BUILD_SPDLOG)
  ExternalProject_Add(spdlog_build
    GIT_URL https://github.com/gabime/spdlog.git
    GIT_TAG v1.8.5
    CMAKE_ARGS
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
      -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
      -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
      -DSPDLOG_BUILD_EXAMPLE=OFF
    TEST_COMMAND ""
  )
endif()
