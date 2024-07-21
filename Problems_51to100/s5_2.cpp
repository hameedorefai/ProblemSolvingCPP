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
void PrintReveredDigits(int Number) {
	int LeftNumber;
	while (Number > 0) {
		 LeftNumber = Number % 10;
		cout<< LeftNumber<<endl;
		Number = Number * 0.10;
	} 

}

int main() {
	PrintReveredDigits(ReadPositiveNumber("Enter a Positive Number : "));

	return 0;
}