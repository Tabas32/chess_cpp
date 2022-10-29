#include "PieceMovement.hpp"

std::vector<int> PieceMovement::getJumpPossibleMoves(
    Board board,
    Piece piece
) {

    std::vector<int> allPossibleMoves;

    for (
        auto horizontalChange = _jumpDifs.begin();
        horizontalChange != _jumpDifs.end();
        horizontalChange += 2
    ) {
        const auto verticalChange = horizontalChange + 1;

        auto possibleMove = Board::calculatePositionFrom(
            piece.position(),
            *horizontalChange,
            *verticalChange
        );

        if(possibleMove == -1) { continue; }

        auto otherPiece = board.getPieceAtPosition(possibleMove);

        if (otherPiece == nullptr ||
            otherPiece->color() != piece.color()) {

            allPossibleMoves.push_back(possibleMove);
        }
    }
        
    return allPossibleMoves;
}

std::vector<int> PieceMovement::getFlyPossibleMoves(
    Board board,
    Piece piece,
    int hDif,
    int vDif
) {
    
    std::vector<int> allPossibleMoves;

    auto possibleMove = board.calculatePositionFrom(
        piece.position(),
        hDif,
        vDif
    );


    while(possibleMove > -1) {
        auto otherPiece = board.getPieceAtPosition(possibleMove);
        if (otherPiece != nullptr) {
            if (otherPiece->color() != piece.color()) {
                allPossibleMoves.push_back(possibleMove);
            }

            return allPossibleMoves;
        }

        allPossibleMoves.push_back(possibleMove);

        possibleMove = board.calculatePositionFrom(
            possibleMove,
            hDif,
            vDif
        );
    }

    return allPossibleMoves;
}

bool PieceMovement::isPositionUnderAttack(
        int pos,
        Board board,
        Color pColor, // my color
        int forvardDirection // my forvard direction
) {
    if(
        isPositionUnderAttackFromPawns(
            pos, board, pColor, forvardDirection
        ) ||
        isPositionUnderAttackFromKnights(pos, board, pColor) ||
        isPositionUnderAttackDiagonalAxis(pos, board, pColor) ||
        isPositionUnderAttackHorizontalVerticalAxis(
            pos, board, pColor
        )
    ) {
        return true;
    }

    return false;
}

bool PieceMovement::isPositionUnderAttackFromPawns(
        int pos,
        Board board,
        Color pColor, // my color
        int forvardDirection // my forvard direction
) {
    std::vector<int> attackingPawnsPositions = {
        board.calculatePositionFrom(pos, 1, forvardDirection),
        board.calculatePositionFrom(pos, -1, forvardDirection),
    };

    for(auto pawnPos : attackingPawnsPositions) {
        if(pawnPos == -1) { continue; }

        auto piece = board.getPieceAtPosition(pawnPos);
        if(piece != nullptr &&
            piece->color() != pColor &&
            piece->type() == PieceType::PAWN
        ) {
            return true;
        }
    }

    return false;
}

bool PieceMovement::isPositionUnderAttackFromKnights(
        int pos,
        Board board,
        Color pColor // my color
) {
    for (
        auto hDif = _jumpDifs.begin();
        hDif != _jumpDifs.end();
        hDif += 2
    ) {
        auto knightPos =
            Board::calculatePositionFrom(pos, *hDif, *(hDif + 1));
        if(knightPos == -1) { continue; }

        auto piece = board.getPieceAtPosition(knightPos);
        if(piece != nullptr &&
            piece->color() != pColor &&
            piece->type() == PieceType::KNIGHT
        ) {
            return true;
        }
    }

    return false;
}

bool PieceMovement::isPositionUnderAttackHorizontalVerticalAxis(
        int pos,
        Board board,
        Color pColor // my color
) {
    std::vector<std::vector<int>> hvAxis{
        std::vector<int>{1,0},
        std::vector<int>{-1,0},
        std::vector<int>{0,1},
        std::vector<int>{0,-1}
    };

    return isPositionUnderAttackFlyingAxis(
        pos,
        hvAxis,
        std::vector<PieceType>{PieceType::QUEEN, PieceType::ROOK},
        board,
        pColor
    );
}

bool PieceMovement::isPositionUnderAttackDiagonalAxis(
        int pos,
        Board board,
        Color pColor // my color
) {
    std::vector<std::vector<int>> dAxis{
        std::vector<int>{1,1},
        std::vector<int>{-1,-1},
        std::vector<int>{-1,1},
        std::vector<int>{1,-1}
    };

    return isPositionUnderAttackFlyingAxis(
        pos,
        dAxis,
        std::vector<PieceType>{PieceType::QUEEN, PieceType::BISHOP},
        board,
        pColor
    );
}

bool PieceMovement::isPositionUnderAttackFlyingAxis(
        int pos,
        std::vector<std::vector<int>> directions,
        std::vector<PieceType> types,
        Board board,
        Color pColor // my color
) {
    auto posUnderValidation = pos;

    for(auto dir : directions) {
        do {
            posUnderValidation = 
                Board::calculatePositionFrom(
                    posUnderValidation, dir[0], dir[1]
                );

            if(posUnderValidation == -1) { break; }

            auto otherPiece = board.getPieceAtPosition(
                posUnderValidation
            );

            if (otherPiece != nullptr &&
                otherPiece->color() != pColor &&
                (otherPiece->type() == types[0] ||
                otherPiece->type() == types[1])
            ) {
                return true;
            }
        } while(posUnderValidation != -1);
    }

    return false;
}

