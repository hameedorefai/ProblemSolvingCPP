#include <iostream>
#include <iomanip>
using namespace std;


     
void FillArrWithOrderedmNumbers(int arr2d[3][3], short Rows, short Cols)
{
	 short Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Counter++;
			arr2d[i][j] = Counter;
		}
	}
}


void PrintArrElements(int arr2d[][3], short Rows, short Cols)
{
	cout << "The Folliwung is a " << Rows << "x" << Cols << " ordered matrix:" << endl;
		for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr2d[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	int From = 98, To = 100;
	int arr2d[3][3];
	short Rows = 3, Cols = 3;

	FillArrWithOrderedmNumbers(arr2d, Rows, Cols);
	PrintArrElements(arr2d, Rows, Cols);


	return 0;
}