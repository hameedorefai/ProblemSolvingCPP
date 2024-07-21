#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enCharTybe { SmallLetters = 1, CapitalLetters, SpecialCharacter, Digit };
int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
		return Number;
	} while (Number <= 0);
}
int RandomNumberInRange(int From, int To) {
	int RandomNumber = (rand() % (To - From + 1)) + From;
	return RandomNumber;
}
char GetRandomChar(enCharTybe CharTybe) {

	if (CharTybe == enCharTybe::SmallLetters)
		return char(RandomNumberInRange(97, 122));
	else if (CharTybe == enCharTybe::CapitalLetters)
		return char(RandomNumberInRange(65, 90));
	else if (CharTybe == enCharTybe::SpecialCharacter)
		return char(RandomNumberInRange(32, 47));
	else if (CharTybe == enCharTybe::Digit)
		return char(RandomNumberInRange(48, 57));
}
string GetGenerateWord(enCharTybe CharacterTybe, int length) {
	string GenerateWord = "";
	for (int i = 0; i < length; i++) {
		GenerateWord = GenerateWord + GetRandomChar(CharacterTybe);
	}
	return  GenerateWord;
}
string GetGenrateKey(enCharTybe CharacterTybe) {

	string GenerateKey = "";
	string GenerateWord;
	int Counter = 0;

	for (int i = 0; i < 4; i++) {
		GenerateWord = GetGenerateWord(CharacterTybe, 4);
		if (Counter < 3)
			GenerateKey = GenerateKey + GenerateWord + "-";
		else
			GenerateKey = GenerateKey + GenerateWord;
		Counter++;
	}

	return  GenerateKey;
}
void PrintGenerateKeys(string arr[100],int&arrKeysLength, enCharTybe CharacterTybe)
{
	for(int i=0;i< arrKeysLength;i++){

	}
	
}

void FillArrayOfKeys(string arrKeys[100],int & arrKeysLength,enCharTybe CharacterTybe) {
	arrKeysLength = ReadPositiveNumber("Enter number of keys : ");
	for (int i = 0; i < arrKeysLength; i++)
		arrKeys[i] = GetGenrateKey(CharacterTybe);
}
void PrintArrayKeys(string arrKeys[100], int arrKeysLength) {
	cout << "Array elements : " << endl << endl;
	for (int i = 0; i < arrKeysLength; i++)
	{
		cout << "Array[" << i << "] : " << arrKeys[i] << endl;
	}
	cout << endl << endl;
}

int main() {
	srand((unsigned)time(NULL));

	enCharTybe CharacterTybe = enCharTybe::CapitalLetters;
	string arrKeys[100];
	int arrKeysLength;
	FillArrayOfKeys(arrKeys, arrKeysLength, CharacterTybe);
	PrintArrayKeys(arrKeys, arrKeysLength);

	return 0;
}