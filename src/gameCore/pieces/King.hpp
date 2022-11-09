#ifndef KING_H
#define KING_H

#include "Piece.hpp"

/*
 * Representation of king piece.
 */
class King: public Piece
{
    public:

        /*
         * Constructor with specified color and position.
         *
         * @param Color, player color
         * @param int, initial king position
         */
        King(Color, int);
        
        /*
         * Get all position where king can curently move.
         *
         * @param Board, board on which king is placed
         *
         * @return vector<int>, vector with all positions where
         *      king can move
         */
        std::vector<int> getAllPossibleMoves(Board);
        
        /*
         * Check if king is in check on his current position.
         *
         * @param Board, board on which king is placed
         *
         * @return bool, true if king is in check
         */
        bool isInCheck(Board);
};

#endif
