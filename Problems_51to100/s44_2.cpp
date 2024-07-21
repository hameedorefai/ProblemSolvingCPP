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
int PositiveNumbersCount(int arr[100], int arrLength) {
	int PositiveNumbersCount = 0;
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] >0)
			PositiveNumbersCount++;
	}
	return PositiveNumbersCount;
}
void PrintPositiveNumbersCount(int OddNumbersCount) {
	cout << "Positive Numbers Count is : " << OddNumbersCount << endl;
}
void PrintArray(int arr[100], int arrLength) {
	cout << "Array Items is : " << endl;
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int arr[100], arrLength = 0, From = -10, To = 100;
	FillArrayWithRandomNumbersInRange(arr, arrLength, From, To);
	PrintArray(arr, arrLength);
	PrintPositiveNumbersCount(PositiveNumbersCount(arr, arrLength));

	return 0;
}