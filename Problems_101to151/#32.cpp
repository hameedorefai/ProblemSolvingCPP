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

int main()
{
	char Letter = ReadChar();

	if (IsVowel(Letter))
		cout << "Yes: Letter \'" << Letter << "\' is Vowel " << endl;
	else
		cout << "No: Letter \'" << Letter << "\' is Not Vowel " << endl;

	return 0;

}

