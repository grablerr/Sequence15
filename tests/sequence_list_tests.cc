#include <gtest/gtest.h>

#include <sequence/sequence.h>


TEST(SequenceListTests, CapacityCheck) {
    SequenceList sequences;
    const auto s = Sequence::Sequence(FACTORIAL);
    for (int i = 0; i < SequenceList::CAPACITY; ++i) {
        sequences.insert(i,s);
    }

    ASSERT_ANY_THROW(sequences.insert(i, s));

}