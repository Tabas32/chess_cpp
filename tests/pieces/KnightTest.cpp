#include <gtest/gtest.h>
#include "../../src/gameCore/pieces/Knight.hpp"
#include <algorithm>

/*
 * Test calculation of all possible moves of knight,
 * when nothing is in a way.
 *
 * Expected result: getAllPossibleMoves function should
 *      return 8 available positions.
 */
TEST(PiecesTests, KnightAllMovesAvailable)
{
    /* Preparation */
    Knight knight(Color::WHITE, 19);

    std::vector<Piece*> pieces{ &knight };
    Board board(pieces);

    std::vector<int> expectedPossitions{2, 4, 9, 13, 25, 29, 34, 36};

    /* Action */
    auto possibleMoves = knight.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 8);
    ASSERT_TRUE(possibleMoves == expectedPossitions);
}

/*
 * Test calculation of all possible moves of knight,
 * when knight is close to edge of chess board.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting illegal positions
 *      outsize of board.
 */
TEST(PiecesTests, KnightMovesOutsideOfBoard)
{
    /* Preparation */
    Knight knight(Color::WHITE, 8);

    std::vector<Piece*> pieces{ &knight };
    Board board(pieces);

    std::vector<int> expectedPossitions{2, 18, 25};

    /* Action */
    auto possibleMoves = knight.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 3);
    ASSERT_TRUE(possibleMoves == expectedPossitions);
}

/*
 * Test calculation of all possible moves of knight,
 * when knight movement is blocked by pieces of same color
 * as knight.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting possition on
 *      which other pieces are standing.
 */
TEST(PiecesTests, KnightMovesWithAllyPieces)
{
    /* Preparation */
    Knight knight1(Color::WHITE, 19);
    Knight knight2(Color::WHITE, 13);
    Knight knight3(Color::WHITE, 36);

    std::vector<Piece*> pieces{ &knight1, &knight2, &knight3 };
    Board board(pieces);

    std::vector<int> expectedPossitions{2, 4, 9, 25, 29, 34};

    /* Action */
    auto possibleMoves = knight1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 6);
    ASSERT_TRUE(possibleMoves == expectedPossitions);
}

/*
 * Test calculation of all possible moves of knight,
 * when oponent pieces are on target positions.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions including possition on
 *      which other pieces are standing.
 */
TEST(PiecesTests, KnightMovesWithOponentPieces)
{
    /* Preparation */
    Knight knight1(Color::WHITE, 19);
    Knight knight2(Color::BLACK, 13);
    Knight knight3(Color::BLACK, 36);

    std::vector<Piece*> pieces{ &knight1, &knight2, &knight3 };
    Board board(pieces);

    std::vector<int> expectedPossitions{2, 4, 9, 13, 25, 29, 34, 36};

    /* Action */
    auto possibleMoves = knight1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 8);
    ASSERT_TRUE(possibleMoves == expectedPossitions);
}
