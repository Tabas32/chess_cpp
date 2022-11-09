#include "Bishop.hpp"
#include "PieceMovement.hpp"

Bishop::Bishop(const Color c, const int pos):
    Piece(c, PieceType::BISHOP, pos)
{}

std::vector<int> Bishop::getAllPossibleMoves(Board board)
{
    std::vector<int> allPossibleMoves;
    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
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
