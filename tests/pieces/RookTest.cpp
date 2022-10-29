#include <gtest/gtest.h>
#include "../../src/gameCore/pieces/Rook.hpp"
#include <algorithm>

/*
 * Test calculation of all possible moves of rook,
 * when nothing is in a way.
 *
 * Expected result: getAllPossibleMoves function should
 *      return all available positions.
 */
TEST(PiecesTests, RookAllMovesAvailable)
{
    /* Preparation */
    Rook rook(Color::WHITE, 27);

    std::vector<Piece*> pieces{ &rook };
    Board board(pieces);

    std::vector<int> expectedPositions{
        3, 11, 19, 24, 25, 26, 28, 29, 30, 31, 35, 43, 51, 59
    };

    /* Action */
    auto possibleMoves = rook.getAllPossibleMoves(board);

    std::sort(possibleMoves.begin(), possibleMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 14);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of rook,
 * when rook is close to edge of chess board.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting illegal positions
 *      outsize of board.
 */
TEST(PiecesTests, RookMovesOutsideOfBoard)
{
    /* Preparation */
    Rook rook(Color::WHITE, 0);

    std::vector<Piece*> pieces{ &rook };
    Board board(pieces);

    std::vector<int> expectedPositions{
        1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 40, 48, 56
    };

    /* Action */
    auto possibleMoves = rook.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 14);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of rook,
 * when rook movement is blocked by pieces of same color
 * as rook.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting position
 *      which other pieces are blocking.
 */
TEST(PiecesTests, RookMovesWithAllyPieces)
{
    /* Preparation */
    Rook rook1(Color::WHITE, 19);
    Rook rook2(Color::WHITE, 18);
    Rook rook3(Color::WHITE, 43);

    std::vector<Piece*> pieces{ &rook1, &rook2, &rook3 };
    Board board(pieces);

    std::vector<int> expectedPositions{
        3, 11, 20, 21, 22, 23, 27, 35
    };

    /* Action */
    auto possibleMoves = rook1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 8);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of rook,
 * when oponent pieces are on target positions.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions including position on
 *      which other pieces are standing, but omitting all
 *      the positions behing other piece, that should be
 *      blocked.
 */
TEST(PiecesTests, RookMovesWithOponentPieces)
{
    /* Preparation */
    Rook rook1(Color::WHITE, 19);
    Rook rook2(Color::BLACK, 18);
    Rook rook3(Color::BLACK, 43);

    std::vector<Piece*> pieces{ &rook1, &rook2, &rook3 };
    Board board(pieces);

    std::vector<int> expectedPositions{
        3, 11, 18, 20, 21, 22, 23, 27, 35, 43
    };

    /* Action */
    auto possibleMoves = rook1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 10);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}
