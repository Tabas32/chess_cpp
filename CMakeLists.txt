cmake_minimum_required(VERSION 3.10)
project(chess_game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_subdirectory(googletest)

set(Headers
    src/gameCore/Chess_game.hpp
    src/gameCore/Board.hpp
    src/gameCore/pieces/Piece.hpp
    src/gameCore/pieces/PieceMovement.hpp
    src/gameCore/pieces/King.hpp
    src/gameCore/pieces/Knight.hpp
    src/gameCore/pieces/Bishop.hpp
    src/gameCore/pieces/Queen.hpp
    src/gameCore/pieces/Rook.hpp
    src/gameCore/pieces/Pawn.hpp
)

set(Sources
    src/gameCore/Chess_game.cpp
    src/gameCore/Board.cpp
    src/gameCore/pieces/Piece.cpp
    src/gameCore/pieces/PieceMovement.cpp
    src/gameCore/pieces/King.cpp
    src/gameCore/pieces/Knight.cpp
    src/gameCore/pieces/Bishop.cpp
    src/gameCore/pieces/Queen.cpp
    src/gameCore/pieces/Rook.cpp
    src/gameCore/pieces/Pawn.cpp
)

add_library(ChessGame STATIC ${Sources} ${Headers})

add_executable(ChessGameExec src/main.cpp)
#target_include_directories(ChessGameExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(ChessGameExec PUBLIC ChessGame)

add_subdirectory(tests)
