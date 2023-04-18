#include <gtest/gtest.h>

#include <sequence/sequence.h>

using namespace sequences;


TEST(SequenceListTests, CapacityCheck) {
	SequenceList sequence(3);
	Sequence s = Sequence(SQUARE, 5);
	sequence[0] = Sequence(SQUARE, 0);
	sequence[1] = Sequence(SQUARE, 1);
	sequence[2] = Sequence(SQUARE, 2);
	ASSERT_ANY_THROW(sequence.insert(4, s););

}

TEST(IndexOfSequenceWithMinValue, NoResult) {
	SequenceList sequence;

	const auto index = index_of_min_value(sequence, 2);

	ASSERT_EQ(index, -1);
}

TEST(IndexOfSequenceWithMinValue, ForSquares1) {
	SequenceList sequence;
	Sequence s0 = Sequence(SQUARE, 0);
	Sequence s1 = Sequence(SQUARE, 1);
	sequence.insert(0, s0);
	sequence.insert(1, s1);
	sequence.insert(2, s1);
	sequence.insert(3, s0);

	const auto index = index_of_min_value(sequence, 0);

	ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForSquares2) {
	SequenceList sequence;
	Sequence s1 = Sequence(SQUARE, 1);
	Sequence s2 = Sequence(SQUARE, 2);
	Sequence s3 = Sequence(SQUARE, 3);
	Sequence s4 = Sequence(SQUARE, 4);

	sequence.insert(0, s1);
	sequence.insert(1, s2);
	sequence.insert(2, s3);
	sequence.insert(3, s4);


	const auto index = index_of_min_value(sequence, 5);

	ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials1) {
	SequenceList sequence;
	Sequence f = Sequence(FACTORIAL);

	sequence.insert(0, f);
	sequence.insert(1, f);
	sequence.insert(2, f);
	sequence.insert(3, f);

	const auto index = index_of_min_value(sequence, 0);

	ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials2) {
	SequenceList sequence;
	Sequence f = Sequence(FACTORIAL);

	sequence.insert(0, f);
	sequence.insert(1, f);
	sequence.insert(2, f);
	sequence.insert(3, f);

	const auto index = index_of_min_value(sequence, 5);

	ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix1) {
	SequenceList sequence;
	Sequence f = Sequence(FACTORIAL);
	Sequence s0 = Sequence(SQUARE, 0);
	Sequence s3 = Sequence(SQUARE, 3);

	sequence.insert(0, f);
	sequence.insert(1, s3);
	sequence.insert(2, f);
	sequence.insert(3, s0);

	const auto index = index_of_min_value(sequence, 5);

	ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix2) {
	SequenceList sequence;
	Sequence f = Sequence(FACTORIAL);
	Sequence s0 = Sequence(SQUARE, 0);
	Sequence s3 = Sequence(SQUARE, 3);
	Sequence s4 = Sequence(SQUARE, 4);

	sequence.insert(0, s0);
	sequence.insert(1, f);
	sequence.insert(2, s3);
	sequence.insert(3, s4);

	const auto index = index_of_min_value(sequence, 1);

	ASSERT_EQ(index, 1);
}

TEST(IndexOfSequenceWithMinValue, Mix3) {
	SequenceList sequence;
	Sequence f = Sequence(FACTORIAL);
	Sequence s1 = Sequence(SQUARE, 1);
	Sequence s2 = Sequence(SQUARE, 2);
	Sequence s3 = Sequence(SQUARE, 3);

	sequence.insert(0, f);
	sequence.insert(1, s2);
	sequence.insert(2, s1);
	sequence.insert(3, s3);

	const auto index = index_of_min_value(sequence, 5);

	ASSERT_EQ(index, 2);
}

TEST(IndexOfSequenceWithMinValue, Mix4) {
	SequenceList sequence;
	Sequence f = Sequence(FACTORIAL);
	Sequence s1 = Sequence(SQUARE, 1);
	Sequence s3 = Sequence(SQUARE, 3);
	Sequence s5 = Sequence(SQUARE, 5);
	Sequence s7 = Sequence(SQUARE, 7);

	sequence.insert(0, f);
	sequence.insert(1, f);
	sequence.insert(2, s1);
	sequence.insert(3, f);
	sequence.insert(4, s3);
	sequence.insert(5, s5);
	sequence.insert(6, f);
	sequence.insert(7, s1);
	sequence.insert(8, s7);
	sequence.insert(9, f);

	const auto index = index_of_min_value(sequence, 5);

	ASSERT_EQ(index, 7);
}

TEST(IndexOfSequenceWithMinValue, Mix5) {
	SequenceList sequence;
	Sequence f = Sequence(FACTORIAL);
	Sequence s3 = Sequence(SQUARE, 3);
	Sequence s4 = Sequence(SQUARE, 4);
	Sequence s5 = Sequence(SQUARE, 5);
	Sequence s7 = Sequence(SQUARE, 7);
	Sequence s8 = Sequence(SQUARE, 8);

    sequence.insert(0, f);
    sequence.insert(1, f);
    sequence.insert(2, s4);
    sequence.insert(3, f);
    sequence.insert(4, s3);
    sequence.insert(5, s5);
    sequence.insert(6, f);
    sequence.insert(7, s8);
    sequence.insert(8, s7);
    sequence.insert(9, f);

    const auto index = index_of_min_value(sequence, 1);

    ASSERT_EQ(index, 9);
}
