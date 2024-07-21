#include <iostream>
using namespace std;

int readNumber() {
	cout << "Enter a number : " << endl;
	int number;
	cin >> number;
	return number;
}
void printFromNTo1(int number) {
	while(number>0){
		cout << number << endl;
		number--;
	}
}

int main() {
	printFromNTo1(readNumber());
	return 0;
}