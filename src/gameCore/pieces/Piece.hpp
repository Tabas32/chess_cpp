#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "../Board.hpp"
#include "../enums/PieceType.hpp"
#include "../enums/Color.hpp"

/*
 * todo remove
 * Official movement notation
 * K - king
 * Q - queen
 * B - bishop
 * N - knight
 * R - rook
 * none - pawn
 *
 * then where to move (e.g. d4)
 * if piece was taken that 'x' is before position
 * if king is in check than '+' is in the end
 *
 * kingside castling 0-0
 * queensize castling 0-0-0
 *
 * examples:
 * e4
 * e5
 * Nc3
 * Nf6
 * dxe4 - pawn from d5 took piece on e4
 * fxe5 - pawn from f4 took peice on e5
 * Bxc7 - bishop took piece on c7
 * Qg6+ - queen is moved to g6 and now king is in check
 * Rhb8 - both rooks can move to b8, but this shows that rook that was on 'h'
 *        is actualy moved
 * b8=Q - promoting pawn to queen
 *
 *
 * Representation of chess piece. All pieces on chess
 * board needs to inherit from this class.
 */
class Piece
{
    public:

        /*
         * Constructor with specified color and position.
         *
         * @param Color, player color
         * @param PieceType, type of constructed piece
         * @param int, initial position
         */
        Piece(Color, PieceType, int);

        /*
         * Get all position where piece can curently move.
         * Default implementation return empty vector. All pieces
         * should owerload this function.
         *
         * @param Board, board on which piece is placed
         *
         * @return vector<int>, vector with all positions where
         *      piece can move
         */
        virtual std::vector<int> getAllPossibleMoves(Board);

        /*
         * Change position of piece.
         *
         * @param int, position where to move
         *
         * @return bool, true if piece was moved
         */
        bool movePiece(int);

        /*
         * Get position of piece.
         *
         * @return int, _position
         */
        int position();

        /*
         * Get type of piece.
         *
         * @return PieceType, _type
         */
        PieceType type();

        /*
         * Get color of piece.
         *
         * @return Color, _color
         */
        Color color();

    protected:
        int _position;
        PieceType _type;
        Color _color;
};

#endif
