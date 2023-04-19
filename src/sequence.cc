#include <cstdio>
#include <stdexcept>
#include <sequence/sequence.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace sequences;

Sequence::Sequence(SequenceType type, int shift) {
	this->_type = type;
	this->_shift = shift;
}
Sequence::Sequence(SequenceType type) {
	this->_type = type;
}

Sequence::Sequence() : _type(SequenceType::SQUARE), _shift(1) { }

SequenceType Sequence::get_type() const {
	return _type;
}

int Sequence::compute_nth(int n) const {
	switch (_type)
	{
	case SQUARE:
		return n * n + _shift;
	case FACTORIAL:
		if (n == 0 || n == 1) { return 1; }
		else { return n * Sequence::compute_nth(n - 1); }
	default:
		return 0;
	}
}

int Sequence::set_shift(int shift) {
	_shift = shift;
	return 0;
}

int Sequence::get_shift() {
	return _shift;
}

std::ostream& sequences::operator<<(std::ostream& out, const SequenceType& type) {
	switch (type) {
	case SQUARE:
		out << "SQUARE";
		return out;
	case FACTORIAL:
		out << "FACTORIAL";
		return out;
	}

}

std::ostream& sequences::operator<<(std::ostream& out, const Sequence& seq) {
	int t = seq._shift;
	if (seq.get_type() == SQUARE) { out << "Type: " << seq.get_type()<< "|" << "Shift: " << t; }
	else(out << "Type: " << seq.get_type());
	return out;
}
