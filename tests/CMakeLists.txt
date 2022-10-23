cmake_minimum_required(VERSION 3.10)

set(Sources
    ExampleTest.cpp
)

add_executable(ChessGameTests ${Sources})
target_link_libraries(ChessGameTests PUBLIC
    gtest_main
    ChessGame
)

add_test(
    NAME ChessGameTests
    COMMAND ChessGameTests
)
