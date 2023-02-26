#include <cstdio>
#include <stdexcept>
#include <sequence/sequence.h>


Sequence::Sequence(SequenceType type, int c) {
	this->_type = type;
	this->_c = c;
}

Sequence::Sequence(SequenceType type) {
	this->_type = type;
}

SequenceType Sequence::get_type() const {
	return _type;
}

int Sequence::compute_nth(int n){
	switch (_type)
	{
	case SQUARE:
		return n * n + _c;
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