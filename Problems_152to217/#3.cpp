#include <iostream>

using namespace std;


long long ReadNumber()
{
	long long Number = 0;
	cout << "Enter a number : ";
	cin >> Number;
	return Number;
}
bool IsLeapYear(int Year)
{
	return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}

int main()
{
	int Year = ReadNumber();

	if (IsLeapYear(Year))
		cout << Year << " is a Leap year." << endl;
	else
		cout << Year << " is NOT a Leap year." << endl;


	return 0;
}