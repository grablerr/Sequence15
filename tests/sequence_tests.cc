#include <gtest/gtest.h>

#include <sequence/sequence.h>
using namespace sequences;

TEST(SequenceTests, SquareTest0) {
    Sequence s(SQUARE, 0);
    
    int r1 = s.compute_nth(1);
    int r2 = s.compute_nth(2);
    int r3 = s.compute_nth(3);

    EXPECT_EQ(r1, 1);
    EXPECT_EQ(r2, 4);
    EXPECT_EQ(r3, 9);
}

TEST(SequenceTests, SquareTest1) {

    Sequence s(SequenceType::SQUARE, 1);

    int r1 = s.compute_nth(4);
    int r2 = s.compute_nth(5);
    int r3 = s.compute_nth(6);

    EXPECT_EQ(r1, 17);
    EXPECT_EQ(r2, 26);
    EXPECT_EQ(r3, 37);
}

TEST(SequenceTests, SquareTest2) {

    Sequence s(SequenceType::SQUARE, 5);

    int r1 = s.compute_nth(7);
    int r2 = s.compute_nth(8);
    int r3 = s.compute_nth(9);

    EXPECT_EQ(r1, 54);
    EXPECT_EQ(r2, 69);
    EXPECT_EQ(r3, 86);
}

TEST(SequenceTests, SquareTest3) {

    Sequence s(SequenceType::SQUARE, -3);

    int r1 = s.compute_nth(1);
    int r2 = s.compute_nth(3);
    int r3 = s.compute_nth(8);

    EXPECT_EQ(r1, -2);
    EXPECT_EQ(r2, 6);
    EXPECT_EQ(r3, 61);
}

TEST(SequenceTests, FactorialTest0) {

    Sequence s(SequenceType::FACTORIAL);

    int r1 = s.compute_nth(0);

    EXPECT_EQ(r1, 1);
}

TEST(SequenceTests, FactorialTest1) {

    Sequence s(SequenceType::FACTORIAL);

    int r1 = s.compute_nth(1);

    EXPECT_EQ(r1, 1);
}

TEST(SequenceTests, FactorialTest4) {

    Sequence s(SequenceType::FACTORIAL);

    int r1 = s.compute_nth(4);

    EXPECT_EQ(r1, 24);
}

TEST(SequenceTests, FactorialTest5) {

    Sequence s(SequenceType::FACTORIAL);

    int r1 = s.compute_nth(5);

    EXPECT_EQ(r1, 120);
}


