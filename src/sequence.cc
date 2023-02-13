#include <sequence/sequence.h>

int sum_stub(int lhs, int rhs) {
	return lhs + rhs;
}

Sequence::Sequence(SequenceType type, int c) {
	this->type = type;
	this->c = c;
}

int Sequence::compute_nth(int n) {
	switch (type)
	{
	case SQUARE:
		return n * n + c;
	case FACTORIAL:
		return n;//todo
	default:
		return 0;
	}
}
