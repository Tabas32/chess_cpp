#include <iostream>
#include <vector>

#include "gameCore/pieces/Knight.hpp"
#include "tui/BoardBuilder.hpp"

int main() {
    Knight knight = Knight(Color::WHITE, 10);
    std::vector<Piece*> boardPieces{&knight};

    Board board(boardPieces);

    BoardBuilder bb;
    bb.buildBoard(&board);

    return 0;
}
