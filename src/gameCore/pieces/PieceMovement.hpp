#ifndef PIECE_MOVEMENT_H
#define PIECE_MOVEMENT_H

#include <vector>
#include "../Board.hpp"
#include "Piece.hpp"

/*
 * Class contains utility functions for obtaining information
 * about positions, for most common types of movement.
 */
class PieceMovement {

    public:

        /*
         * Get available 'knight like jump move' positions
         * for piece based on board it is placed on.
         *
         * @param Board, board with all pieces
         * @param Piece, piece for which moves are calucated
         *
         * @return vector<int> all available jump moves
         */
        std::vector<int> getJumpPossibleMoves(Board, Piece);

        /*
         * Get available 'fly move' positions in specified
         * direction for piece based on board it is placed on.
         *
         * @param Board, board with all pieces
         * @param Piece, piece for which moves are calucated
         * @param int, horizontal axis diference (right=1, left=-1) 
         * @param int, vertical axi diference (up=1, down=-1)
         *
         * @return vector<int> all available fly moves
         */
        std::vector<int> getFlyPossibleMoves(
                Board,
                Piece,
                int,
                int
        );

        /*
         * Check if any oponent piece is attacking position.
         *
         * @param int, position that is being checked for attack
         * @param Board, board with all pieces
         * @param Color, color of player that is performing check
         *      (so attacking pieces are oposite of this color)
         * @param int, forvard direction of player that is perfoming
         *      check (so attacking pawns have oposite forvard dir)
         */
        bool isPositionUnderAttack(int, Board, Color, int);

    private:
        const std::vector<int> _jumpDifs{
            1, 2,
            1, -2,
            -1, 2,
            -1, -2,
            2, 1,
            2, -1,
            -2, 1,
            -2, -1
        };

        bool isPositionUnderAttackFromPawns(int, Board, Color, int);
        bool isPositionUnderAttackFromKnights(int, Board, Color);
        bool isPositionUnderAttackDiagonalAxis(int, Board, Color);
        bool isPositionUnderAttackHorizontalVerticalAxis(
            int, Board, Color
        );

        bool isPositionUnderAttackFlyingAxis(
            int,
            std::vector<std::vector<int>>,
            std::vector<PieceType>,
            Board,
            Color
        );
};

#endif
