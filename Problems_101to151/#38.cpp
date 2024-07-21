#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

string ReadString(string Message = "")
{
	string Words;
	(Message == "" ? cout << "Enter a String : \n" : cout << Message);
	getline(cin, Words);
	return Words;
} 
string TrimLeft(string S1)
{
	string Delim = " ";

	while (S1[0] == ' ')
	{
		S1 = S1.erase(0, Delim.length());
	}

	return S1;
}
string TrimRight(string S1)
{

	short Position = 0;
	string Delim = " ";
	string Word = "";
	string Words;
	short DLength = 0;

	for (short i = S1.length() - 1; i > 0; i--)
	{
		if (S1[i] == ' ')
		{
			S1.erase(i, S1.length());
		}
		else
		{
			break;
		}

	}
	return S1;
}
string Trim(string&S1)
{
	return TrimLeft(TrimRight(S1));
}
int main()
{
	string S1 = "   Hameedo   ";
	cout << "Without Trimming    = " << S1 << endl;
	cout << "With Trimming Right = " << TrimRight(S1) << endl;
	cout << "With Trimming left  = " << TrimLeft(S1) << endl;
	cout << "With Trim           = " << Trim(S1) << endl;

	return 0;

}

