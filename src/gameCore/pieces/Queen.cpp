#include "Queen.hpp"
#include "PieceMovement.hpp"

Queen::Queen(const Color c, const int pos):
    Piece(c, PieceType::QUEEN, pos)
{}

std::vector<int> Queen::getAllPossibleMoves(Board board)
{
    std::vector<int> allPossibleMoves;
    int directions[8][2] = {
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    PieceMovement pm;

    for(auto dir : directions) {
        auto dirMoves = pm.getFlyPossibleMoves(
                board, *this, dir[0], dir[1]
        );

        allPossibleMoves.insert(
                allPossibleMoves.end(),
                dirMoves.begin(),
                dirMoves.end()
        );
    }

    return allPossibleMoves;
}
