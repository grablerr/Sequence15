#include <iostream>
#include <stdlib.h>
#include <sequence/sequence.h>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;
using namespace sequences;


int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

void PrintList(SequenceList& arr) {
	system("cls");
	if (arr.get_size() == 0)
		cout << "Массив последовательностей пуст";
	for (int i = 0; i < arr.get_size(); ++i) {
		cout << "[" << i+1 << "]\t" << arr[i] << endl;
	}
	cout << endl;
	cout << "Для продолжения нажмите любую кнопку ";
	get_key();
}

SequenceType InputType() {
	string types[] = { "SEQUENCE", "FACTORIAL" };
	SequenceType ctypes[] = { SQUARE, FACTORIAL };
	int choose = 0;
	int flag = true;
	system("cls");
	while (flag) {
		cout << "<Выберите тип последовательности>" << endl;
		cout << "1)" << "<Квадрат со сдвигом>" << endl;
		cout << "2)" << "<Факториал>" << endl;
		int seq_type = get_key();
		if (seq_type == 49) { choose = 0; flag = false; }
		else if (seq_type == 50) { choose = 1; flag = false; }
		else { cout << "Введено неправильное число, попробуйте ещё раз" << endl; }

	}
	return ctypes[choose];
}

void InputShift(Sequence& seq) {
	int shift = 0;
	cout << "Введите целочисленный сдиг" << endl;
	cin >> shift;
	seq.set_shift(shift);
}

int InputIndex(int size) {
	bool flag = true;
	int index;
	while (flag) {
		cout << "Введите индекс или -1, если хотите выйти: ";
		cin >> index;
		index--;
		if (cin.fail() || index < -1 || index >= size) {
			std::cin.clear();
			system("cls");
			cout << "Неверный индекс или ввод!" << endl;
		}
		else {
			flag = false;
		}
	}
	return index;
}

void AddSequence(SequenceList& arr) {
	system("cls");
	int index = InputIndex(arr.get_size() + 1);
	if (index != -1) {
		Sequence seq(InputType());
		SequenceType type = seq.get_type();
		if (type == SQUARE) { InputShift(seq); }
		arr.insert(index, seq);
	}
}


void DeleteCharacter(SequenceList& arr) {
	int index = InputIndex(arr.get_size());
	if (index != -1) { arr.remove(index); }
}

void FindMinElem(SequenceList& arr) {
	system("cls");
	cout << "Введите n: ";
	int n;
	cin >> n;
	int index = index_of_min_value(arr, n);
	cout << "Последовательностью с минимальным n-ым членом, при n=" << n << " является - " << "[" << index << "]" << " " << arr[index] << endl;
	get_key();
}

void ChangeSequence(SequenceList& arr) {
	system("cls");
	int index = InputIndex(arr.get_size());
	if (index != -1) {
		Sequence seq(InputType());
		SequenceType type= seq.get_type();
		if (type == SQUARE) { InputShift(seq); }
		arr[index] = seq;

	}
}

int menu1() {
	cout << "1)" << "Добавить последовательность в массив по индексу" << endl;
	cout << "2)" << "Удалить последовательность из массива по индексу" << endl;
	cout << "3)" << "Вывести последовательности на экран" << endl;
	cout << "4)" << "Вывести последовательность с минимальным n-ым членом" << endl;
	cout << "5)" << "Заменить последовательность из массива по индексу" << endl;
	cout << "6)" << "Выйти" << endl;

	while (true) {
		int key = get_key();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54)) return key;
	}
}




int main() {
	setlocale(LC_ALL, "Russian");
	SequenceList array;
	while (true) {
		system("cls");
		printf("Меню.\n");
		int m1 = menu1();
		if (m1 == 49) { system("cls"); AddSequence(array); }
		if (m1 == 50) { DeleteCharacter(array); }
		if (m1 == 51) { PrintList(array); };
		if (m1 == 52) { FindMinElem(array); };
		if (m1 == 53) { ChangeSequence(array); };
		if (m1 == 54) break;
	}
	return 0;
}