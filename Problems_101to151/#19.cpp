#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;


int ReadNumber(string Message = "") {
	int Number;
	cout << Message;
	cin >> Number;
	return Number;
}

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


bool IsExistInMatrix(int Number, int arr2d[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Number == arr2d[i][j])
				return 1;
		}
	}
	return 0;
}

void IntersectedNumbersInArr(int arrInterstNums[9],short& NewRows, int arr2d1[3][3], int arr2d2[3][3], short Rows, short Cols) {
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (IsExistInMatrix(arr2d1[i][j], arr2d2, Rows, Cols))
			{
				arrInterstNums[NewRows] = arr2d1[i][j];
				NewRows++;
			}
		}
	}

}

int GetMaxNumberInArr(int arr[3][3], short Rows, short Cols) {

	int Max = arr[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] > Max)
				Max = arr[i][j];
		}
	}
	return Max;
}

int GetMinNumberInArr(int arr[3][3], short Rows, short Cols) {

	int Min = arr[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] < Min)
				Min = arr[i][j];
		}
	}
	return Min;
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

void PrintArrElements(int arr[9], short Rows = 0)
{

	for (short i = 0; i < Rows; i++)
	{
		cout << setw(3);
		printf("%.*d  ", 2, arr[i]);
		
	}
	cout << endl;

}


int main()
{
	short Rows = 3, Cols = 3;
	int arr2d1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };

	cout << "Matrix1:" << endl;
	PrintArrElements(arr2d1, Rows, Cols);

	cout << "Minimum Number is : " << GetMinNumberInArr(arr2d1, Rows, Cols) << endl;
	cout << "Max Number is     : " << GetMaxNumberInArr(arr2d1, Rows, Cols) << endl;

	return 0;
}

