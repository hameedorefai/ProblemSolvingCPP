#include <iostream>

using namespace std;


int ReadNumber(string Message = "")
{
	int Number = 0;
	cout << Message;
	cin >> Number;
	return Number;
}
bool IsLeapYear(int Year)
{
	return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}

int NumberOfDaysInMonth(int Year, int Month) 
{
	if (Month > 12 || Month < 1)
		return 0;
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ( Month == 2) ? (IsLeapYear(Year)) ? 29 : 28 : NumberOfDays[Month-1];
}

int main()
{
	int Year = ReadNumber("Please enter year to check : ");
	int Month = ReadNumber("Please enter Month to check : ");

	cout << "Number of Days    in Month [" << Month << "] is "
		<< NumberOfDaysInMonth(Year, Month) << endl;


	return 0;
}