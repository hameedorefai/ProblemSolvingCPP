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
void PrintInvertedPattern(int Number) {
	for (int i = Number; i > 0; i--) {
		for (int j = 0; j < i; j++)
			cout << i;
		cout << endl;
	}
}

int main() {
	PrintInvertedPattern(ReadPositiveNumber("Enter A Positive Number"));
	return 0;
}