#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "enums/Color.hpp"

class Piece;

/*
 * Representation of chess board.
 * Holds all pieces, and provided common functions
 * for orientation on it.
 */
class Board
{
    public:

        /*
         * Basic constructor.
         *
         * @param vector<Piece*>, vector of pieces on board
         */
        Board(std::vector<Piece*>);

        /*
         * Constructor specifying sides of players.
         *
         * @param vector<Piece*>, vector of pieces on board
         * @param int forvard direction of white pieces
         */
        Board(std::vector<Piece*>, int);

        /*
         * Get position by combining 'original postion' with
         * horizontal and vertical diferences.
         *
         * @param int, original position (from 0 to 63)
         * @param int, horizontal difference
         * @param int, vertical difference
         *
         * @return int, new calculated position (from 0 to 63),
         *      or -1 if calculated postion is out of board
         */
        static int calculatePositionFrom
        (
            const int,
            const int,
            const int
        );

        /*
         * Get piece standing on position.
         *
         * @param const int, position on board
         *
         * @return Piece*, piece at specified position or nullptr
         */
        Piece* getPieceAtPosition(const int);

        /*
         * Check if position contains pawn shadow (en passant).
         *
         * @param int, position on board
         *
         * @return bool, true if there is pawn shadow on position
         */
        bool isShadowPawnAtPosition(int);

        /*
         * Get forvard direction of player with specified color.
         *
         * @param Color, player color
         *
         * @return int, direction of player (-1 or 1)
         */
        int getForvardDirection(Color);

        /*
         * Move piece from postion (param 1) to different possition (param 2).
         * If move was performed return true
         */
        bool makeMove(int, int);

    private:

        /*
         * Representation of pawn shadow (en passant).
         */
        struct ShadowPawn
        {
            int _position = -1;
            int _age = -1;

            /*
             * Basic constructor.
             *
             * @param int, position of pawn shadow
             * @param int, age, how many turns is shadow on board
             *      (it is recomendet to start with 0)
             */
            ShadowPawn(int pos, int age):
                _position(pos),
                _age(age)
            {};
        };
        
        std::vector<Piece*> _pieces;
        std::vector<ShadowPawn> _shadowPawns;
        int _forvardDirectionWhite;
        int _forvardDirectionBlack;
};


#endif
