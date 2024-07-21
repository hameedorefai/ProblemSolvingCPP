#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int GetRandomNumbers(short From = 1, short To = 10) {
	return rand() % (To - From + 1) + From;
}

void FillArrWithRandomNumbers(int arr2d[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr2d[i][j] = GetRandomNumbers();
		}
	}
}

void TransposeMatrix(int arr2d[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
	//	int arr2dTemp[3][3];
		//arr2dTemp = arr2d;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr2d[j][i];
		}
	}


}

void MultiplyTwo2DArr(int arr2dMultiplied[3][3], int arr2d1[3][3], int arr2d2[3][3], short Rows, short Cols) {




	int Multiplied = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr2dMultiplied[i][j] = arr2d1[i][j] * arr2d2[i][j];
		}

	}


}

void MiddleRowsMatrix(int MidArr[3], int arr2d[3][3], float Rows) {
	int MidRow = floor(Rows / 2);
	for (int i = 0; i < 3; i++)
	{

		MidArr[i] = arr2d[MidRow][i];
	}

}

void MiddleColsMatrix(int MidArr[3], int arr2d[3][3], float Cols) {
	int MidCol = floor(Cols / 2);
	for (int i = 0; i < 3; i++)
	{

		MidArr[i] = arr2d[i][MidCol];
	}

}

int SumArrElements(int arr2d[3][3], short Rows, short Cols) {

	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += arr2d[i][j];
		}
	}
	return Sum;

}

bool AreArrEqual(int arr2d1[3][3], int arr2d2[3][3], short Rows, short Cols) {

	return (SumArrElements(arr2d1, Rows, Cols) == SumArrElements(arr2d2, Rows, Cols));
}

bool AreArrTypical(int arr2d1[3][3], int arr2d2[3][3], short Rows, short Cols) {

	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr2d1[i][j] != arr2d2[i][j])
				return 0;
		}
	}
	return 1;
}


bool IsArrIdentity(int arr2d[3][3],  short Rows, short Cols) {


	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j)
			{
				if (arr2d[i][j] != 1)
					return 0;
				else continue;
			}
			else if (arr2d[i][j] != 0)
				return 0;
		}
	}
	return 1;
}

void PrintArrElements(int arr2d[][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3);
			printf("%.*d  ", 2, arr2d[i][j]);
		}
		cout << endl;
	}
}

void PrintArrElements(int arr[3], short Rows)
{

	for (int j = 0; j < Rows; j++)
	{
		cout << setw(3);
		printf("%.*d  ", 2, arr[j]);
	}
	cout << endl;

}


int main()
{
	int arr2d1[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	short Rows = 3, Cols = 3;



	//FillArrWithRandomNumbers(arr2d1, Rows, Cols);
	cout << "Matrix1:" << endl;
	PrintArrElements(arr2d1, Rows, Cols);
	
	

	if (IsArrIdentity(arr2d1, Rows, Cols))
	{
		cout << "Yes: matrix are Identity.\n";
	}
	else
	{
		cout << "No: matrix are Not Identity.\n";
	}

	return 0;
}

