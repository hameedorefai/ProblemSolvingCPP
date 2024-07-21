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
bool IsPerfectNumber(int Number) {
	int HalfNumber = ceil(Number / 2);
	int Sum = 0;
	for(int i=1;i<=HalfNumber;i++){

		if (Number % i == 0)
			Sum += i;
	}
	return(Number == Sum);
}
void PrintPerfectNumbersFrom1ToN(int Number) {
	for (int i = 1; i <= Number; i++) {
		if (IsPerfectNumber(i))
			cout << i << endl;
	}

}
int main() {
	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Enter a number"));


	return 0;
}