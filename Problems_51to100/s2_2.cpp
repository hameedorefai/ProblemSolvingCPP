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
bool IsPrime(int number) {
	int HalfNumber = ceil(number / 2);
	for (int i = 2; i <= HalfNumber; i++) {
		if (number % i == 0)
			return 0;
	}
	return 1;
}
void PrintPrimeFrom1ToN(int number) {
	cout << "Prime numbers from 1 to " << number << " is : " << endl;
	for(int i=1;i<=number;i++){
		if (IsPrime(i))
			cout << i << endl;
		else
			continue;
	}
}

int main() {
	PrintPrimeFrom1ToN(ReadPositiveNumber("Enter a number"));
}