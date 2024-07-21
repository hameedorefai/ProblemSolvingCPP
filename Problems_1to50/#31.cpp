#include <iostream>
using namespace std;

int readNum() {
	int number;
	cout << "Enter a Number : ";
	cin >> number;
	return number;
}
int read_And_PrintPowerOf(int number) {
	int power = number;
	int powArr[10];

	for (int i = 0; i < 3; i++) {
		power *= number;
		powArr[i] = power;
	}
	for (int i = 0; i < 3; i++)
				cout << powArr[i] << endl;
	//return powArr[];
	return 0;
}
//void printPowerOf(int powArr[]) {
//	for (int i = 0; i < 3; i++)
//		cout << powArr[i] << endl;
//
//}
int main() {
	read_And_PrintPowerOf(readNum());
	return 0;
}