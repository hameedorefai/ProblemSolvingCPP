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
char InveredLetterCase(char Letter) {

	return (isupper(Letter) ? tolower(Letter) : toupper(Letter));

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
short CountLetter(string S1, char Letter, bool MatchCase = true) {
	
	short Counter = 0;
	
	for (int i = 0; i < S1.length(); i++)
	{
		if (MatchCase) {
			if (S1[i] == Letter)
				Counter++;
		}
		else {
			if (tolower(S1[i]) == tolower(Letter)) {
				Counter++;
			}
		}
	}
	return Counter;
}

short CountLetter(string S1, enWhatToCount WhatToCount = All) {
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
	char Letter = ReadChar();
	char InvertedLetter = InveredLetterCase(Letter);
	short CountTheLetter = CountLetter(S1, Letter);
	short CountWithInvertedLetter = CountLetter(S1, InvertedLetter);

	cout << "Letter \" " << Letter << " \" count = " << CountTheLetter << endl;
	cout << "Letter \" " << Letter << " \" and \" " << InvertedLetter << " \"count = " << CountTheLetter + CountWithInvertedLetter << endl;
	cout << endl << endl << endl;


	cout << "Letter \" " << Letter << " \" count = " << CountLetter(S1,Letter) << endl;
	cout << "Letter \" " << Letter << " \" and \" " << InvertedLetter<< " \"count = " << CountLetter(S1,Letter,false) << endl;


	return 0;

}

