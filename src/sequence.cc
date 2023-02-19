#include <sequence/sequence.h>

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
		if (n == 1) return 1;
		else {
			return n * Sequence::compute_nth(n - 1);
		}
	default:
		return 0;
	}
}
