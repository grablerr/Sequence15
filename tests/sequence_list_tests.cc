#include <gtest/gtest.h>

#include <sequence/sequence.h>

using namespace sequences;
using namespace std;


TEST(SequenceListTests, NoResult) {
	SequenceList sequences;

	const auto index = index_of_min_value(sequences);

	ASSERT_EQ(index, -1);
}

TEST(IndexOfSequenceWithMinValue, CapacityCheck) {
	SequenceList sequence;

	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, -1);
}

TEST(IndexOfSequenceWithMinValue, ForSquares1) {
	SequenceList sequence;
	auto const Square1 = make_shared<SquareSequence>(1, 0);
	auto const Square2 = make_shared<SquareSequence>(2, 0);
	sequence.add(Square1);
	sequence.add(Square2);
	sequence.add(Square2);
	sequence.add(Square1);

	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForSquares2) {
	SequenceList sequence;
	auto const Square1 = make_shared<SquareSequence>(1, 0);
	auto const Square2 = make_shared<SquareSequence>(2, 0);
	auto const Square3 = make_shared<SquareSequence>(3, 0);
	auto const Square4 = make_shared<SquareSequence>(4, 0);

	sequence.add(Square1);
	sequence.add(Square2);
	sequence.add(Square3);
	sequence.add(Square4);


	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials1) {
	SequenceList sequence;
	auto const Factorial1 = make_shared<FactSequence>(1);
	auto const Factorial2 = make_shared<FactSequence>(2);
	auto const Factorial3 = make_shared<FactSequence>(3);
	auto const Factorial4 = make_shared<FactSequence>(4);

	sequence.add(Factorial1);
	sequence.add(Factorial2);
	sequence.add(Factorial3);
	sequence.add(Factorial4);

	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials2) {
	SequenceList sequence;
	auto const Factorial1 = make_shared<FactSequence>(4);
	auto const Factorial2 = make_shared<FactSequence>(3);
	auto const Factorial3 = make_shared<FactSequence>(2);
	auto const Factorial4 = make_shared<FactSequence>(1);

	sequence.add(Factorial1);
	sequence.add(Factorial2);
	sequence.add(Factorial3);
	sequence.add(Factorial4);

	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix1) {
	SequenceList sequence;

	auto const Factorial5 = make_shared<FactSequence>(5);
	auto const Square50 = make_shared<SquareSequence>(5, 0);
	auto const Square53 = make_shared<SquareSequence>(5, 3);

	sequence.add(Factorial5);
	sequence.add(Square53);
	sequence.add(Factorial5);
	sequence.add(Square50);

	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix2) {
	SequenceList sequence;

	auto const Factorial1 = make_shared<FactSequence>(1);
	auto const Square10 = make_shared<SquareSequence>(1, 0);
	auto const Square53 = make_shared<SquareSequence>(1, 3);
	auto const Square54 = make_shared<SquareSequence>(1, 4);

	sequence.add(Square10);
	sequence.add(Factorial1);
	sequence.add(Square53);
	sequence.add(Square54);

	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 1);
}

TEST(IndexOfSequenceWithMinValue, Mix3) {
	SequenceList sequence;

	auto const Factorial5 = make_shared<FactSequence>(5);
	auto const Square51 = make_shared<SquareSequence>(5, 1);
	auto const Square52 = make_shared<SquareSequence>(5, 2);
	auto const Square53 = make_shared<SquareSequence>(5, 3);

	sequence.add(Factorial5);
	sequence.add(Square52);
	sequence.add(Square51);
	sequence.add(Square53);

	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 2);
}

TEST(IndexOfSequenceWithMinValue, Mix4) {
	SequenceList sequence;

	auto const Factorial5 = make_shared<FactSequence>(5);
	auto const Square51 = make_shared<SquareSequence>(5, 1);
	auto const Square53 = make_shared<SquareSequence>(5, 3);
	auto const Square55 = make_shared<SquareSequence>(5, 5);
	auto const Square57 = make_shared<SquareSequence>(5, 7);

	sequence.add(Factorial5);
	sequence.add(Factorial5);
	sequence.add(Square51);
	sequence.add(Factorial5);
	sequence.add(Square53);
	sequence.add(Square55);
	sequence.add(Factorial5);
	sequence.add(Square51);
	sequence.add(Square57);
	sequence.add(Factorial5);


	const auto index = index_of_min_value(sequence);

	ASSERT_EQ(index, 7);
}

TEST(IndexOfSequenceWithMinValue, Mix5) {
	SequenceList sequence;

	auto const Factorial5 = make_shared<FactSequence>(1);
	auto const Square53 = make_shared<SquareSequence>(1, 3);
	auto const Square54 = make_shared<SquareSequence>(1, 4);
	auto const Square55 = make_shared<SquareSequence>(1, 5);
	auto const Square57 = make_shared<SquareSequence>(1, 7);
	auto const Square58 = make_shared<SquareSequence>(1, 8);

	sequence.add(Factorial5);
	sequence.add(Factorial5);
	sequence.add(Square54);
	sequence.add(Factorial5);
	sequence.add(Square53);
	sequence.add(Square55);
	sequence.add(Factorial5);
	sequence.add(Square58);
	sequence.add(Square57);
	sequence.add(Factorial5);

    const auto index = index_of_min_value(sequence);

    ASSERT_EQ(index, 9);
}
