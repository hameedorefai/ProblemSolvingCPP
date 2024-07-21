#include <iostream>
#include <iomanip>
using namespace std;


void FillRandomNumberInRange(int& Number,int From,int To)
{
	Number = (rand() % (To - From + 1)) + From; 
}
     
void FillArrWithRandomNumbers(int arr2d[][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			FillRandomNumberInRange(arr2d[i][j], 1, 100);
		}

	}
}

void PrintArrElements(int arr2d[][3], short Rows, short Cols)
{
	cout << "The Folliwung is a " << Rows << "x" << Cols << "Random matrix:" << endl;
		for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr2d[i][j] << "  ";
		}
		cout << endl;
	}
}

void SumEachRowInArr(int arr2d[3][3], int SumRowsArr[100], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		int Sum = 0;
		for (int j = 0; j < Cols; j++)
		{
			 Sum += arr2d[i][j];
		}
		SumRowsArr[i] = Sum;
	}
}

void PrintSumEachRow(int SumRowsArr[100], int Rows)
{
	cout << "The Following are the sum of each row in the matrix:" << endl;
	for (int i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << SumRowsArr[i] << endl;
	}
}

int main()
{
	int From = 98, To = 100;
	int arr2d[3][3];
	short Rows = 3, Cols = 3;

	FillArrWithRandomNumbers(arr2d, Rows, Cols);
	PrintArrElements(arr2d, Rows, Cols);

	int SumRowsArr[3];
	SumEachRowInArr(arr2d, SumRowsArr, Rows, Cols);
	PrintSumEachRow(SumRowsArr, Rows);
	return 0;
}