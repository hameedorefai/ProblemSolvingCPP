#include <iostream>
using namespace std;
void printFactorial(long);
int readNumber() {
	int number;
	cout << "Enter a number : " << endl;
	cin >> number;
	return number;
}

bool isPositiveNumber(int number) {
	if (number >0)
		return 1;
	else
		return 0;
}
long getFactorial(int number) {
	long  sumFact = 1;
	int i = number;
	if (isPositiveNumber(number)) {
		while (i > 0) {
			sumFact *= i;
			i--;
		}
		return sumFact;
	}
	else {
		cout << "That is a negative number!" << endl;
		//printFactorial(getFactorial(readNumber()));
		return 0;
	}

}

void printFactorial( long sum) {
	if(isPositiveNumber(sum))
	cout << "Factorial is : " << sum << endl;
}

int main() {
	printFactorial(getFactorial(readNumber()));
	return 0;
}