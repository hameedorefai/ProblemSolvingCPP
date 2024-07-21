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
void PrintInvertedPatternFrom1ToN(int Number) {
	for (int i = 1; i <=Number; i++) {
		for (int j = 0; j < i; j++)
			cout << i;
		cout << endl;
	}
}

int main() {
	PrintInvertedPatternFrom1ToN(ReadPositiveNumber("Enter A Positive Number"));
	return 0;
}