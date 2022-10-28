#pragma once

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.hpp"

class Bishop: public Piece
{
    public:
        Bishop(const Color, const int);
        std::vector<int> getAllPossibleMoves(const Board);
};

#endif
