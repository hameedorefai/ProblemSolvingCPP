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
char GetUpperLetter(char Letter)
{
	return (int(Letter) > 96 && int(Letter) < 123 ? char(int(Letter - 32)) : Letter );
}
string UpperFirstLetterOfEachWord(string Word) {
	
	bool IsFirstLetter = true;

	for (int i = 0; i < Word.length(); i++)
	{
		if (Word[i] != ' ' && IsFirstLetter)
			Word[i] = toupper(Word[i]);
		
		IsFirstLetter = (Word[i] == ' ');
	}
	return Word;

}


int main()
{

	string UpperedWords = UpperFirstLetterOfEachWord(ReadString());
	
	cout << UpperedWords << endl;

	return 0;

}

