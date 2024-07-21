#include <iostream>
using namespace std;

int readNumber() {
	cout << "Enter a number : " << endl;
	int number;
	cin >> number;
	return number;
}
int getSumOddFrom1ToN(int number) {
	int sum = 0;
	int i=1;
	while (i<=number) {
		
		if (i % 2 != 0)
			sum += i;
		i++;
		
	}
	return sum;
}

void printSumOdd(int sum) {
	cout << "Sum of Odd numbers is : " << sum << endl;
}

int main() {
	printSumOdd(getSumOddFrom1ToN(readNumber()));
	return 0;
}
