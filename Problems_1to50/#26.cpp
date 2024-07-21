#include <iostream>
using namespace std;

int readNumber() {
	cout << "Enter a number : " << endl;
	int number;
	cin >> number;
	return number;
}
void printFrom1ToN(int number) {
	for (int i = 1; i <= number; i++) {
		cout << i << endl;
	}
}

int main() {
	printFrom1ToN(readNumber());
	return 0;
}