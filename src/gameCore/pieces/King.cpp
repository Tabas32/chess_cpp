#include "King.hpp"
#include "PieceMovement.hpp"

using std::vector;

King::King(Color c, int pos):
    Piece(c, PieceType::KING, pos)
{}

vector<int> King::getAllPossibleMoves(Board board)
{
    PieceMovement pm;
    std::vector<int> allPossibleMoves;
    int directions[8][2] = {
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    for(auto dir : directions) {
        auto possibleMove = board.calculatePositionFrom(
            _position,
            dir[0],
            dir[1]
        );

        if(possibleMove == -1) { continue; }

        auto otherPiece = board.getPieceAtPosition(possibleMove);
        if((otherPiece == nullptr ||
            otherPiece->color() != _color) &&
            !pm.isPositionUnderAttack(
                possibleMove, board, _color, 1
            )
        ) {
            allPossibleMoves.push_back(possibleMove);
        }
    }

    return allPossibleMoves;
}

bool King::isInCheck(Board board)
{
    return PieceMovement().isPositionUnderAttack(
        _position,
        board,
        _color,
        board.getForvardDirection(_color)
    );
}

