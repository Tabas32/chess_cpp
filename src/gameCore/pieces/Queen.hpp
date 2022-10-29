#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"

/*
 * Representation of queen piece.
 */
class Queen: public Piece
{
    public:

        /*
         * Constructor with specified color and position.
         *
         * @param const Color, player color
         * @param const int, initial queen position
         */
        Queen(const Color, const int);

        /*
         * Get all position where queen can curently move.
         *
         * @param Board, board on which queen is placed
         *
         * @return vector<int>, vector with all positions where
         *      queen can move
         */
        std::vector<int> getAllPossibleMoves(Board);
};

#endif
