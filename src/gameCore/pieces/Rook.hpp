#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"

/*
 * Representation of rook piece.
 */
class Rook: public Piece
{
    public:

        /*
         * Constructor with specified color and position.
         *
         * @param const Color, player color
         * @param const int, initial rook position
         */
        Rook(const Color, const int);

        /*
         * Get all position where rook can curently move.
         *
         * @param Board, board on which rook is placed
         *
         * @return vector<int>, vector with all positions where
         *      rook can move
         */
        std::vector<int> getAllPossibleMoves(Board);
};

#endif
