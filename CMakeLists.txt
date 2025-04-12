cmake_minimum_required(VERSION 3.14)
project(TodoListTDD)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

add_executable(test_todo
    todo.cpp
    test_todo.cpp
)

target_link_libraries(test_todo gtest_main)

include(GoogleTest)
gtest_discover_tests(test_todo)
