#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.hpp"

/*
 * Representation of bishop piece.
 */
class Bishop: public Piece
{
    public:

        /*
         * Constructor with specified color and position.
         *
         * @param const Color, player color
         * @param const int, initial bishop position
         */
        Bishop(const Color, const int);

        /*
         * Get all position where bishop can curently move.
         *
         * @param Board, board on which bishop is placed
         *
         * @return vector<int>, vector with all positions where
         *      bishop can move
         */
        std::vector<int> getAllPossibleMoves(Board);
};

#endif
