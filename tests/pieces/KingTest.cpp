#include <gtest/gtest.h>
#include "../../src/gameCore/pieces/King.hpp"
#include "../../src/gameCore/pieces/Pawn.hpp"
#include <algorithm>

/*
 * - all moves empty board
 * - moves at the edge of the board
 * - moves blocked by ally pieces
 * - moves blocked by enemy pieces
 * - moves blocked by being in check
 */
TEST(PiecesTests, KingAllMovesAvailable)
{
    /* Preparation */
    King king(Color::WHITE, 27);

    std::vector<Piece*> pieces{ &king };
    Board board(pieces);

    std::vector<int> expectedPositions{
        18, 19, 20, 26, 28, 34, 35, 36
    };

    /* Action */
    auto possibleMoves = king.getAllPossibleMoves(board);

    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 8);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

TEST(PiecesTests, KingMovesOutsideOfBoard)
{
    /* Preparation */
    King king(Color::WHITE, 0);

    std::vector<Piece*> pieces{ &king };
    Board board(pieces);

    std::vector<int> expectedPositions{1, 8, 9};

    /* Action */
    auto possibleMoves = king.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 3);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

TEST(PiecesTests, KingMovesWithAllyPieces)
{
    /* Preparation */
    King king1(Color::WHITE, 19);
    King king2(Color::WHITE, 26);

    std::vector<Piece*> pieces{ &king1, &king2 };
    Board board(pieces);

    std::vector<int> expectedPositions{10, 11, 12, 18, 20, 27, 28};

    /* Action */
    auto possibleMoves = king1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 7);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

TEST(PiecesTests, KingMovesWithOponentPieces)
{
    /* Preparation */
    King king(Color::WHITE, 43);
    Pawn pawn(Color::BLACK, 35, -1, false);

    std::vector<Piece*> pieces{ &king, &pawn };
    Board board(pieces);

    std::vector<int> expectedPositions{
        34, 35, 36, 42, 44, 50, 51, 52
    };

    /* Action */
    auto possibleMoves = king.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 8);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

TEST(PiecesTests, KingMovesWithOponentPiecesOmittingCheckMoves)
{
    /* Preparation */
    King king(Color::WHITE, 19);
    Pawn pawn(Color::BLACK, 35, -1, false);

    std::vector<Piece*> pieces{ &king, &pawn };
    Board board(pieces);

    std::vector<int> expectedPositions{
        10, 11, 12, 18, 20, 27
    };

    /* Action */
    auto possibleMoves = king.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 6);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

TEST(PiecesTests, KingIsInCheck)
{
    /* Preparation */
    King king1(Color::WHITE, 17);
    King king2(Color::WHITE, 22);
    Pawn pawn(Color::BLACK, 26, -1, false);

    std::vector<Piece*> pieces{ &king1, &king2, &pawn };
    Board board(pieces);

    /* Action */
    auto king1Check = king1.isInCheck(board);
    auto king2Check = king2.isInCheck(board);

    /* Assertions */
    ASSERT_TRUE(king1Check);
    ASSERT_FALSE(king2Check);
}

