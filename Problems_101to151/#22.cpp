#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;



void PrintFibonacciSeries(short PreNumber, short NextNumber, short Length) {

	if (Length > 0) {

		cout << NextNumber << " ";
		short Temp = NextNumber;
		NextNumber += PreNumber;
		PreNumber = Temp;

		PrintFibonacciSeries(PreNumber, NextNumber, Length - 1);

	}
}
int main()
{
	short PreNumber = 0;
	short NextNumber = 1;

	PrintFibonacciSeries(PreNumber, NextNumber, 10 );

	return 0;

}

