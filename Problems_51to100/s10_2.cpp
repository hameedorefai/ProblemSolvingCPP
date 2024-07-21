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
int ReversedDigits(int Number) {
	int LeftNumber;
	int ReversedNumber = 0;
	while (Number > 0) {
		LeftNumber = Number % 10;
		Number = Number * 0.10;
		ReversedNumber = ReversedNumber * 10 + LeftNumber;
	}
	return ReversedNumber;
}
void PrintDigits(int ReversedNumber) {
	int LeftNumber;
	int Number2 = 0;

	while (ReversedNumber > 0) {
		LeftNumber = ReversedNumber % 10;
		ReversedNumber = ReversedNumber * 0.10;
		cout << LeftNumber << endl;

	}


}
int main() {
	PrintDigits(ReversedDigits((int)ReadPositiveNumber("Enter a Positive Number : ")));

	return 0;
}