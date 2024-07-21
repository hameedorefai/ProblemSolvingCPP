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
int CountFrequencyNumberTimes(int Number,int FrequencyNumber) {
	int LeftNumber;
	int FrequencyTimes = 0;

	while (Number > 0) {
		LeftNumber = Number % 10;
		Number = Number * 0.10;
		if (FrequencyNumber == LeftNumber)
			FrequencyTimes++;
	}
	return FrequencyTimes;
}




int main() {
	int Number = (int)ReadPositiveNumber("Enter a Positive Number : ");
	short FrequencyNumber = (int)ReadPositiveNumber("Enter a Positive Number To Check over : ");

	cout << "Digit " << FrequencyNumber << " Frequency is ";
	cout << CountFrequencyNumberTimes(Number, FrequencyNumber);
	cout << " Time(s)" << endl;
	return 0;
}