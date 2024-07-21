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
int GetSumOfDigits(int Number) {
	int LeftNumber,SumDigits=0;
	while (Number > 0) {
		LeftNumber = Number % 10;
		SumDigits += LeftNumber;
		Number = Number * 0.10;
	}
	return SumDigits;

}
void PrintSumDigits(int Number) {
	int SumOfDigits = GetSumOfDigits(Number);
	cout << "Sum Of Digits is : " << SumOfDigits << endl;
	

}


int main() {
	PrintSumDigits((int)ReadPositiveNumber("Enter a Positive Number : "));

	return 0;
}