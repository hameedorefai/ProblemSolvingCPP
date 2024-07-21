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
	/*if (Number == Sum)
		return true;
	else
		return false;*/
}
void PrintPerfectNumber(int Number) {
	if (IsPerfectNumber(Number))
		cout << Number << " is perfect number." << endl;
	else
		cout << Number << " is not perfect number." << endl;

}
int main() {
	PrintPerfectNumber(ReadPositiveNumber("Enter a number")); 


	return 0;
}