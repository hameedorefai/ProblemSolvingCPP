#include <iostream>

using namespace std;


string NumberToText(long long Number)
{
	if (Number == 0)
	{
		return "";
	}
	else if (Number >= 1 && Number <= 19)
	{
		string arr[] =
		{ "", "One", "Tow", "Three", "Four",
		"Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Elevent", "Twelve",
		"Thirteen","Fourteen","Fifteen",
		"Sixteen","Seventeen","Eighteen",
		"Ninteen" };

		return arr[Number] + " ";
	}
	else if (Number >= 20 && Number <= 99)
	{
		string arr[] =
		{ "", "", "Twenty", "Thirty", "Fourty",
		"Fivty", "Sixty", "Seventy", "Eightty",
		"Ninety" };

		return arr[Number / 10] + " " + NumberToText(Number % 10);
	}
	else if (Number >= 100 && Number <= 199)
	{	
		return "One hundred " + NumberToText(Number % 100);
	}
	else if (Number >= 200 && Number <= 999)
	{
		return NumberToText(Number / 100) + "hundreds " + NumberToText(Number % 100);
	}
	else if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + NumberToText(Number % 1000);
	}
	else if (Number >= 2000 && Number <= 99999)
	{
		return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
	}
	else if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Million " + NumberToText(Number % 1000000);
	}
	else if (Number >= 2000000 && Number <= 999999999)
	{
		return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
	}
	else if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One Billion " + NumberToText(Number % 1000000000);
	}
	else
	{
		return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);

	}

}
long long ReadNumber()
{
	long long Number = 0;
	cout << "Enter a number : ";
	cin >> Number;
	return Number;
}

int main()
{
	long long Number = ReadNumber();

	cout << "Number by text : ";
	cout << NumberToText(Number) << endl;


	return 0;
}