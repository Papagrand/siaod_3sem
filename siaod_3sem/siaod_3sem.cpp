#include "locale.h"
#include <string>
#include <iostream>

using namespace std;
string convert_to_bin(unsigned int num)
{
	unsigned int t = 0x80000000;
	string result = "";
	if (num == 0) return "0";
	while (t>0) {

		if (t & num) {
			result += "1";
		}
		else {
			result += "0";
		}
		t /= 2;
	}
	return result;

}

void third(unsigned int& numb, int& digit) {

	numb = numb << digit;
}
void fourth(unsigned int& numb, int& digit) {
	
	numb = numb >> digit;

}
void fifth(unsigned int& numb, unsigned int& mask, int& n) {
	mask = mask >> n;	
	numb = numb | mask;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int g = -1;
	while (g!=0)
	{
		cout<<"1)Установить заданные биты в значение 1(3-ий, 5 - ый, 11 - ый)\n2)Обнулить заданные биты(Четыре младших)\n3)Умножить значение целочисленной переменной на множитель(128)\n4)Разделить значение целочисленной переменнойна множитель(128)\n5)Установить n - ый бит в 1, используя маску 2\n0)Завершить программу\n\nВыберите номер задания : ";
		cin >> g;
		cout << endl;
		switch (g) {
			case 1: {
				cout << "1ое упражнение\n";
				unsigned int numb;
				cout << "Введите число" << "\n";
				cin >> numb;
				unsigned int mask = 2088;
				cout << "First test\n";
				cout << "number hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl;
				cout << "mask hex: " << hex << mask << " , bin:   " << convert_to_bin(mask) << " ,dec: " << dec << mask << endl;
				cout << "result hex: " << hex << (numb | mask) << " , bin: " << convert_to_bin(numb|mask) << " ,dec: " << dec << (numb | mask) << endl << endl;
				break;
			}
			case 2: {
				cout << "2ое упражнение\n";
				unsigned int numb;
				cout << "Введите число" << "\n";
				cin >> numb;
				unsigned int mask =0xFFFFFFF0 ;
				cout << "number hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl;
				cout << "mask hex: " << hex << mask << " , bin: " << convert_to_bin(mask) << " ,dec: " << dec << mask << endl;
				cout << "result hex: " << hex << (numb & mask) << " , bin: " << convert_to_bin(numb & mask) << " ,dec: " << dec << (numb & mask) << endl << endl;
			}
			case 3: {
				cout << "3е упражнение\n";
				cout << "Введите исходное число: ";
				int digit;
				unsigned int numb;
				cin >> numb;
				digit = 7;
				cout << "number before" << endl << "hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl;
				third(numb, digit);
				cout << "number after" << endl << "hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl << endl;
				break;
			}
			case 4: {
				cout << "4ое упражнение\n";
				cout << "Введите исходное число: ";
				unsigned int numb;
				int digit;
				cin >> numb;
				digit = 7;
				cout << "number before" << endl << "hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl;
				fourth(numb, digit);
				cout << "number after" << endl << "hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl << endl;
				break;
			}
			case 5: {
				cout << "5ое упражнение\n";
				cout << "Введите исходное число: ";
				unsigned int numb;
				cin >> numb;
				cout << endl;
				int n;
				cout << "Введите n: ";
				cin >> n;
				unsigned int mask;
				mask = 0x80000000;
				cout << "number before" << endl << "hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl;
				fifth(numb, mask, n);
				cout << "number after" << endl << "hex: " << hex << numb << " , bin: " << convert_to_bin(numb) << " ,dec: " << dec << numb << endl << endl;
				break;
			}
		}
	}
}