#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

string ReadString(string Message) {
	
	string Words;
	cout << Message;
	getline(cin, Words);
	return Words;
}

void PrintFirstLetterInEachWord(string Word) {
	
	bool IsFirstLetter = true;

	for (char Letter : Word)
	{
		if (Letter != ' ' && IsFirstLetter)
			cout << Letter << endl;
		
		IsFirstLetter = (Letter == ' ');
	}

}


int main()
{
	string FullName = ReadString("Enter Your Full Name :\n");
	
	PrintFirstLetterInEachWord(FullName);

	return 0;

}

