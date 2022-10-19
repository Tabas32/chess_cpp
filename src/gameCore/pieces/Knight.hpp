#pragma once

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"

class Knight: public Piece
{
    public:
        Knight(const Color, const int);
        std::vector<int> getAllPossibleMoves(const Board);

    private:
        const std::vector<int> _possibleMoves
        {
            1, 2,
            1, -2,
            -1, 2,
            -1, -2,
            2, 1,
            2, -1,
            -2, 1,
            -2, -1
        };
};

#endif
