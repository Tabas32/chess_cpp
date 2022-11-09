#ifndef PAWN_H
#define PAWN_H

#include "Piece.hpp"

/*
 * Representation of pawn piece.
 */
class Pawn: public Piece
{
    public:

        /*
         * Constructor.
         *
         * @param const Color, player color
         * @param const int, initial pawn position
         * @param const int, pawn forvard direction (1 or -1)
         * @param const bool, mark that pawn in in default position,
         *      from which it can move 2 steps, by default is true
         */
        Pawn(
            const Color,
            const int,
            const int,
            const bool = true
        );

        /*
         * Get all position where pawn can curently move.
         *
         * @param Board, board on which pawn is placed
         *
         * @return vector<int>, vector with all positions where
         *      pawn can move
         */
        std::vector<int> getAllPossibleMoves(Board);

    private:
        const int _forvardDirection;
        bool _isInDefaultPosition;
};

#endif
