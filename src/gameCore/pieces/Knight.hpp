#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"

/*
 * Representation of knight piece.
 */
class Knight: public Piece
{
    public:

        /*
         * Constructor with specified color and position.
         *
         * @param const Color, player color
         * @param const int, initial knight position
         */
        Knight(const Color, const int);

        /*
         * Get all position where knight can curently move.
         *
         * @param Board, board on which knight is placed
         *
         * @return vector<int>, vector with all positions where
         *      knight can move
         */
        std::vector<int> getAllPossibleMoves(Board);
};

#endif
