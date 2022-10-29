#include <gtest/gtest.h>
#include "../../src/gameCore/pieces/Bishop.hpp"
#include <algorithm>

/*
 * Test calculation of all possible moves of bishop,
 * when nothing is in a way.
 *
 * Expected result: getAllPossibleMoves function should
 *      return all available positions.
 */
TEST(PiecesTests, BishopAllMovesAvailable)
{
    /* Preparation */
    Bishop bishop(Color::WHITE, 27);

    std::vector<Piece*> pieces{ &bishop };
    Board board(pieces);

    std::vector<int> expectedPositions{
        0, 9, 18, 20, 13, 6, 34, 41, 48, 36, 45, 54, 63
    };

    /* Action */
    auto possibleMoves = bishop.getAllPossibleMoves(board);

    std::sort(possibleMoves.begin(), possibleMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 13);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of bishop,
 * when bishop is close to edge of chess board.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting illegal positions
 *      outsize of board.
 */
TEST(PiecesTests, BishopMovesOutsideOfBoard)
{
    /* Preparation */
    Bishop bishop(Color::WHITE, 0);

    std::vector<Piece*> pieces{ &bishop };
    Board board(pieces);

    std::vector<int> expectedPositions{9, 18, 27, 36, 45, 54, 63};

    /* Action */
    auto possibleMoves = bishop.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 7);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of bishop,
 * when bishop movement is blocked by pieces of same color
 * as bishop.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting position
 *      which other pieces are blocking.
 */
TEST(PiecesTests, BishopMovesWithAllyPieces)
{
    /* Preparation */
    Bishop bishop1(Color::WHITE, 19);
    Bishop bishop2(Color::WHITE, 26);
    Bishop bishop3(Color::WHITE, 46);

    std::vector<Piece*> pieces{ &bishop1, &bishop2, &bishop3 };
    Board board(pieces);

    std::vector<int> expectedPositions{1, 5, 10, 12, 28, 37};

    /* Action */
    auto possibleMoves = bishop1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 6);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of bishop,
 * when oponent pieces are on target positions.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions including position on
 *      which other pieces are standing, but omitting all
 *      the positions behing other piece, that should be
 *      blocked.
 */
TEST(PiecesTests, BishopMovesWithOponentPieces)
{
    /* Preparation */
    Bishop bishop1(Color::WHITE, 19);
    Bishop bishop2(Color::BLACK, 26);
    Bishop bishop3(Color::BLACK, 46);

    std::vector<Piece*> pieces{ &bishop1, &bishop2, &bishop3 };
    Board board(pieces);

    std::vector<int> expectedPositions{
        1, 5, 10, 12, 26, 28, 37, 46
    };

    /* Action */
    auto possibleMoves = bishop1.getAllPossibleMoves(board);
    std::sort(possibleMoves.begin(), possibleMoves.end());

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 8);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}
