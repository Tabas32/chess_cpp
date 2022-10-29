#include "Knight.hpp"
#include "PieceMovement.hpp"

Knight::Knight(const Color c, const int pos):
    Piece(c, PieceType::KNIGHT, pos)
{}

std::vector<int> Knight::getAllPossibleMoves(Board board)
{
    PieceMovement pm;
    return pm.getJumpPossibleMoves(board, *this);
}
