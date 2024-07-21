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

	cout << "Vowels in string are : ";
	for (int i = 0; i < S1.size(); i++)
	{
		if (IsVowel(S1[i]))
			Counter++;
	}

	return Counter;
}
void  PrintVowels(string S1) {

	cout << "Vowels in string are : ";
	for (int i = 0; i < S1.size(); i++)
	{
		if (IsVowel(S1[i]))
			cout << S1[i] << " ";
	}
	cout << endl;
}


int main()
{	
	string S1 = ReadString();

	PrintVowels(S1);

	return 0;

}

