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
char ReadChar() {
		char C;
		cout << "Enter a character :\n";
		cin >> C;
		return C;

}
char InvertChar(char Letter)
{
	if (Letter >= 'A' && Letter <= 'Z')
		return Letter + 32;
	else if (Letter >= 'a' && Letter <= 'z')
		return Letter - 32;
	else
		return Letter;
}
char InvertLetterCase(char Letter) {
	return (isupper(Letter) ? tolower(Letter) : toupper(Letter));
}
string InvertAllStringLetterCase(string Word)
{
	for (int i = 0; i < Word.length(); i++) {
		Word[i] = InvertLetterCase(Word[i]);
	}
	return Word;
}



int main()
{
	
	cout << InvertAllStringLetterCase(ReadString()) << endl;


	return 0;

}

