#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

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

bool IsVowel(char L) {

	L = tolower(L);
		return (L == 'a' || L == 'e' || L == 'i' || L == 'o' || L == 'u');

}

short  CountVowels(string S1) {

	short Counter = 0;

	for (int i = 0; i < S1.size(); i++)
	{
		if (IsVowel(S1[i]))
			Counter++;
	}

	return Counter;
}


int main()
{	
	string S1 = ReadString();

	cout << "Number of vowels is : " << CountVowels(S1) << endl;

	return 0;

}

