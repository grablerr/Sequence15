#include <sequence/sequence.h>
#include <stdexcept>


using namespace sequences;


SequenceList::SequenceList(const SequenceList& arr) {
	_size = arr._size;
	_array = new Sequence * [_size];
	for (int i = 0; i < _size; i++) {
		_array[i] = new Sequence;
		*_array[i] = arr[i];
	}
}

SequenceList::SequenceList(int size) {
	if (size < 0)throw std::invalid_argument("Size of array should be positive");
	_size = size;
	_array = new Sequence * [size];
	for (int i = 0; i < size; i++) {
		_array[i] = new Sequence;
		*_array[i] = Sequence();
	}
}

int SequenceList::get_size() const {
	return _size;
}

Sequence& SequenceList::operator[](int index) {
	if (index < 0 || _size <= index) {
		throw std::runtime_error("Index out of range.");
	}

	return *_array[index];
}

Sequence SequenceList::operator[](int index) const {
	if (index < 0 || _size <= index) {
		throw std::runtime_error("Index out of range.");
	}

	return *_array[index];
}

void SequenceList::insert(int index, Sequence& s) {
	if (index > _size || index < 0) throw std::runtime_error("Invalid index");

	Sequence** ptr = new Sequence * [_size + 1];
	for (int i = 0; i <= index; i++) {
		ptr[i] = new Sequence;
	}

	memcpy(ptr, _array, sizeof(Sequence*) * index);
	*ptr[index] = s;
	memcpy(ptr + index + 1, _array + index, sizeof(Sequence*) * (_size - index));
	++_size;

	delete[] _array;
	_array = ptr;
	ptr = nullptr;
}

void SequenceList::remove(int index) {
	if (index < 0 || index >= _size)throw std::out_of_range("Invalid index.");

	Sequence** ptr = new Sequence * [_size - 1];
	for (int i = 0; i < _size - 1; i++) {
		ptr[i] = new Sequence;
	}
	memcpy(ptr, _array, sizeof(Sequence*) * index);
	memcpy(ptr + index, _array + index + 1, sizeof(Sequence*) * (_size - index));
	delete _array[index];
	delete[] _array;
	_array = ptr;
	ptr = nullptr;
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

SequenceList::~SequenceList() {
	for (int i = 0; i < _size; i++) {
		delete _array[i];
	}
	delete[] _array;
}

void SequenceList::swap(SequenceList& arr) {
	std::swap(_size, arr._size);
	std::swap(_array, arr._array);
}

SequenceList& ::SequenceList::operator=(SequenceList arr) {
	this->swap(arr);
	return *this;
}
