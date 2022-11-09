#include "Pawn.hpp"
#include "PieceMovement.hpp"

Pawn::Pawn(
    const Color c,
    const int pos,
    const int forvardDirection,
    const bool isInDefaultState
):
    Piece(c, PieceType::PAWN, pos),
    _forvardDirection(forvardDirection),
    _isInDefaultPosition(isInDefaultState)
{}

std::vector<int> Pawn::getAllPossibleMoves(Board board)
{
    std::vector<int> allPossibleMoves;

    int forvardPos = board.calculatePositionFrom(
        _position,
        0,
        _forvardDirection
    );

    if(forvardPos == -1) { return allPossibleMoves; }

    auto forvardPiece = board.getPieceAtPosition(forvardPos);
    if(forvardPiece == nullptr) {
        allPossibleMoves.push_back(forvardPos);
    }

    for(auto hDif : {-1, 1}) {
        int diagonalPos = board.calculatePositionFrom(
            _position,
            hDif,
            _forvardDirection
        );

        auto diagonalPiece = board.getPieceAtPosition(diagonalPos);
        if(diagonalPiece != nullptr &&
            diagonalPiece->color() != _color ||
            board.isShadowPawnAtPosition(diagonalPos)) {

            allPossibleMoves.push_back(diagonalPos);
        }
    }

    if(_isInDefaultPosition) {
        int extForvardPos = board.calculatePositionFrom(
            _position,
            0,
            _forvardDirection * 2
        );

        auto extForvardPiece = board.getPieceAtPosition(
                extForvardPos
        );

        if(extForvardPiece == nullptr) {
            allPossibleMoves.push_back(extForvardPos);
        }
    }

    return allPossibleMoves;
}
