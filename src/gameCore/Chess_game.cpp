#include "Chess_game.hpp"
#include <iostream>

#include <vector>
#include <regex>

#include "pieces/Bishop.hpp"
#include "pieces/King.hpp"
#include "pieces/Knight.hpp"
#include "pieces/Pawn.hpp"
#include "pieces/Queen.hpp"
#include "pieces/Rook.hpp"
#include "../tui/BoardBuilder.hpp"

int Chess_game::play() {
    std::cout << "Game begun" << std::endl;

    // WHITE
    Bishop bW1 = Bishop(Color::WHITE, 2);
    Bishop bW2 = Bishop(Color::WHITE, 5);
    King kW = King(Color::WHITE, 3);
    Knight nW1 = Knight(Color::WHITE, 1);
    Knight nW2 = Knight(Color::WHITE, 6);
    Queen qW = Queen(Color::WHITE, 4);
    Rook rW1 = Rook(Color::WHITE, 0);
    Rook rW2 = Rook(Color::WHITE, 7);

    Pawn pW1 = Pawn(Color::WHITE, 8, 1);
    Pawn pW2 = Pawn(Color::WHITE, 9, 1);
    Pawn pW3 = Pawn(Color::WHITE, 10, 1);
    Pawn pW4 = Pawn(Color::WHITE, 11, 1);
    Pawn pW5 = Pawn(Color::WHITE, 12, 1);
    Pawn pW6 = Pawn(Color::WHITE, 13, 1);
    Pawn pW7 = Pawn(Color::WHITE, 14, 1);
    Pawn pW8 = Pawn(Color::WHITE, 15, 1);
    
    // BLACK
    Bishop bB1 = Bishop(Color::BLACK, 58);
    Bishop bB2 = Bishop(Color::BLACK, 61);
    King kB = King(Color::BLACK, 59);
    Knight nB1 = Knight(Color::BLACK, 57);
    Knight nB2 = Knight(Color::BLACK, 62);
    Queen qB = Queen(Color::BLACK, 60);
    Rook rB1 = Rook(Color::BLACK, 56);
    Rook rB2 = Rook(Color::BLACK, 63);

    Pawn pB1 = Pawn(Color::BLACK, 48, -1);
    Pawn pB2 = Pawn(Color::BLACK, 49, -1);
    Pawn pB3 = Pawn(Color::BLACK, 50, -1);
    Pawn pB4 = Pawn(Color::BLACK, 51, -1);
    Pawn pB5 = Pawn(Color::BLACK, 52, -1);
    Pawn pB6 = Pawn(Color::BLACK, 53, -1);
    Pawn pB7 = Pawn(Color::BLACK, 54, -1);
    Pawn pB8 = Pawn(Color::BLACK, 55, -1);

    std::vector<Piece*> boardPieces{
        &rW1, &nW1, &bW1, &kW, &qW, &bW2, &nW2, &rW2,
        &pW1, &pW2, &pW3, &pW4, &pW5, &pW6, &pW7, &pW8,

        &pB1, &pB2, &pB3, &pB4, &pB5, &pB6, &pB7, &pB8,
        &rB1, &nB1, &bB1, &kB, &qB, &bB2, &nB2, &rB2
    };

    Board board(boardPieces);

    std::regex inputPattern("([a-h])([1-8]) ([a-h])([1-8])");
    std::smatch inputMatch;

    BoardBuilder bb;
    bb.buildBoard(&board, [&](ftxui::Event event) {
        if (event == ftxui::Event::Return) {
            //std::cout << "Submitted text: " << bb.move << std::endl;
            // translate 'move' input and do appropriate board move
            int fromColumn, fromRow, toColumn, toRow = 0;

            if (
                std::regex_match(bb.move, inputMatch, inputPattern) &&
                inputMatch.size() == 5
            ) {
                fromColumn = static_cast<std::string>(inputMatch[1])[0] - 'a';
                fromRow = 8 - std::stoi(inputMatch[2]);
                int fromPosition = fromRow * 8 + fromColumn;

                toColumn = static_cast<std::string>(inputMatch[3])[0] - 'a';
                toRow = 8 - std::stoi(inputMatch[4]);
                int toPosition = toRow * 8 + toColumn;

                board.makeMove(fromPosition, toPosition);
                bb.move = "";
            }

            return true;
        }

        return false;
    });

    return 0;
}
