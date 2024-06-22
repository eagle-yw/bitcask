include(FetchContent)

FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE  TEST_SRC_FILES "./*.cpp")

add_executable(test ${TEST_SRC_FILES})
target_link_libraries(test gtest_main bitcask)
add_test(NAME example_test COMMAND test)