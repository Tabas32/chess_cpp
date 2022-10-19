#include "Board.hpp"
#include "pieces/Piece.hpp"

Board::Board(std::vector<Piece*> pieces)
{
    _pieces = std::vector<Piece*>(64, nullptr);

    for(auto piece : pieces)
    {
        _pieces[piece->possition()] = piece;
    }
}

int Board::calculatePositionFrom
(
        const int originPos,
        const int horizontalDif,
        const int verticalDif
)
{
    auto targetRow = (originPos / 8) + verticalDif;
    auto targetCol = (originPos % 8) + horizontalDif;

    if(targetRow < 0 || targetRow > 7)
    {
        return -1;
    }

    if(targetCol < 0 || targetCol > 7)
    {
        return -1;
    }

    return (targetRow * 8) + targetCol;
}

Piece* Board::getPieceAtPossition(const int possition)
{
    return _pieces[possition];
}
