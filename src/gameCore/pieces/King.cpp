#include "King.hpp"

using std::vector;

King::King(Color c, int pos):
    Piece(c, PieceType::KING, pos),
    _isInCheck(false)
{}

King::King(Color c, int pos, Board board):
    Piece(c, PieceType::KING, pos),
    _isInCheck(isInCheck(board))
{}

vector<int> King::getAllPossibleMoves(Board board)
{
    return vector<int>{1,2,3};
}

bool King::isInCheck()
{
    return _isInCheck;
}

bool King::isInCheck(Board board)
{
    return false;
}
