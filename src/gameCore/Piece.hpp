#ifndef PIECE_H
#define PIECE_H

#include <vector>

/*
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
 */
class Piece {
    public:
        
};

#endif
