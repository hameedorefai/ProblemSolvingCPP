#include <iostream>
using namespace std;

int readNumber() {
	cout << "Enter a number : " << endl;
	int number;
	cin >> number;
	return number;
}
int getSumEvenFrom1ToN(int number) {
	int sum = 0;
	int i=1;
	while (i<=number) {
		if (i % 2 == 0)
			sum += i;
		i++;
	}
	return sum;
}

void printSumEven(int sum) {
	cout << "Sum of Even numbers is : " << sum << endl;
}

int main() {
	printSumEven(getSumEvenFrom1ToN(readNumber()));
	return 0;
}