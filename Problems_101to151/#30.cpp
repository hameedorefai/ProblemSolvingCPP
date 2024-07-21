#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

enum enWhatToCount { SmallLetters, CapitalLetters, All };
string ReadString(string Message = "") {
	string Words;
	(Message == "" ? cout << "Enter a String : \n" : cout << Message);
	getline(cin, Words);
	return Words;
}
char ReadChar(string Message = "") {
	char Letter;
	(Message == "" ? cout << "Enter a char : \n" : cout << Message);
	cin >> Letter;
	return Letter;
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
short CountLetter(string S1, char Letter ) {
	
	short Counter = 0;
	
	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
			Counter++;
	}
	return Counter;
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


int main()
{
	string S1 = ReadString();
	char c1 = ReadChar();
	
	cout << CountLetter(S1, c1) << endl;

	return 0;

}

