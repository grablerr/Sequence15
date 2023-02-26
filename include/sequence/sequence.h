#pragma once
#include <stdexcept>
enum SequenceType
{
	SQUARE,
	FACTORIAL,
};

int search_seq(int sqr, int fact);

class Sequence {
	SequenceType _type;
	int _c;
	
public:
	Sequence(SequenceType type, int c);
	Sequence(SequenceType type);
	Sequence();
	SequenceType get_type() const;
	int compute_nth(int n);
};

class SequenceList {
public:
	static const int CAPACITY = 10;

private:
	Sequence _data[CAPACITY] = {};
	int _size;

public:
	SequenceList();
	int get_size();
	Sequence operator[](int index) const;
	void insert(int index,Sequence s);
	void remove(int index);
};