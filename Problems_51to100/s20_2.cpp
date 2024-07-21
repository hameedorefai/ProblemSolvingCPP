#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enCharTybe{ SmallLetters=1, CapitalLetters, SpecialCharacter, Digit };
int RandomNumberInRange(int From, int To) {
	int RandomNumber = (rand() % (To - From + 1))+ From;
	return RandomNumber;
}
char PrintRandomChar(enCharTybe CharTybe) {

	if (CharTybe == enCharTybe::SmallLetters)
		return char(RandomNumberInRange(97, 122));
	else if (CharTybe == enCharTybe::CapitalLetters)
		return char(RandomNumberInRange(65, 90));
	else if (CharTybe == enCharTybe::SpecialCharacter)
		return char(RandomNumberInRange(32, 47));
	else if (CharTybe == enCharTybe::Digit)
		return char(RandomNumberInRange(48, 57));
}

int main() {
	srand((unsigned)time(NULL));

	cout << PrintRandomChar(enCharTybe::SmallLetters) << endl;
	cout << PrintRandomChar(enCharTybe::CapitalLetters) << endl;
	cout << PrintRandomChar(enCharTybe::SpecialCharacter) << endl;
	cout << PrintRandomChar(enCharTybe::Digit) << endl;

	return 0;
}