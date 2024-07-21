#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ReadLetters(string Message) {
	string Input;
	cout << Message << endl;
	cin >> Input;
	return Input;
}
bool GuessPasswordBy3Letters(string Password) {
	int Counter = 0;
	string PassPossibility = "";
	for (int i = 65; i <=90; i++) {
		for (int j = 65; j <= 90; j++) {
			for (int v = 65; v <= 90; v++) {
				Counter++;
				PassPossibility = char(i);
				PassPossibility += char(j);
			    PassPossibility += char(v);
				cout << "Trial [" << Counter << "] : "<< PassPossibility;
				if (PassPossibility == Password) {
					cout << "\nPassword is : " << PassPossibility << endl;
					cout << "Found after " << Counter << " Trial(s)." << endl;
					return true;
				}
				cout << endl;

			}
			
		}
		
	}
	return false;
}

int main() {
	GuessPasswordBy3Letters(ReadLetters("Enter 3 Capital Letters"));
	return 0;
}