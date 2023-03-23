#pragma once

namespace sequences {

	enum SequenceType
	{
		SQUARE,
		FACTORIAL,
	};

	class Sequence {
		SequenceType _type;
		int _shift;

	public:
		Sequence(SequenceType type, int shift);
		Sequence(SequenceType type);
		Sequence();
		SequenceType get_type() const;
		int compute_nth(int n) const;
		int set_shift(int shift);
		int get_shift();
	};

	bool operator==(const Sequence& lhs, const Sequence& rhs);
	bool operator!=(const Sequence& lhs, const Sequence& rhs);

	class SequenceList {
	public:
		static const int CAPACITY = 10;

	private:
		Sequence _data[CAPACITY] = {};
		int _size;

	public:
		SequenceList();
		int get_size() const;
		Sequence operator[](int index) const;
		void insert(int index, Sequence s);
		void remove(int index);

	};

	int index_of_min_value(const SequenceList& sequence, int c);

}