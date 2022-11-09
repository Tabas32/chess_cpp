#include <gtest/gtest.h>
#include "../../src/gameCore/pieces/Pawn.hpp"
#include <algorithm>

/*
 * Test calculation of all possible moves of pawn,
 * when nothing is in a way. And it is starting from
 * default position.
 *
 * Expected result: getAllPossibleMoves function should
 *      return all available positions.
 */
TEST(PiecesTests, PawnAllMovesAvailableDefault)
{
    /* Preparation */
    Pawn wPawn(Color::WHITE, 10, 1);
    Pawn bPawn(Color::BLACK, 51, -1);

    std::vector<Piece*> pieces{&wPawn, &bPawn};
    Board board(pieces);

    /* Action */
    auto wPossibleMoves = wPawn.getAllPossibleMoves(board);
    auto bPossibleMoves = bPawn.getAllPossibleMoves(board);

    std::vector<int> wExpectedPositions{18, 26};
    std::vector<int> bExpectedPositions{43, 35};

    /* Assertions */
    ASSERT_EQ(wPossibleMoves.size(), 2);
    ASSERT_EQ(bPossibleMoves.size(), 2);

    ASSERT_TRUE(wPossibleMoves == wExpectedPositions);
    ASSERT_TRUE(bPossibleMoves == bExpectedPositions);
}

/*
 * Test calculation of all possible moves of pawn,
 * when nothing is in a way. And it is not starting from
 * default position.
 *
 * Expected result: getAllPossibleMoves function should
 *      return all available positions.
 */
TEST(PiecesTests, PawnAllMovesAvailable)
{
    /* Preparation */
    Pawn wPawn(Color::WHITE, 10, 1, false);
    Pawn bPawn(Color::BLACK, 51, -1, false);

    std::vector<Piece*> pieces{&wPawn, &bPawn};
    Board board(pieces);

    /* Action */
    auto wPossibleMoves = wPawn.getAllPossibleMoves(board);
    auto bPossibleMoves = bPawn.getAllPossibleMoves(board);

    std::vector<int> wExpectedPositions{18};
    std::vector<int> bExpectedPositions{43};

    /* Assertions */
    ASSERT_EQ(wPossibleMoves.size(), 1);
    ASSERT_EQ(bPossibleMoves.size(), 1);

    ASSERT_TRUE(wPossibleMoves == wExpectedPositions);
    ASSERT_TRUE(bPossibleMoves == bExpectedPositions);
}

/*
 * Test calculation of all possible moves of pawn,
 * when pawn is close to edge of chess board.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting illegal positions
 *      outsize of board.
 */
TEST(PiecesTests, PawnMovesOutsideOfBoard)
{
    /* Preparation */
    Pawn pawn(Color::WHITE, 57, 1);

    std::vector<Piece*> pieces{&pawn};
    Board board(pieces);

    /* Action */
    auto possibleMoves = pawn.getAllPossibleMoves(board);

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 0);
}

/*
 * Test calculation of all possible moves of pawn,
 * when pawn movement is blocked by pieces of same color
 * as pawn.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions omitting position
 *      which other pieces are blocking.
 */
TEST(PiecesTests, PawnMovesWithAllyPieceBlocking)
{
    /* Preparation */
    Pawn pawn1(Color::WHITE, 10, 1);
    Pawn pawn2(Color::WHITE, 26, 1);

    std::vector<Piece*> pieces{&pawn1, &pawn2};
    Board board(pieces);

    std::vector<int> expectedPositions{18};

    /* Action */
    auto possibleMoves = pawn1.getAllPossibleMoves(board);

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 1);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

/*
 * Test calculation of all possible moves of pawn,
 * when oponent pieces are on target positions.
 *
 * Expected result: getAllPossibleMoves function should
 *      return available positions including position on
 *      which other pieces are standing, but omitting all
 *      the positions behing other piece, that should be
 *      blocked.
 */
TEST(PiecesTests, PawnMovesWithOponentPieceBlocking)
{
    /* Preparation */
    Pawn pawn1(Color::WHITE, 10, 1);
    Pawn pawn2(Color::BLACK, 26, -1);

    std::vector<Piece*> pieces{&pawn1, &pawn2};
    Board board(pieces);

    std::vector<int> expectedPositions{18};

    /* Action */
    auto possibleMoves = pawn1.getAllPossibleMoves(board);

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 1);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

TEST(PiecesTests, PawnMovesWithOponentPieceAbleToTake)
{
    /* Preparation */
    Pawn pawn1(Color::WHITE, 10, 1);
    Pawn pawn2(Color::BLACK, 19, -1);

    std::vector<Piece*> pieces{&pawn1, &pawn2};
    Board board(pieces);

    std::vector<int> expectedPositions{18, 19, 26};

    /* Action */
    auto possibleMoves = pawn1.getAllPossibleMoves(board);

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 3);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}

TEST(PiecesTests, PawnMovesEnPassant)
{
    /* Preparation */
    Pawn pawn1(Color::WHITE, 10, 1);
    Pawn pawn2(Color::BLACK, 19, -1);

    std::vector<Piece*> pieces{&pawn1, &pawn2};
    Board board(pieces);

    std::vector<int> expectedPositions{18, 19, 26};

    /* Action */
    auto possibleMoves = pawn1.getAllPossibleMoves(board);

    /* Assertions */
    ASSERT_EQ(possibleMoves.size(), 3);
    ASSERT_TRUE(possibleMoves == expectedPositions);
}
