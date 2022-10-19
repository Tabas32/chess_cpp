#pragma once

#ifndef KING_H
#define KING_H

#include "Piece.hpp"

class King: public Piece
{
    public:
        King(Color, int);
        King(Color, int, Board);
        
        std::vector<int> getAllPossibleMoves(Board);
        bool isInCheck();

    private:
        bool _isInCheck;

        bool isInCheck(Board);
};

#endif
