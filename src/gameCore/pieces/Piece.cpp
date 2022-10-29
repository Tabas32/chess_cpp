#include "Piece.hpp"

using std::vector;

Piece::Piece(Color c, PieceType t, int p):
    _color(c),
    _type(t),
    _position(p)
{}

bool Piece::movePiece(int newPosition)
{

    //todo: validate movement first
    _position = newPosition;
    return true;
}

vector<int> Piece::getAllPossibleMoves(Board board)
{
    return vector<int>(); 
}

int Piece::position()
{
    return _position;
}

PieceType Piece::type()
{
    return _type;
}

Color Piece::color()
{
    return _color;
}
