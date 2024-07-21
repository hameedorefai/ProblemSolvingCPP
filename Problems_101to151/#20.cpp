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


void RevrseMatrix(int arr[100], short Rows, int RevrsedArr[100]) {
		
	int Counter = 0;
	for (int i = Rows; i > 0; i--)
	{
		RevrsedArr[Counter] = arr[i];
			Counter++;
	}
}

bool IsEqualNumbers(int Number1, int Number2) {
	return (Number1 == Number2);
}

bool IsPalindromeMatrix(int arr[3][3], int Rows, int Cols) {

	int RevrsedArr[100];
	int TCols = Cols;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < ceil(Cols/2.0); j++)
		{
			TCols -= 1;
			if(!IsEqualNumbers(arr[i][j],arr[i][TCols]))
				return 0;
			
		}
		TCols = Cols;
	}
	return 1;
}

void PrintArrElements(int arr2d[3][3], short Rows, short Cols)
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
	int arr2d1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

	cout << "Matrix1:" << endl;
	PrintArrElements(arr2d1, Rows, Cols);

	if (IsPalindromeMatrix(arr2d1, Rows, Cols))
		cout << "Yes: Matrix is Palindrome\n";
	else
		cout << "No: Matrix is Not Palindrome\n";

	return 0;

}

