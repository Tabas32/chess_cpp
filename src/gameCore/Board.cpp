#include "Board.hpp"
#include "pieces/Piece.hpp"

#include <iostream>

Board::Board(std::vector<Piece*> pieces):
    _forvardDirectionWhite(1),
    _forvardDirectionBlack(-1)
{
    _pieces = std::vector<Piece*>(64, nullptr);

    for(auto piece : pieces)
    {
        _pieces[piece->position()] = piece;
    }
}

Board::Board(std::vector<Piece*> pieces, int forvardDirectionWhite):
    _forvardDirectionWhite(forvardDirectionWhite),
    _forvardDirectionBlack(-forvardDirectionWhite)
{
    _pieces = std::vector<Piece*>(64, nullptr);

    for(auto piece : pieces)
    {
        _pieces[piece->position()] = piece;
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

Piece* Board::getPieceAtPosition(const int position)
{
    return _pieces[position];
}

bool Board::isShadowPawnAtPosition(int position) {
    for(auto sPawn : _shadowPawns) {
        if(sPawn._position == position && sPawn._age < 2) {
            return true;
        }
    }

    return false;
}

int Board::getForvardDirection(Color color) {
    return (color == Color::WHITE) 
        ? _forvardDirectionWhite
        : _forvardDirectionBlack;
}

bool Board::makeMove(int fromPosition, int toPosition) {
    if (_pieces[fromPosition] == nullptr) {
        return false;
    }

    if (
        _pieces[toPosition] != nullptr && 
        (_pieces[fromPosition]->color() == _pieces[toPosition]->color())
    ) {
        return false;
    }

    auto possibleMoves = _pieces[fromPosition]->getAllPossibleMoves(*this);

    for(auto possibleMove : possibleMoves) {
        if (possibleMove == toPosition) {
            _pieces[fromPosition]->movePiece(toPosition);
            _pieces[toPosition] = _pieces[fromPosition];
            _pieces[fromPosition] = nullptr;

            return true;
        }
    }

    return false;
}
