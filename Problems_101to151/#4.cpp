#include <iostream>
#include <iomanip>
using namespace std;


void FillRandomNumberInRange(int& Number,int From,int To)
{
	Number = (rand() % (To - From + 1)) + From; 
}
     
void FillArrWithRandomNumbers(int arr2d[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			FillRandomNumberInRange(arr2d[i][j], 1, 100);
		}

	}
}

int SumCols(int arr2d[3][3], short Rows, short ColNumber) {

	int SumCols =0;
	for (int i = 0; i < Rows ; i++ )
	{
		SumCols += arr2d[i][ColNumber];
	}
	return SumCols;
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

void SumEachColsInArr(int arr2d[3][3], int SumColsArr[100], short Rows, short Cols) {

	
	for (int i = 0; i < Cols; i++)
	{
		
		SumColsArr[i] = SumCols(arr2d,Rows,i);
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

void PrintSumEachCols(int SumColsArr[100], short Cols) {
	cout << "The Following are the sum of each Col in the matrix:" << endl;
	for (int i = 0; i < Cols; i++)
	{
		cout << "Col " << i + 1 << " Sum = " << SumColsArr[i] << endl;
	}
}
int main()
{
	int From = 98, To = 100;
	int arr2d[3][3];
	short Rows = 3, Cols = 3;

	FillArrWithRandomNumbers(arr2d, Rows, Cols);
	PrintArrElements(arr2d, Rows, Cols);

	//int SumRowsArr[3];
	//SumEachRowInArr(arr2d, SumRowsArr, Rows, Cols);
	//PrintSumEachRow(SumRowsArr, Rows);

	int SumColsArr[3];
	SumEachColsInArr(arr2d, SumColsArr, Rows, Cols);
	PrintSumEachCols(SumColsArr, Cols);

	return 0;
}