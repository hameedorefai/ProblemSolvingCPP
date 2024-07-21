#include <iostream>
#include <iomanip>
using namespace std;


     
void FillArrWithOrderedmNumbers(int arr2d[3][3], short Rows, short Cols)
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
	cout << "The Folliwung is a " << Rows << "x" << Cols << " matrix:" << endl;
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
	int arr2d[3][3];
	short Rows = 3, Cols = 3;

	FillArrWithOrderedmNumbers(arr2d, Rows, Cols);
	PrintArrElements(arr2d, Rows, Cols);

	int arrTransposed[3][3];
	TransposeMatrix(arr2d, arrTransposed, Rows, Cols);
	PrintArrElements(arrTransposed, Rows, Cols);



	return 0;
}