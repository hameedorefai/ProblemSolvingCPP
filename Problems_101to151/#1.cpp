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



int main()
{
	int From = 98, To = 100;
	int arr2d[3][3];
	short Rows = 3, Cols = 3;

	FillArrWithRandomNumbers(arr2d, Rows, Cols);
	PrintArrElements(arr2d, Rows, Cols);

	return 0;
}