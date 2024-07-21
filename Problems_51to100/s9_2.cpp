#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//I couldn't solve it from the first time (I'ts the first problim :) ).
float ReadPositiveNumber(string Message) {
	float number;
	do {
		cout << Message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}
int CountFrequencyNumberTimes(int Number, int FrequencyNumber) {
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
void PrintAllDigitsFrequency(int Number) {
	for (int i = 0; i < 10; i++) {
		short DigitFrequency = CountFrequencyNumberTimes(Number, i);
		if(DigitFrequency>0)
		cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)." << endl;
	}
}



int main() {
	int Number = ReadPositiveNumber("Enter a Positive number");
	PrintAllDigitsFrequency(Number);
	return 0;
}