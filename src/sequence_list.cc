#include <sequence/sequence.h>
#include <stdexcept>

using namespace sequences;
using namespace std;


SequenceList::SequenceList() : _size(0) {}

int SequenceList::get_size() const{
	return _size;
}

Sequence SequenceList::operator[](int index) const {
	if (index < 0 || _size <= index) {
		throw runtime_error("Index out of range.");
	}

	return _data[index];
}

void SequenceList::insert(int index, Sequence s) {
    if (_size == CAPACITY) {
        throw runtime_error("Full capacity reached.");
    }

    for (int i = _size - 1; i >= index; i--) {
        _data[i + 1] = _data[i];
    }

    _data[index] = s;
    ++_size;
}

void SequenceList::remove(int index) {
    if (index < 0 || index >= _size) {
        throw out_of_range("Invalid index.");
    }

    for (int i = index; i < _size - 1; i++) {
        _data[i] = _data[i + 1];
    }

    --_size;
}

int sequences::index_of_min_value(const SequenceList& sequence, int c) {
    int last_index = -1;
    int min_value = 0;

    const auto size = sequence.get_size();
    for (int i = 0; i < size; ++i) {
        const auto value = sequence[i].compute_nth(c);
        if (last_index == -1 || value <= min_value) {
            last_index = i;
            min_value = value;
        }
    }

    return last_index;
}