#include <cstdio>
#include <stdexcept>
#include <sequence/sequence.h>

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

int Sequence::compute_nth(int n) const{
	switch (_type)
	{
	case SQUARE:
		return n * n + _shift;
	case FACTORIAL:
		if (n == 0 || n == 1) {return 1;}
		else {return n * Sequence::compute_nth(n - 1);}
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

//bool sequences::operator==(const Sequence& lhs, const Sequence& rhs) {
//	return
//		lhs.get_type() == rhs.get_type();
//}
//
//bool sequences::operator!=(const Sequence& lhs, const Sequence& rhs) {
//	return !(lhs == rhs);
//}