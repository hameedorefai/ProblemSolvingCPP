#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum eDayName {
	Sunday = 0,
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thirsday = 4,
	Friday = 5,
	Satarday = 6,
};
enum eInputTybe{ eDay, eMonth, eYear};
int ReadDate(string Message, eInputTybe InTybe)
{
	int Number = 0;
	cout << Message;
	cin >> Number;

	switch (InTybe)
	{
	case eDay:
	{
		if (Number <= 0 || Number > 31)
		{
			cout << "Error in Day input.\n";
			return 0;
		}
		else break;
	}
	case eMonth:
	{
		if (Number <= 0 || Number > 12)
		{
			cout << "Error in Month input.\n";
			return 0;
		}
		else break;
	}
	case eYear:
	{
		if (Number <= 0)
		{
			cout << "Error in Year input.\n";
			return 0;
		}
		else break;
	}
	default :
		cout << "\nError in ReadNumber Function.\n";
	}

	
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
string GetDayName(short Day)
{	
	switch (Day)
	{
	case Sunday:
		return "Sunday";
	case Monday:
		return "Monday";
	case Tuesday:
		return "Teusday";
	case Wednesday:
		return "Wednesday";
	case Thirsday:
		return "Thirsday";
	case Friday :
		return "Firday";
	case Satarday:
		return "Satarday";
		
	default :
		return "\nWrong in GetDayName Function.\n";
	}
}
int CalculateDayOrder(int Year, short Month, short Day)
{
	// Calculate it using Gregorian Calender
	int A = (14 - Month) / 12;
	int Y = Year - A;
	int M = Month + (12 * A) - 2;
	int D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	return D;
}
int main()
{
	int Year = ReadDate("Please enter year to check : ", eYear);
	short Month = ReadDate("Please enter Month to check : ", eMonth);
	short Day = ReadDate("Please enter Day to check : ", eDay);

	short DayOrder = CalculateDayOrder(Year, Month, Day);

	cout << "Date		: " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order	: " << DayOrder << endl;
	cout << "Day Name	: " << GetDayName(DayOrder) << endl;

	return 0;
}