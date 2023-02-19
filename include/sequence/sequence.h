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
	Sequence(SequenceType type);
	int compute_nth(int n);
    int search_seq(int sqr, int fact);
};
