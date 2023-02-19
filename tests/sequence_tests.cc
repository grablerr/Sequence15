#include <gtest/gtest.h>

#include <sequence/sequence.h>

int search_seq(int sqr, int fact);

TEST(SequenceTests, SquareTest0) {
    // Arrange
    Sequence s(SequenceType::SQUARE, 0);
    
    // Act
    int r1 = s.compute_nth(1);
    int r2 = s.compute_nth(2);
    int r3 = s.compute_nth(3);
    // Assert
    EXPECT_EQ(r1, 1);
    EXPECT_EQ(r2, 4);
    EXPECT_EQ(r3, 9);
}

TEST(SequenceTests, SquareTest1) {
    // Arrange
    Sequence s(SequenceType::SQUARE, 1);

    // Act
    int r1 = s.compute_nth(4);
    int r2 = s.compute_nth(5);
    int r3 = s.compute_nth(6);

    // Assert
    EXPECT_EQ(r1, 17);
    EXPECT_EQ(r2, 26);
    EXPECT_EQ(r3, 37);
}

TEST(SequenceTests, SquareTest5) {
    // Arrange
    Sequence s(SequenceType::SQUARE, 5);

    // Act
    int r1 = s.compute_nth(7);
    int r2 = s.compute_nth(8);
    int r3 = s.compute_nth(9);

    // Assert
    EXPECT_EQ(r1, 54);
    EXPECT_EQ(r2, 69);
    EXPECT_EQ(r3, 86);
}

TEST(SequenceTests, FactorialTest0) {
    // Arrange
    Sequence s(SequenceType::FACTORIAL);

    // Act
    int r1 = s.compute_nth(4);

    // Assert
    EXPECT_EQ(r1, 24);
}

TEST(SequenceTests, Serch_test1) {
    // Arrange
    Sequence s(SequenceType::SQUARE, 0);
    Sequence fact(SequenceType::FACTORIAL);

    // Act
    int r1 = s.compute_nth(4);
    int r2 = fact.compute_nth(4);
    int result = search_seq(r1,r2);
    // Assert
    EXPECT_EQ(result, 0);
}

TEST(SequenceTests, Serch_test2) {
    // Arrange
    Sequence s(SequenceType::SQUARE, 0);
    Sequence fact(SequenceType::FACTORIAL);

    // Act
    int r1 = s.compute_nth(3);
    int r2 = fact.compute_nth(3);
    int result = search_seq(r1,r2);
    // Assert
    EXPECT_EQ(result, 1);
}
