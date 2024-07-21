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

int NumberOfDaysInYear(int Year) {
	return IsLeapYear(Year) ? 366 : 365;
}
int NumberOfHoursInYear(int Year) {
	return NumberOfDaysInYear(Year) * 24;
}
int NumberOfMinutsInYear(int Year) {
	return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(int Year) {
	return NumberOfMinutsInYear(Year) * 60;
}

void PrintYearData(int Year)
{

	cout << "Number of Days    in year [" << Year << "] is " << NumberOfDaysInYear(Year) << endl;
	cout << "Number of Hours   in year [" << Year << "] is " << NumberOfHoursInYear(Year) << endl;
	cout << "Number of Minutes in year [" << Year << "] is " << NumberOfMinutsInYear(Year) << endl;
	cout << "Number of Seconds in year [" << Year << "] is " << NumberOfSecondsInYear(Year) << endl;
}
int main()
{
	int Year = ReadNumber("Please enter a year to check : ");
	PrintYearData(Year);
	


	return 0;
}