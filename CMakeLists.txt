cmake_minimum_required(VERSION 3.11)
project(chess_game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_subdirectory(googletest)

#-Core Game--------------------------------------------

set(HeadersGameCore
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

set(SourcesGameCore
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

add_library(ChessGame STATIC ${SourcesGameCore} ${HeadersGameCore})


#-Tui--------------------------------------------

include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v3.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

set(HeadersTui
    src/tui/BoardBuilder.hpp
)

set(SourcesTui
    src/tui/BoardBuilder.cpp
)

add_library(ChessTui STATIC ${SourcesTui} ${HeadersTui})

target_link_libraries(ChessTui
    PRIVATE ftxui::screen
    PUBLIC ftxui::dom
    PRIVATE ftxui::component
)

target_link_libraries(ChessGame
    PUBLIC ftxui::dom
)


#-Main--------------------------------------------

add_executable(ChessGameExec src/main.cpp)
#target_include_directories(ChessGameExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(ChessGameExec
    PUBLIC ChessGame
    PUBLIC ChessTui
)

add_subdirectory(tests)
