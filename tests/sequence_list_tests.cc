#include <gtest/gtest.h>

#include <sequence/sequence.h>

using namespace sequences;


TEST(SequenceListTests, CapacityCheck) {
    SequenceList sequence;

    const auto s = Sequence::Sequence(SQUARE,0);
    for (int i = 0; i < SequenceList::CAPACITY; ++i) {
        sequence.insert(i,s);
        
    }
    ASSERT_ANY_THROW(sequence.insert(10, s));
    
}

TEST(IndexOfSequenceWithMinValue, NoResult) {
    SequenceList sequence;

    const auto index = index_of_min_value(sequence, 2);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfSequenceWithMinValue, ForSquares1) {
    SequenceList sequence;

    sequence.insert(0,Sequence::Sequence(SQUARE,0));
    sequence.insert(1,Sequence::Sequence(SQUARE,1));
    sequence.insert(2,Sequence::Sequence(SQUARE,1));
    sequence.insert(3,Sequence::Sequence(SQUARE,0));

    const auto index = index_of_min_value(sequence, 0);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForSquares2) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(SQUARE, 1));
    sequence.insert(1, Sequence::Sequence(SQUARE, 2));
    sequence.insert(2, Sequence::Sequence(SQUARE, 3));
    sequence.insert(3, Sequence::Sequence(SQUARE, 4));

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials1) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(FACTORIAL));
    sequence.insert(1, Sequence::Sequence(FACTORIAL));
    sequence.insert(2, Sequence::Sequence(FACTORIAL));
    sequence.insert(3, Sequence::Sequence(FACTORIAL));

    const auto index = index_of_min_value(sequence, 0);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials2) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(FACTORIAL));
    sequence.insert(1, Sequence::Sequence(FACTORIAL));
    sequence.insert(2, Sequence::Sequence(FACTORIAL));
    sequence.insert(3, Sequence::Sequence(FACTORIAL));

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix1) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(FACTORIAL));
    sequence.insert(1, Sequence::Sequence(SQUARE,3));
    sequence.insert(2, Sequence::Sequence(FACTORIAL));
    sequence.insert(3, Sequence::Sequence(SQUARE,0));

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix2) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(SQUARE,0));
    sequence.insert(1, Sequence::Sequence(FACTORIAL));
    sequence.insert(2, Sequence::Sequence(SQUARE,3));
    sequence.insert(3, Sequence::Sequence(SQUARE,4));

    const auto index = index_of_min_value(sequence, 1);

    ASSERT_EQ(index, 1);
}

TEST(IndexOfSequenceWithMinValue, Mix3) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(FACTORIAL));
    sequence.insert(1, Sequence::Sequence(SQUARE, 2));
    sequence.insert(2, Sequence::Sequence(SQUARE,1));
    sequence.insert(3, Sequence::Sequence(SQUARE,3));

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfSequenceWithMinValue, Mix4) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(FACTORIAL));
    sequence.insert(1, Sequence::Sequence(FACTORIAL));
    sequence.insert(2, Sequence::Sequence(SQUARE, 1));
    sequence.insert(3, Sequence::Sequence(FACTORIAL));
    sequence.insert(4, Sequence::Sequence(SQUARE, 3));
    sequence.insert(5, Sequence::Sequence(SQUARE, 5));
    sequence.insert(6, Sequence::Sequence(FACTORIAL));
    sequence.insert(7, Sequence::Sequence(SQUARE, 1));
    sequence.insert(8, Sequence::Sequence(SQUARE, 7));
    sequence.insert(9, Sequence::Sequence(FACTORIAL));

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 7);
}

TEST(IndexOfSequenceWithMinValue, Mix5) {
    SequenceList sequence;

    sequence.insert(0, Sequence::Sequence(FACTORIAL));
    sequence.insert(1, Sequence::Sequence(FACTORIAL));
    sequence.insert(2, Sequence::Sequence(SQUARE, 4));
    sequence.insert(3, Sequence::Sequence(FACTORIAL));
    sequence.insert(4, Sequence::Sequence(SQUARE, 3));
    sequence.insert(5, Sequence::Sequence(SQUARE, 5));
    sequence.insert(6, Sequence::Sequence(FACTORIAL));
    sequence.insert(7, Sequence::Sequence(SQUARE, 8));
    sequence.insert(8, Sequence::Sequence(SQUARE, 7));
    sequence.insert(9, Sequence::Sequence(FACTORIAL));

    const auto index = index_of_min_value(sequence, 1);

    ASSERT_EQ(index, 9);
}
