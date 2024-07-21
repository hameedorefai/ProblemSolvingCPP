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
int ReversedDigits(int Number) {
	int LeftNumber;
	int ReversedNumber = 0;
	while (Number > 0) {
		LeftNumber = Number % 10;
		Number = Number * 0.10;
		ReversedNumber = ReversedNumber * 10 + LeftNumber;
	}
	return ReversedNumber;
}
bool IsPalindromeNumber(int Number) {
	return (ReversedDigits(Number) == Number);
	/*if (ReversedDigits(Number) == Number)
		return 1;
	else
		return 0;*/
}
void PrintResult(bool IsPalindrome) {
	if (IsPalindrome)
		cout << "Yes, It is a Palindrome number." << endl;
	else
		cout << "No, It is NOT a Palindrome number." << endl;
}
int main() {
	PrintResult(IsPalindromeNumber(ReadPositiveNumber("Enter A Positive Number")));
	return 0;
}