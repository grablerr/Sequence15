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
		int _size;
		Sequence** _array;
	public:
		SequenceList(const SequenceList& arr);
		SequenceList() : _size(0), _array(nullptr) {};
		SequenceList(int size);
		int get_size() const;
		void insert(int index, Sequence& s);
		void remove(int index);

		Sequence& operator[](int index);
		Sequence operator[](int index) const;

		void swap(SequenceList& arr);
		~SequenceList();
		SequenceList& operator=(SequenceList arr);
	};

	int index_of_min_value(const SequenceList& sequence, int c);

}