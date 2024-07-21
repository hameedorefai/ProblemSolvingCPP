
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void FillArray(int arr[100], int& arrLength) {
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
	arrLength = 10;
}
int RandomNumberInRange(int From, int To) {
	int RandomNumber = (rand() % (To - From + 1)) + From;
	return RandomNumber;
}
int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
		return Number;
	} while (Number <= 0);
}
void AddArrayElement(int Number, int arr[100], int& arrLength) {
	arr[arrLength] = Number;
	arrLength++;
}
short FindNumberPositionInArray(int arr[100], int arrLength, int CheckItem) {
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] == CheckItem)
			return i;
	}
	return -1;

}
bool IsExist(int arr[100], int arrLength, int CheckItem) {
	return (FindNumberPositionInArray(arr, arrLength, CheckItem) != -1);

}
void CopyDistinctNumbers(int arr[100], int arrLength, int arrCopied[100], int& arrCopiedLength) {
	
	for (int i = 0; i < arrLength; i++)
	{
		if (!IsExist(arrCopied, arrCopiedLength, arr[i]))
		AddArrayElement(arr[i], arrCopied, arrCopiedLength);
	}
}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}

int main() {
	int arrLength,arrCopiedLength = 0;
	int From = 1, To = 10;
	int arr[100];
	int arrCopied[100];
	FillArray(arr, arrLength);

	CopyDistinctNumbers(arr, arrLength, arrCopied, arrCopiedLength);

	cout << "The Real Array is   : ";
	PrintArray(arr, arrLength);

	cout << "The Prime Array is  : ";
	PrintArray(arrCopied, arrCopiedLength);




	return 0;
}