#include <sequence/sequence.h>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace sequences;
using namespace std;

FactSequence::FactSequence(int i) : _i(i) {};

int FactSequence::get_i() const {
	return _i;
}

int FactSequence::compute_nth() const {
	int result=1;
	for (int i = 2; i <= get_i(); i++) {
		result *= i;
	}
	return result;
}

SequencePtr FactSequence::clone() const {
	return make_shared<FactSequence>(_i);
}

bool FactSequence::equals(SequencePtr other) const {
	const auto downcast_other = dynamic_pointer_cast<FactSequence>(other);
	if (downcast_other == nullptr) {
		return false;}
	return _i == downcast_other->_i;
}

SquareSequence::SquareSequence(int i, int shift): _i(i), _shift(shift){}

int SquareSequence::get_i() const {
	return _i;
}

int SquareSequence::get_shift() const {
	return _shift;
}

void SquareSequence::set_shift(int shift) {
	_shift = shift;
}

int SquareSequence::compute_nth() const {
	return get_i() * get_i() + get_shift();
}

SequencePtr SquareSequence::clone() const {
	return make_shared<SquareSequence>(_i, _shift);
}

bool SquareSequence::equals(SequencePtr other) const {
	const auto downcast_other = dynamic_pointer_cast<SquareSequence>(other);
	if (downcast_other == nullptr) {
		return false;
	}
	return _i == downcast_other->_i;
}