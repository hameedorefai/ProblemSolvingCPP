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
	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return  NumberOfDays[Month - 1];
}

int NumberOfHoursInMonth(int Year, int Month) {
	return NumberOfDaysInMonth(Year, Month) * 24;
}
int NumberOfMinutsInMonth(int Year, int Month) {
	return NumberOfHoursInMonth(Year, Month) * 60;
}
int NumberOfSecondsInMonth(int Year, int Month) {
	return NumberOfMinutsInMonth(Year, Month) * 60;
}
void PrintMonthData()
{
	int Year = ReadNumber("Please enter year to check : ");
	int Month = ReadNumber("Please enter Month to check : ");

	cout << "Number of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Year, Month) << endl;
	cout << "Number of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year, Month) << endl;
	cout << "Number of Minutes in Month [" << Month << "] is " << NumberOfMinutsInMonth(Year, Month) << endl;
	cout << "Number of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month) << endl;
}
int main()
{
	PrintMonthData();

	return 0;
}