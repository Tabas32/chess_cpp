#include <iostream>
#include <vector>

#include "gameCore/pieces/Knight.hpp"

int main() {
    Knight knight = Knight(Color::WHITE, 10);
    std::vector<Piece*> boardPieces{&knight};

    Board board(boardPieces);

    for(auto move : knight.getAllPossibleMoves(board))
    {
        std::cout << move << std::endl;
    }

    return 0;
}
