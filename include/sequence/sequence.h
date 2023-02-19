#pragma once

enum SequenceType
{
	SQUARE,
	FACTORIAL,
};

class Sequence {
	SequenceType type;
	int c;
public:
	Sequence(SequenceType type, int c);
	int compute_nth(int n);

};
