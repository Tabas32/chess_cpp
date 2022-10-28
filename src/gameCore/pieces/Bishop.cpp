#include "Bishop.hpp"
#include <iostream>

Bishop::Bishop(const Color c, const int pos):
    Piece(c, PieceType::BISHOP, pos)
{}

std::vector<int> Bishop::getAllPossibleMoves(Board board)
{
    std::vector<int> allPossibleMoves;

    //todo implement
    return allPossibleMoves;
}
