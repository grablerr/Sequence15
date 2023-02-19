#include <sequence/sequence.h>

Sequence::Sequence(SequenceType type, int c) {
	this->type = type;
	this->c = c;
}

Sequence::Sequence(SequenceType type) {
	this->type = type;
}

int Sequence::compute_nth(int n) {
	switch (type)
	{
	case SQUARE:
		return n * n + c;
	case FACTORIAL:
		if (n == 1) {return 1;}
		else {return n * Sequence::compute_nth(n - 1);}
	default:
		return 0;
	}
}

int search_seq(int sqr, int fact) {
	if (sqr < fact) { return 0; }
	else { return 1; }
}