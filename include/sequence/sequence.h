#pragma once

enum SequenceType
{
	SQUARE,
	FACTORIAL,
};

int search_seq(int sqr, int fact);

class Sequence {
	SequenceType type;
	int c;
public:
	Sequence(SequenceType type, int c);
	Sequence(SequenceType type);
	int compute_nth(int n);
};
