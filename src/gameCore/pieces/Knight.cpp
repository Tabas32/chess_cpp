#include "Knight.hpp"
#include <iostream>

Knight::Knight(const Color c, const int pos):
    Piece(c, PieceType::KNIGHT, pos)
{}

std::vector<int> Knight::getAllPossibleMoves(Board board)
{
    std::vector<int> allPossibleMoves;

    for
    (
        auto horizontalChange = _possibleMoves.begin();
        horizontalChange != _possibleMoves.end();
        horizontalChange += 2
    )
    {
        const auto verticalChange = horizontalChange + 1;

        auto possibleMove = Board::calculatePositionFrom
        (
            _possition,
            *horizontalChange,
            *verticalChange
        );

        if(possibleMove == -1) { continue; }

        auto otherPiece = board.getPieceAtPossition(possibleMove);

        if(otherPiece == nullptr || otherPiece->color() != _color)
        {
            allPossibleMoves.push_back(possibleMove);
        }
    }
        
    return allPossibleMoves;
}
