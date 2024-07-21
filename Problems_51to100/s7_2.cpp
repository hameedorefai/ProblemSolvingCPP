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
void PrintReversedNumber(int Number) {
	int LeftNumber, arrReversedNumbers[10],i=0;
	int Number2 = 0;

	while (Number > 0) {
		LeftNumber = Number % 10;
		Number = Number * 0.10;
		Number2 = Number2 * 10 + LeftNumber;
		
	}
	cout << "Reverse is : " << Number2 << endl;

	/*while (Number > 0) {
		arrReversedNumbers[i] = Number % 10;
		Number = Number * 0.10;
		i++;
	}
	cout << "Reverse is : ";
	for (int j = 0; j < i; j++) {
		 cout<< arrReversedNumbers[j];
	}*/
	cout << endl;
	

}



int main() {
	PrintReversedNumber((int)ReadPositiveNumber("Enter a Positive Number : "));

	return 0;
}