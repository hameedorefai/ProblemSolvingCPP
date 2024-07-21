#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string Message) {
	float PositiveNumber = 0;
		cout << Message << endl;
		cin >> PositiveNumber;
	return PositiveNumber;
}
float MyABS(float Number) {
	if (Number < 0)
		Number = -1 * Number;
	return Number;
}
float MyRand(float Number) {

	bool TRUE=false;
	if (TRUE) {
		float Rand = 0.0;
		int intNumber = Number;

		if (Number > 0)
			Rand = Number - intNumber;
		else
			Rand = MyABS(Number) + intNumber;
		return Rand;
	}


	if (Number > 0) {
		while (Number > 1) {
			if (Number >= 100000)
				Number -= 1000;
			else if (Number >= 10000)
				Number -= 10000;
			else if (Number >= 1000)
				Number -= 1000;
			else if (Number >= 100)
				Number -= 100;
			else if (Number >= 10)
				Number =Number- 10;
			else
				Number =Number- 1;
		}
	}
	else if (Number < 0) {
		if (Number <= 0) {
			while (Number < -1) {
				if (Number <= -100000)
					Number += 100000;
				else if (Number <= -10000)
					Number += 10000;
				else if (Number <= -1000)
					Number += 1000;
				else if (Number <= -100)
					Number += 100;
				else if (Number <= -10)
					Number += 10;
				else
					Number += 1;
			}
		}
	}
	return Number;
}
int MyRound(float Number) {
	 
	float Rand = MyRand(Number);
	float elseRand = 1 - Rand;
	if (Number >= 0) {
		if (Rand >= 0.5)
			Number += elseRand;
		else
			Number -= Rand;
	}
	else {
		if (Rand >= 0.5)
			Number -= elseRand;
		else
			Number += Rand;

	}
	
	
	return Number;
}
int main() {
	float Number;
	Number = ReadNumber("Enter a Number : ");
	
	cout << "My  Round  : " << MyRound(Number) << endl;
	cout << "C++ Round  : " << round(Number) << endl;
	
	return 0;
}