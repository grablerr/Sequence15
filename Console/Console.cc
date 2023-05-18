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
		cout << "\033[0;31mМассив последовательностей пуст\033[0m";
	for (int i = 0; i < arr.get_size(); ++i) {
		auto seq = arr[i];
		auto square_seq = dynamic_cast<SquareSequence*>(seq.get());
		auto fact_seq = dynamic_cast<FactSequence*>(seq.get());
		if (square_seq != nullptr) {
			cout << "Square";
			cout << " [" << square_seq->get_i() << "]";
			cout << " [" << square_seq->get_shift() << "]" << endl;
		}
		else if (fact_seq != nullptr) {
			cout << "Factorial";
			cout << " [" << fact_seq->get_i() << "]" << endl;
		}
	}

	cout << endl;
	cout << "\033[0;33mДля продолжения нажмите любую кнопку \033[0m";
	get_key();
}

int InputType() {
	int choose = 0;
	int flag = true;
	system("cls");
	while (flag) {
		cout << "\033[0;34m<Выберите тип последовательности>\033[0m" << endl;
		cout << "1)" << "\033[0;36m<Квадрат со сдвигом>\033[0m" << endl;
		cout << "2)" << "\033[0;36m<Факториал>\033[0m" << endl;
		int seq_type = get_key();
		if (seq_type == 49) { choose = 0; flag = false; }
		else if (seq_type == 50) { choose = 1; flag = false; }
		else { cout << "\033[0;31mВведено неправильное число, попробуйте ещё раз\033[0m" << endl; }

	}
	return choose;
}

int InputShift() {
	int shift = 0;
	cout << "\033[0;33mВведите целочисленный сдвиг\033[0m" << endl;
	cin >> shift;
	return shift;
}

int InputI() {
	int i = 0;
	cout << "\033[0;33mВведите значение, от которого будет вычисляться последовательность: \033[0m" << endl;
	cin >> i;
	return i;
}

int InputIndex(int size) {
	bool flag = true;
	int index;
	while (flag) {
		cout << "\033[0;32mВведите индекс или \033[0m\033[0;31m-1\033[0m\033[0;32m, если хотите выйти: \033[0m";
		cin >> index;
		if (index < -1 || index >= size) {
			std::cin.clear();
			system("cls");
			cout << "\033[0;31mНеверный индекс или ввод!\033[0m" << endl;
		}
		else {
			flag = false;
		}
	}
	return index;
}

void AddSequence(SequenceList& arr) {
	system("cls");
	int index = InputIndex(arr.get_size()+2);
	if (index == -1)return;
	char FactSeq[] = "FactSequence";
	char SquareSeq[] = "SquareSequence";
	if (InputType() == 0) {
		auto const Square = make_shared<SquareSequence>(InputI(), InputShift());
		arr.add(Square);
	}
	else {
		auto const Factorial = make_shared<FactSequence>(InputI());
		arr.add(Factorial);
	}
}


void DeleteCharacter(SequenceList& arr) {
	int index = InputIndex(arr.get_size());
	if (index != -1) { arr.remove(index); }
}

void FindMinElem(SequenceList& arr) {
	system("cls");
	int index = index_of_min_value(arr);
	cout << "Последовательностью с минимальным n-ым членом" << " является - " << (typeid(*arr[index]) == typeid(SquareSequence) == 0 ? "Factorial" : "Square") << endl;
	get_key();
}

void ChangeSequence(SequenceList& arr) {
	system("cls");
	int index = InputIndex(arr.get_size());
	if (InputType() == 0) {
		auto const Square = make_shared<SquareSequence>(InputI(), InputShift());
		arr[index] = Square;
	}
	else {
		auto const Factorial = make_shared<FactSequence>(InputI());
		arr[index] = Factorial;
	}
}

int menu1() {
	cout << "1)" << "\033[0;32mДобавить последовательность в массив по индексу\033[0m" << endl;
	cout << "2)" << "\033[0;32mУдалить последовательность из массива по индексу\033[0m" << endl;
	cout << "3)" << "\033[0;32mВывести последовательности на экран\033[0m" << endl;
	cout << "4)" << "\033[0;32mВывести последовательность с минимальным n-ым членом\033[0m" << endl;
	cout << "5)" << "\033[0;32mЗаменить последовательность из массива по индексу\033[0m" << endl;
	cout << "6)" << "\033[0;32mВыйти\033[0m" << endl;

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
		cout << "\033[1;34mМеню:\033[0m " << endl;
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