#include <gtest/gtest.h>
#include "../../src/gameCore/pieces/Queen.hpp"
#include <algorithm>

//todo : rewrite doc

/*
 * Test calculation of all possible moves of queen,
 * when nothing is in a way.
 *
 * Expected result: getAllPossibleMoves function should
 *      return all available positions.
 */
TEST(PiecesTests, QueenpAllMovesAvailable)
{
    /* Preparation */
    Queen queen(Color::WHITE, 27);

    std::vector<Piece*> pieces{ &queen };
    Board board(pieces);

    std::vector<int> expectedPositions{
        0, 9, 18,
        19, 11, 3,
        20, 13, 6,
        28, 29, 30, 31,
        36, 45, 54, 63,
        35, 43, 51, 59,
        34, 41, 48,
        24, 25, 26
    };

    /* Action */
    auto possibleMoves = queen.getAllPossibleMoves(board);

    std::sort(possibleMoves.begin(), possibleMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 27);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of queen,
 * when queen is close to edge of chess board.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting illegal positions
 *      outsize of board.
 */
TEST(PiecesTests, QueenMovesOutsideOfBoard)
{
    /* Preparation */
    Queen queen(Color::WHITE, 0);

    std::vector<Piece*> pieces{ &queen };
    Board board(pieces);

    std::vector<int> expectedPositions{
        1, 2, 3, 4, 5, 6, 7,
        9, 18, 27, 36, 45, 54, 63,
        8, 16, 24, 32, 40, 48, 56
    };

    /* Action */
    auto possibleMoves = queen.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 21);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of queen,
 * when queen movement is blocked by pieces of same color
 * as queen.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting position
 *      which other pieces are blocking.
 */
TEST(PiecesTests, QueenMovesWithAllyPieces)
{
    /* Preparation */
    Queen queen1(Color::WHITE, 19);
    Queen queen2(Color::WHITE, 26);
    Queen queen3(Color::WHITE, 46);
    Queen queen4(Color::WHITE, 35);

    std::vector<Piece*> pieces{ &queen1, &queen2, &queen3, &queen4 };
    Board board(pieces);

    std::vector<int> expectedPositions{
        16, 17, 18, 27, 28, 37, 20, 21, 22, 23, 12, 5,  11, 3, 10, 1
    };

    /* Action */
    auto possibleMoves = queen1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 16);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of queen,
 * when oponent pieces are on target positions.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions including position on
 *      which other pieces are standing, but omitting all
 *      the positions behing other piece, that should be
 *      blocked.
 */
TEST(PiecesTests, QueenMovesWithOponentPieces)
{
    /* Preparation */
    Queen queen1(Color::WHITE, 19);
    Queen queen2(Color::BLACK, 26);
    Queen queen3(Color::BLACK, 46);
    Queen queen4(Color::BLACK, 35);

    std::vector<Piece*> pieces{ &queen1, &queen2, &queen3, &queen4 };
    Board board(pieces);

    std::vector<int> expectedPositions{
        16, 17, 18, 26, 27, 35, 28, 37, 46, 20,
        21, 22, 23, 12, 5,  11, 3, 10, 1
    };

    /* Action */
    auto possibleMoves = queen1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 19);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}
