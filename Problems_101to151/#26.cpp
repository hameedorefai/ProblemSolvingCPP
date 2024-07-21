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

string LowerAllString(string Word) {
	
	for (int i = 0; i < Word.length(); i++)
	{
			Word[i] = tolower(Word[i]);
	}
	return Word;

}

string UpperAllString(string Word) {

	for (int i = 0; i < Word.length(); i++)
	{
		Word[i] = toupper(Word[i]);
	}
	return Word;

}


int main()
{

	string String = ReadString();

	cout << LowerAllString(String) << endl;

	cout << UpperAllString(String) << endl;


	return 0;

}

