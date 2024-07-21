#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
	int PositiveNumber = 0;
	do {
		cout << Message << endl;
		cin >> PositiveNumber;
	} while (PositiveNumber < 1);
	return PositiveNumber;
}
int RandomNumberInRange(int From,int To) {
	return (int)(rand() % To) + From;
}
void FillArrayWithRandomNumbersInRange(int arr[100],int&arrLength,int From,int To) {
	if (arrLength == 0)
		arrLength=ReadPositiveNumber("Enter Array Length : ");
	for (int i = 0; i < arrLength; i++) {
		arr[i] = RandomNumberInRange(From, To);

	}
}
int OddNumbersCount(int arr[100], int arrLength) {
	int OddNumbersCount = 0;
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] % 2 != 0)
			OddNumbersCount++;
	}
	return OddNumbersCount;
}
void PrintOddNumbersCount(int OddNumbersCount) {
	cout << "Odd Numbers Count is : " << OddNumbersCount << endl;
}
void PrintArray(int arr[100], int arrLength) {
	cout << "Array Items is : " << endl;
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int arr[100], arrLength = 0, From = 1, To = 100;
	FillArrayWithRandomNumbersInRange(arr, arrLength, From, To);
	PrintArray(arr, arrLength);
	PrintOddNumbersCount(OddNumbersCount(arr, arrLength));

	return 0;
}