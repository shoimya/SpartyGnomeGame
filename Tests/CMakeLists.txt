project(Tests)
set(Test_FILES)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include Google Test directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Tests_run target
add_executable(Tests_run ${TEST_FILES} ItemTest.cpp gtest_main.cpp)

# linking Tests_run with library which will be tested and wxWidgets
target_link_libraries(Tests_run ${APPLICATION_LIBRARY} ${wxWidgets_LIBRARIES} )

# linking Tests_run with the Google Test libraries
target_link_libraries(Tests_run gtest)

target_precompile_headers(Tests_run PRIVATE ../${APPLICATION_LIBRARY}/pch.h)
