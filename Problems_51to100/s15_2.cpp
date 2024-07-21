#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadPositiveNumber(string Message) {
	float number;
	do {
		cout << Message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}
void PrintLetters(int Number) {
	for (int i = 1; i <=Number; i++) {
		for (int j = 0; j < i; j++)
			cout << char(i+ 64);
		cout << endl;
	}
}

int main() {
	PrintLetters(ReadPositiveNumber("Enter A Positive Number"));
	return 0;
}