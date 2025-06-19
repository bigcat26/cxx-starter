include(GoogleTest)

enable_testing()
find_package(GTest REQUIRED)

file(GLOB src *.cc)

foreach(file ${src})
    get_filename_component(progname ${file} NAME_WE)

    add_executable(${progname} ${file})
    target_link_libraries(${progname} PRIVATE GTest::gtest_main GTest::gmock_main)
    target_compile_definitions(${progname} 
        PRIVATE 
            CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
            SOURCE_DIR="${CMAKE_SOURCE_DIR}" 
            )

    set_property(TARGET ${progname} PROPERTY CXX_STANDARD 20)
    set_property(TARGET ${progname} PROPERTY CXX_STANDARD_REQUIRED YES)
    set_property(TARGET ${progname} PROPERTY CXX_EXTENSIONS YES)
    set_property(TARGET ${progname} PROPERTY POSITION_INDEPENDENT_CODE ON)

    add_test(NAME ${progname} COMMAND $<TARGET_FILE:${progname}>)
    gtest_discover_tests(${progname})

endforeach(file ${src})
