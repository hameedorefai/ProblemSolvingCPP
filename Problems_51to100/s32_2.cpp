#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
		return Number;
	} while (Number <= 0);
}
void ReadOrderArrayInRange(int arr[100], int& arrLength, int From, int To) {
	
	 arrLength = ReadPositiveNumber("Enter Array Length : ");
	for (int i = 0; i < To; i++) {
		arr[i] = From + i;
	}
}
void Swap(int& Num1, int& Num2) {
	int Temp;
	Temp = Num1;
	Num1 = Num2;
	Num2 = Temp;

}
int RandomNumberInRange(int From, int To) {
	int RandomNumber = (rand() % (To - From + 1)) + From;
	return RandomNumber;
}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}
void Shuffle(int arr[100], int arrLength, int From, int To)
{
	for (int i = 0; i < arrLength; i++)
		Swap(arr[RandomNumberInRange(From, To) - 1], arr[RandomNumberInRange(From, To) - 1]);

}

int main() {
	int arrLength = 0;
	int From = 1, To = 10;
	int arr[100];

	ReadOrderArrayInRange(arr, arrLength, From, To);
	cout << "Array Before Shuffle : ";
	PrintArray(arr, arrLength);

	Shuffle(arr, arrLength, From, To);
	cout << "Array After Shuffle  : ";
	PrintArray(arr, arrLength);

	return 0;
}