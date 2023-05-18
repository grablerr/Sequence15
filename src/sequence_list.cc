#include <sequence/sequence.h>
#include <stdexcept>


using namespace sequences;
using namespace std;


SequenceList::SequenceList(const SequenceList& arr) {
	const auto n = arr.get_size();
	_sequences.reserve(n);
	for (const auto& ptr:arr._sequences) {
		_sequences.push_back(ptr->clone());
	}
}

SequenceList& SequenceList::operator=(const SequenceList& rhs) {
	SequenceList copy(rhs);
	copy.swap(*this);
	return *this;
}

int SequenceList::get_size() const {
	return static_cast<int>(_sequences.size());
}

SequencePtr SequenceList::operator[](const int index) const {
	return _sequences.at(index);
}

void SequenceList::add(SequencePtr seq) {
	_sequences.push_back(seq);
}

void SequenceList::remove(int index) {
	_sequences.erase(_sequences.begin() + index);
}

void SequenceList::swap(SequenceList& other) {
	std::swap(this->_sequences, other._sequences);
}

int sequences::index_of_min_value(const SequenceList& sequence) {
	int last_index = -1;
	int min_value = 0;

	const auto size = sequence.get_size();
	for (int i = 0; i < size; ++i) {
		const auto value = sequence[i]->compute_nth();
		if (last_index == -1 || value <= min_value) {
			last_index = i;
			min_value = value;
		}
	}

	return last_index;
}
