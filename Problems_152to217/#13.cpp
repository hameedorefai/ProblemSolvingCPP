#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
short GetTotalDays(int, short, short);

enum eDayName {
	Sunday = 0,
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thirsday = 4,
	Friday = 5,
	Satarday = 6,
};
struct sDate
{
	int Year;
	short Month;
	short Day;
	short TotalDaysInYearUntillDate;

};
enum eInputTybe { eDay, eMonth, eYear };
int ReadDate(string Message, eInputTybe InTybe = eYear)
{
	// This function reads a number by the way user choiced.
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
	default:
		cout << "\nError in ReadNumber Function.\n";
	}


	return Number;
}
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDate("Please enter Day to check : ", eDay);
	Date.Month = ReadDate("Please enter Month to check : ", eMonth);
	Date.Year = ReadDate("Please enter year to check : ", eYear);
	return Date;
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
	return (Month == 2) ? (IsLeapYear(Year)) ? 29 : 28 : NumberOfDays[Month - 1];
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
	case Friday:
		return "Firday";
	case Satarday:
		return "Satarday";

	default:
		return "\nWrong in GetDayName Function.\n";
	}
}
string GetMonthName(short Month)
{
	string arrMonthName[12] = { "Jan", "Feb", "Mar", "Apr",
		"May", "Jun", "Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec" };
	return arrMonthName[Month - 1];
}

int CalculateDayOrder(int Year, short Month, short Day)
{
	//  Calculate it using Gregorian Calender
	int A = (14 - Month) / 12;
	int Y = Year - A;
	int M = Month + (12 * A) - 2;
	int D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	return D;
}
void PrintMonthCalender(int Year, short Month)
{
	short MonthDays = NumberOfDaysInMonth(Year, Month);
	short Current = CalculateDayOrder(Year, Month, 1);
	short i;

	cout << "_____________" << GetMonthName(Month) << "_____________" << endl;
	cout <<" Sun Mon Tue Wed Thi  Fri Sat" << endl;

	for (i = 0; i < Current; i++)
		printf("    ");
	for (int j = 1; j <= MonthDays; j++)
	{
		printf("%4d", j);
		if (++i == 7)
		{
			i = 0;
			cout << endl;
		}
	}
	cout << "\n_____________________________" << endl;

}
void PrintYearCalender(int Year) 
{
	cout << "\n_____________________________\n" << endl;
	cout << "	Calender - " << Year << endl;
	cout << "_____________________________" << endl;

	for (int i = 1; i <= 12; i++)
	{
		PrintMonthCalender(Year, i);
		cout << endl;
	}
}
short GetTotalDays(int Year, short Month, short Day)
{
	// Getting Total days from 1 January untill the day user input from the year.
	short TotalDays = Day;
	short CurrMonth = 1;
	while (Month != CurrMonth)
	{
		TotalDays += NumberOfDaysInMonth(Year, CurrMonth);
		CurrMonth++;
	}
	return TotalDays;
}
void PrintTotalDays(int Year, short Month, short Day)
{
	// Printing Total days from 1 January untill the the day user input from the year.
	cout << "Number of days from the bigening of the year is : " << GetTotalDays(Year, Month, Day) << endl;
}
sDate GetDateByYearAndTotalDays(int Year, short TotalDays)
{
	sDate Date;
	short CurrentMonthDays = 0;
	short DaysLeft = TotalDays;
	int i;
	for ( i = 1; i <= 12; i++)
	{
		CurrentMonthDays = NumberOfDaysInMonth(Year, i);
		if (DaysLeft > CurrentMonthDays)
		{
			DaysLeft -= CurrentMonthDays;
		}
		else
		{
			break;
		}
	}
	Date.Day = DaysLeft;
	Date.Month = i;
	Date.Year = Year;
	return Date;
}
sDate AddDaysToDate(sDate Date, int DaysToAdd)
{
	
	DaysToAdd += GetTotalDays(Date.Year, Date.Month, Date.Day);

	while (true)
	{
		if (DaysToAdd >= 365)
		{
			IsLeapYear(Date.Year) ? DaysToAdd -= 366 : DaysToAdd -= 365;
			Date.Year++;
		}
		else
		{
			break;
		}
	}

	return GetDateByYearAndTotalDays(Date.Year, DaysToAdd);

}
bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
	if (Date1.Year < Date2.Year)
		return 1;
	else if (Date1.Year > Date2.Year)
		return 0;
	return (GetTotalDays(Date1.Year, Date1.Month, Date1.Day) < GetTotalDays(Date2.Year, Date2.Month, Date2.Day);

}
int main()
{
	sDate Date1,Date2;
	Date1 = ReadFullDate();
	Date2 = ReadFullDate();

	if (IsDate1LessThanDate2(Date1, Date2))
	{
		cout << "Yes, Date1 is less than Date2\n";
	}
	else 
		cout << "No, Date1 is Not less than Date2\n";
	return 0;
}