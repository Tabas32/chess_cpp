#include "Piece.hpp"

using std::vector;

Piece::Piece(Color c, PieceType t, int p):
    _color(c),
    _type(t),
    _possition(p)
{}

/**
 * todo: validate movement first
 */
bool Piece::movePiece(int newPossition)
{
    _possition = newPossition;
    return true;
}

vector<int> Piece::getAllPossibleMoves(Board board)
{
    return vector<int>(); 
}

int Piece::possition()
{
    return _possition;
}

PieceType Piece::type()
{
    return _type;
}

Color Piece::color()
{
    return _color;
}
