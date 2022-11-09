#include "Rook.hpp"
#include "PieceMovement.hpp"

Rook::Rook(const Color c, const int pos):
    Piece(c, PieceType::ROOK, pos)
{}

std::vector<int> Rook::getAllPossibleMoves(Board board)
{
    std::vector<int> allPossibleMoves;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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
