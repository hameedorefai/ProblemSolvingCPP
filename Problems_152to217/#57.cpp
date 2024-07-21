#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <time.h>
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
enum enCompareDates{ Befor = -1, Equal = 0, After = 1};
struct stDate
{
	int Year;
	short Month;
	short Day;
	short TotalDaysInYearUntillDate;
	int AllDateDays;
	int DayOfWeekOrder;

};
void PrintDate(stDate);

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
stDate ReadFullDate()
{
	stDate Date;
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

short DayOfWeekOrder(int Year, short Month, short Day)
{
	//  Calculate it using Gregorian Calender
	int A = (14 - Month) / 12;
	int Y = Year - A;
	int M = Month + (12 * A) - 2;
	int D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	return D;
}
short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}
void PrintMonthCalender(int Year, short Month)
{
	short MonthDays = NumberOfDaysInMonth(Year, Month);
	short Current = DayOfWeekOrder(Year, Month, 1);
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
stDate GetDateByYearAndTotalDays(int Year, short TotalDays)
{
	stDate Date;
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
stDate AddDaysToDate(stDate Date, int DaysToAdd)
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
int GetAllDateDays(stDate Date)
{
	int AllDateDays = Date.Day;
	//if(Date.Year != 1)
	for (int CurrentYear = 1; CurrentYear < Date.Year; CurrentYear++)
	{
		IsLeapYear(CurrentYear) ? AllDateDays += 366 : AllDateDays += 365;
	}
	if (Date.Month != 1)
		for (int CurrentMonth = 1; CurrentMonth < Date.Month; CurrentMonth++)
			AllDateDays += NumberOfDaysInMonth(Date.Year, CurrentMonth);

	return AllDateDays;
}
int GetDifferenceBetween2DatesByDays(stDate& Date1, stDate& Date2, bool IncludeEndDay = false)
{
	Date1.AllDateDays = GetAllDateDays(Date1);
	Date2.AllDateDays = GetAllDateDays(Date2);

	int Difference = Date2.AllDateDays - Date1.AllDateDays;
	int DifferenceIncludeDay = (Date2.AllDateDays == Date1.AllDateDays ? 0 : 1) + Difference;

	if (!IncludeEndDay)
		return Difference;
	else
	{
		if (Date2.AllDateDays >= Date1.AllDateDays)
			return DifferenceIncludeDay;
		else
			return DifferenceIncludeDay - 2;
	}


}
void PrintDifferenceBetween2DatesByDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	if (!IncludeEndDay)
	{
		int Difference = GetDifferenceBetween2DatesByDays(Date1, Date2);
		cout << "Difference is : " << Difference << " Day(s)\n";
	}
	else
	{
		int DifferenceIncludeDay = GetDifferenceBetween2DatesByDays(Date1, Date2, true);
		cout << "Difference (including end day) is : " << DifferenceIncludeDay << " Day(s)\n";
	}
}
stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);

	Date.Year = now.tm_year + 1900;
	Date.Month = now.tm_mon + 1;
	Date.Day = now.tm_mday;
	return Date;
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year < Date2.Year)
		return 1;
	else if (Date1.Year > Date2.Year)
		return 0;
	return (GetTotalDays(Date1.Year, Date1.Month, Date1.Day) < GetTotalDays(Date2.Year, Date2.Month, Date2.Day));

}
bool IsDate1EqualsThanDate2(stDate Date1, stDate Date2)
{
	return ((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));
}
bool IsDate1MoreThanDate2(stDate Date1, stDate Date2)
{
	return !(IsDate1LessThanDate2(Date1, Date2) || IsDate1EqualsThanDate2(Date1, Date2));
}
enCompareDates CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1LessThanDate2(Date1, Date2))
		return Befor;
	if (IsDate1EqualsThanDate2(Date1, Date2))
		return Equal;
	//if(IsDate1MoreThanDate2(Date1,Date2))
	return After;
}

bool IsLastDayInMonth(stDate Date)
{
	return (NumberOfDaysInMonth(Date.Year, Date.Month) == Date.Day);
}
bool IsLastMonthInYear(short Month)
{
	return(Month == 12);
}


stDate IncreasDateByOneDay(stDate&Date)
{
	if (IsLastDayInMonth(Date) && IsLastMonthInYear(Date.Month))
	{
		Date.Year++;
		Date.Month = 1;
		Date.Day = 1;
	}
	else if (IsLastDayInMonth(Date))
	{
		Date.Month ++;
		Date.Day = 1;
	}
	else
		Date.Day++;
	return Date;
}
stDate IncreasDateByXDays(stDate&Date, int XDays)
{
	for (int i = 0; i < XDays; i++)
	{
		IncreasDateByOneDay(Date);
	}
	return Date;
}
stDate IncreasDateByOneWeek(stDate& Date)
{
	IncreasDateByXDays(Date, 7);
	return Date;
}
stDate IncreasDateByXWeeks(stDate& Date, int XWeeks)
{

	for (int i = 0; i < XWeeks; i++)
	{
		IncreasDateByOneWeek(Date);
	}
	return Date;
}
stDate IncreasDateByOneMonth(stDate& Date)
{
	stDate TempDate = Date;
	if (IsLastMonthInYear(Date.Month))
	{
		Date.Year++;
		Date.Month = 1;
	}
	else
		Date.Month++;
	int CurrentMonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (TempDate.Day > CurrentMonthDays)
	{
		Date.Day = CurrentMonthDays;
	}


	return Date;
}
stDate IncreasDateByXMonths(stDate& Date, int XMonths)
{
	for (int i = 0; i < XMonths; i++)
	{
		IncreasDateByOneMonth(Date);
	}
	return Date;
}
stDate IncreaseDateByOneYear(stDate& Date)
{
	Date.Year++;
	return Date;
}
stDate IncreaseDateByXYears(stDate& Date, int XYears)
{
	for (int i = 0; i < XYears; i++)
		IncreaseDateByOneYear(Date);
	return Date;

}
stDate IncreaseDateByXYearsFaster(stDate& Date, int XYears)
{
	Date.Year += XYears;
	return Date;

}
stDate IncreaseDateByOneDecade(stDate& Date)
{
	Date.Year += 10;
	return Date;
}
stDate IncreaseDateByXDecades(stDate& Date, int XDecades)
{
	for (int i = 0; i < XDecades; i++)
		IncreaseDateByOneDecade(Date);
	return Date;
}
stDate IncreaseDateByXDecadesFaster(stDate& Date, int XDecades)
{
	/*for (int i = 0; i < XDecade; i++)
		Date.Year += 10;*/
	Date.Year += XDecades * 10;
	return Date;
}
stDate IncreaseDateByOneCentury(stDate& Date)
{
	Date.Year += 100;
	return Date;
}
stDate IncreaseDateByOneMillennium(stDate& Date)
{
	Date.Year += 1000;
	return Date;
}
void PrintDateAfterIncrease(stDate Date)
{

	cout << "\nDate : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;
	cout << "Date After..\n\n";
	IncreasDateByOneDay(Date);
	printf("%d-Adding one day  : ", 1); PrintDate(Date);
	IncreasDateByXDays(Date, 10);
	printf("%d-Adding 10 days  : ", 2); PrintDate(Date);
	IncreasDateByOneWeek(Date);
	printf("%d-Adding one Week : ", 3); PrintDate(Date);
	IncreasDateByXWeeks(Date, 10);
	printf("%d-Adding 10 Weeks : ", 4); PrintDate(Date);
	IncreasDateByOneMonth(Date);
	printf("%d-Adding one Month: ", 5); PrintDate(Date);
	IncreasDateByXMonths(Date, 5);
	printf("%d-Adding 5 Months : ", 6); PrintDate(Date);
	IncreaseDateByOneYear(Date);
	printf("%d-Adding one Year : ", 7); PrintDate(Date);
	IncreaseDateByXYears(Date, 10);
	printf("%d-Adding 10 Years : ", 8); PrintDate(Date);
	IncreaseDateByXYearsFaster(Date, 10);
	printf("%d-Adding 10 Years (Faster) : ", 9); PrintDate(Date);
	IncreaseDateByOneDecade(Date);
	printf("%d-Adding one Decade: ", 10); PrintDate(Date);
	IncreaseDateByXDecades(Date, 10);
	printf("%d-Adding 10 Decades: ", 11); PrintDate(Date);
	IncreaseDateByXDecadesFaster(Date, 10);
	printf("%d-Adding 10 Decades (Faster) : ", 12); PrintDate(Date);
	IncreaseDateByOneCentury(Date);
	printf("%d-Adding one Century    : ", 13); PrintDate(Date);
	IncreaseDateByOneMillennium(Date);
	printf("%d-Adding one Millennium : ", 14); PrintDate(Date);

}

stDate DecreaseDateByOneDay(stDate& Date)
{
	if (Date.Day == 1 && Date.Month == 1)
	{
		Date.Year--;
		Date.Month = 12;
		Date.Day = 31;
	}
	else if (Date.Day == 1)
	{
		Date.Month--;
		Date.Day = NumberOfDaysInMonth(Date.Year,Date.Month);
	}
	else
		Date.Day--;
	return Date;
}
stDate DecreaseDateByXDays(stDate& Date, int XDays)
{
	for (int i = 0; i < XDays; i++)
	{
		DecreaseDateByOneDay(Date);
	}
	return Date;
}
stDate DecreaseDateByOneWeek(stDate& Date)
{
	DecreaseDateByXDays(Date, 7);
	return Date;
}
stDate DecreaseDateByXWeeks(stDate& Date, int XWeeks)
{

	for (int i = 0; i < XWeeks; i++)
	{
		DecreaseDateByOneWeek(Date);
	}
	return Date;
}
stDate DecreaseDateByOneMonth(stDate& Date)
{
	stDate TempDate = Date;
	if (1 == Date.Month)
	{
		Date.Year--;
		Date.Month = 12;
	}
	else
		Date.Month--;

	int CurrentMonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (TempDate.Day > CurrentMonthDays)
	{
		Date.Day = CurrentMonthDays;
	}


	return Date;
}
stDate DecreaseDateByXMonths(stDate& Date, int XMonths)
{
	for (int i = 0; i < XMonths; i++)
	{
		DecreaseDateByOneMonth(Date);
	}
	return Date;
}
stDate DecreaseDateByOneYear(stDate& Date)
{
	Date.Year--;
	return Date;
}
stDate DecreaseDateByXYears(stDate& Date, int XYears)
{
	for (int i = 0; i < XYears; i++)
		DecreaseDateByOneYear(Date);
	return Date;

}
stDate DecreaseDateByXYearsFaster(stDate& Date, int XYears)
{
	Date.Year -= XYears;
	return Date;

}
stDate DecreaseDateByOneDecade(stDate& Date)
{
	Date.Year -= 10;
	return Date;
}
stDate DecreaseDateByXDecades(stDate& Date, int XDecades)
{
	for (int i = 0; i < XDecades; i++)
		DecreaseDateByOneDecade(Date);
	return Date;
}
stDate DecreaseDateByXDecadesFaster(stDate& Date, int XDecades)
{

	Date.Year -= XDecades * 10;
	return Date;
}
stDate DecreaseDateByOneCentury(stDate& Date)
{
	Date.Year -= 100;
	return Date;
}
stDate DecreaseDateByOneMillennium(stDate& Date)
{
	Date.Year -= 1000;
	return Date;
}
void PrintDateAfterDecrease(stDate Date)
{

	cout << "\nDate : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;
	cout << "Date After..\n\n";
	DecreaseDateByOneDay(Date);
	printf("%d-Subtracting one day  : ", 1); PrintDate(Date);
	DecreaseDateByXDays(Date, 10);
	printf("%d-Subtracting 10 days  : ", 2); PrintDate(Date);
	DecreaseDateByOneWeek(Date);
	printf("%d-Subtracting one Week : ", 3); PrintDate(Date);
	DecreaseDateByXWeeks(Date, 10);
	printf("%d-Subtracting 10 Weeks : ", 4); PrintDate(Date);
	DecreaseDateByOneMonth(Date);
	printf("%d-Subtracting one Month: ", 5); PrintDate(Date);
	DecreaseDateByXMonths(Date, 5);
	printf("%d-Subtracting 5 Months : ", 6); PrintDate(Date);
	DecreaseDateByOneYear(Date);
	printf("%d-Subtracting one Year : ", 7); PrintDate(Date);
	DecreaseDateByXYears(Date, 10);
	printf("%d-Subtracting 10 Years : ", 8); PrintDate(Date);
	DecreaseDateByXYearsFaster(Date, 10);
	printf("%d-Subtracting 10 Years (Faster) : ", 9); PrintDate(Date);
	DecreaseDateByOneDecade(Date);
	printf("%d-Subtracting one Decade: ", 10); PrintDate(Date);
	DecreaseDateByXDecades(Date, 10);
	printf("%d-Subtracting 10 Decades: ", 11); PrintDate(Date);
	DecreaseDateByXDecadesFaster(Date, 10);
	printf("%d-Subtracting 10 Decades (Faster) : ", 12); PrintDate(Date);
	DecreaseDateByOneCentury(Date);
	printf("%d-Subtracting one Century    : ", 13); PrintDate(Date);
	DecreaseDateByOneMillennium(Date);
	printf("%d-Subtracting one Millennium : ", 14); PrintDate(Date);

}


bool IsEndOfWeek(stDate Date)
{

	short Day = DayOfWeekOrder(Date);
	return (6 == Day);
}
bool IsWeekend(stDate Date)
{
	short DayOrder = DayOfWeekOrder(Date);

	return (5 == DayOrder || 6 == DayOrder);
}
bool IsBusinessDay(stDate Date)
{
	return !IsWeekend(Date);
}
short DaysUntillTheEndOfWeek(stDate Date)
{
	short Day = DayOfWeekOrder(Date);
	return  (Day == 7) ? 6 : 6 - Day;
}
short DaysUntillTheEndOfMonth(stDate Date)
{
	int MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);

	return MonthDays - Date.Day;
}
short DaysUntillTheEndOfYear(stDate Date)
{
	// Total Days in year untill current date.
	short TotalDays = GetTotalDays(Date.Year, Date.Month, Date.Day);
	short YearDays = IsLeapYear(Date.Year) ? 366 : 365;

	return YearDays - TotalDays;
}

void ReadVacationPeriod(stDate& DateFrom, stDate& DateTo)
{
	// This function is read vacation Start date, and Vacation end date.
	cout << "Vacation Starts:\n";
	DateFrom = ReadFullDate();
	cout << "Vacation Ends:\n";
	DateTo = ReadFullDate();
}
void ReadVacationPeriod(stDate&DateFrom, short&VacationDays)
{
	// This function is read vacation Start date, and Vacation Days.
	cout << "Vacation Starts:\n";
	DateFrom = ReadFullDate();
	cout << "Please enter vacation days : ";
	cin >> VacationDays;
}
short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short VacationDaysCounter = 0;
	while (IsDate1LessThanDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
		{
			VacationDaysCounter++;
		}
		IncreasDateByOneDay(DateFrom);
	}
	return VacationDaysCounter;
}
stDate GetVacationEndDate(stDate DateFrom, short VacationDays)
{
	stDate DateTo = DateFrom;
	while (VacationDays != 0)
	{
		if (IsBusinessDay(DateTo))
		{
			VacationDays--;
		}
		IncreasDateByOneDay(DateTo);
	}
	return DateTo;
}

void PrintDate(stDate Date)
{
	int DayOrder = DayOfWeekOrder(Date);
	cout << GetDayName(DayOrder) << " , ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}
void PrintDayInfo(stDate Date)
{
	int DayOrder = DayOfWeekOrder(Date);

	cout << "\nToday is " << GetDayName(DayOrder) << " , ";
	PrintDate(Date);

	cout << "\nIs it End of week?\n";
	IsEndOfWeek(Date) ? printf("Yes, It's Saturday\n")
		: printf("No, It's NOT Saturday\n");

	cout << "\nIs it Weekend?\n";
	IsWeekend(Date) ? printf("Yes, It's Weekend\n")
		: printf("No, It's %s\n", GetDayName(DayOrder));

	cout << "\nIs it Business Day?\n";
	IsBusinessDay(Date) ? printf("Yes, It's a business day\n")
		: printf("No, It's NOT a business day\n");

	cout << "\nDays untill end of week : " << DaysUntillTheEndOfWeek(Date) << " Day(s).\n";
	cout << "Days untill end of Month: " << DaysUntillTheEndOfMonth(Date) << " Day(s).\n";
	cout << "Days untill end of Year : " << DaysUntillTheEndOfYear(Date) << " Day(s).\n";


}

int main()
{
	cout << "Enter Date1\n";
	stDate Date1 = ReadFullDate();
	cout << "Ente Date2\n";
	stDate Date2 = ReadFullDate();

	cout << "Compare result = " << CompareDates(Date1, Date2) << endl;

	return 0;
}