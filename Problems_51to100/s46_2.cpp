#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber(string Message) {
	int PositiveNumber = 0;
		cout << Message << endl;
		cin >> PositiveNumber;
	return PositiveNumber;
}
int MyABS(int Number) {
	if (Number < 0)
		Number = -1 * Number;
	return Number;
}
int main() {
	int Number;
	Number = ReadNumber("Enter a Number : ");
	
	cout << "My  ABS  : " << MyABS(Number) << endl;
	cout << "C++ ABS  : " << abs(Number);

	
	return 0;
}