cmake_minimum_required(VERSION 3.10)
project(chess_game)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(googletest)

set(Headers
    src/gameCore/Chess_game.hpp
    src/gameCore/Piece.hpp
)

set(Sources
    src/gameCore/Chess_game.cpp
)

add_library(ChessGame STATIC ${Sources} ${Headers})

add_executable(ChessGameExec src/main.cpp)
#target_include_directories(ChessGameExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(ChessGameExec PUBLIC ChessGame)

add_subdirectory(tests)
