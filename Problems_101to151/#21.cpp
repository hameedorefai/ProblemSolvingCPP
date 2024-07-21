#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;



void PrintFibonacciSeries(short ListLength) {
	short PreNumber = 1;
	short NextNumber = 1;
	short Temp = 0;

	cout << PreNumber << " ";
	
	for (int i = 0; i < ListLength-1; i++)
	{
		cout << NextNumber << " ";

		Temp = NextNumber;
		NextNumber += PreNumber;
		PreNumber = Temp;
	}
}

int main()
{

	PrintFibonacciSeries(10);

	return 0;

}

