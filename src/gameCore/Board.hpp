#pragma once

#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Piece;

class Board
{
    public:
        Board(std::vector<Piece*>);

        static int calculatePositionFrom
        (
            const int,
            const int,
            const int
        );

        Piece* getPieceAtPossition(const int);

    private:
        std::vector<Piece*> _pieces;
};

#endif
