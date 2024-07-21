#include <iostream>
#include <iomanip>
using namespace std;




void FillArrWithRandomNumbers(int arr2d[3][3], short Rows, short Cols)
{
	 short Counter = 1;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr2d[i][j] = Counter;
			Counter++;
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

void MultiplyTwo2DArr(int arr2dMultiplied[3][3], int arr2d1[3][3], int arr2d2[3][3], short Rows, short Cols) {

	FillArrWithRandomNumbers(arr2d1, Rows, Cols);
	cout << "Matrix1:" << endl;
	PrintArrElements(arr2d1, Rows, Cols);

	FillArrWithRandomNumbers(arr2d2, Rows, Cols);
	cout << "Matrix2:" << endl;
	PrintArrElements(arr2d2, Rows, Cols);



	int Multiplied = 0;
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr2dMultiplied[i][j] = arr2d1[i][j] * arr2d2[i][j];
		}

	}
	cout << "Results:" << endl;
	PrintArrElements(arr2dMultiplied, Rows, Cols);

}


int main()
{
	int arr2d1[3][3];
	int arr2d2[3][3];
	int arr2dMultiplied[3][3];
	short Rows = 3, Cols = 3;

	MultiplyTwo2DArr(arr2dMultiplied, arr2d1, arr2d2, Rows, Cols);

	return 0;
}