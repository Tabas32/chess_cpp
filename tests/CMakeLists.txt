cmake_minimum_required(VERSION 3.10)

set(Sources
    ExampleTest.cpp
    pieces/KnightTest.cpp
    pieces/BishopTest.cpp
    pieces/QueenTest.cpp
    pieces/RookTest.cpp
    pieces/PawnTest.cpp
    pieces/KingTest.cpp
)

set(CMAKE_BUILD_TYPE Debug)

add_executable(ChessGameTests ${Sources})
target_link_libraries(ChessGameTests PUBLIC
    gtest_main
    ChessGame
)

add_test(
    NAME ChessGameTests
    COMMAND ChessGameTests
)
