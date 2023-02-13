#include <gtest/gtest.h>

#include <sequence/sequence.h>

TEST(SequenceTests, SquareTest0) {
    // Arrange
    Sequence s(SequenceType::SQUARE, 0);
    
    // Act
    int r1 = s.compute_nth(1);
    int r2 = s.compute_nth(2);
    int r3 = s.compute_nth(3);
    int r4 = s.compute_nth(4);
    int r5 = s.compute_nth(5);
    int r6 = s.compute_nth(6);
    
    // Assert
    EXPECT_EQ(r1, 1);
    EXPECT_EQ(r2, 4);
    EXPECT_EQ(r3, 9);
    EXPECT_EQ(r4, 16);
    EXPECT_EQ(r5, 25);
}
