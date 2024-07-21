#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

enum enWhatToCount {SmallLetters, CapitalLetters, All};
string ReadString(string Message = "") {
	string Words;
	(Message == "" ? cout << "Enter a String : \n" : cout << Message);
	getline(cin, Words);
	return Words;
}

short CountLetters(string S1, enWhatToCount WhatToCount = All) {
	short Counter = 0;
	
	if (WhatToCount == All)
	{
		return S1.length();
	}
	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == CapitalLetters && isupper(S1[i]))
			Counter++;
		if (WhatToCount == SmallLetters && islower(S1[i]))
			Counter++;
	}
	return Counter;
}

short GetCountUpperCaseInString(string S1) {
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			Counter++;
	}
	return Counter;
}
short GetCountLowerCaseInStringLength(string S1) {
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			Counter++;
	}
	return Counter;
}


int main()
{
	string S1 = ReadString();
	
	cout << "Length of string    : " << CountLetters(S1) << endl;
	cout << "UpperCase in string : " << CountLetters(S1,CapitalLetters) << endl;
	cout << "LowerCase in string : " << CountLetters(S1,SmallLetters) << endl;


	return 0;

}

