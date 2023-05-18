#pragma once
#include <memory>
#include <string>
#include <vector>

namespace sequences {

	class Sequence;

	using SequencePtr = std::shared_ptr<Sequence>;

	class Sequence {
	public:
		virtual int compute_nth() const = 0;

		virtual SequencePtr clone() const = 0;
		virtual bool equals(SequencePtr other) const = 0;

		virtual ~Sequence() = default;

	protected:
		Sequence() = default;
		Sequence(const Sequence&) = default;
		Sequence& operator=(const Sequence&) = default;
	};

	class FactSequence : public Sequence {
	private:
		int _i;

	public:
		FactSequence(int i);

		int get_i() const;

		int compute_nth()const override;

		SequencePtr clone()const override;
		bool equals(SequencePtr other) const override;
	};

	class SquareSequence : public Sequence{
	private:
		int _i;
		int _shift;
	public:
		SquareSequence(int i, int shift);

		int get_i()const;
		int get_shift()const;
		void set_shift(int shift);

		int compute_nth()const override;

		SequencePtr clone() const override;
		bool equals(SequencePtr other) const override;
	};

	class SequenceList {
	private:
		std::vector<SequencePtr> _sequences;

	public:
		SequenceList() = default;

		SequenceList(const SequenceList& other);

		SequenceList& operator=(const SequenceList & rhs);

		int get_size() const;

		SequencePtr operator[](int index) const;

		void add(SequencePtr seq);
		void remove(int index);

		void swap(SequenceList& arr);
	};

	int index_of_min_value(const SequenceList& sequence);
}