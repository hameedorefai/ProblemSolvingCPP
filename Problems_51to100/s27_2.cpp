#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

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
void ReadArrItemsInRange(int arr[100], int& arrLength, int From, int To) {
	arrLength = ReadPositiveNumber("How Much Numbers You Want to Entrer?");
	string PrintTimes;
	for (int i = 0; i < arrLength; i++) {
		arr[i] = RandomNumberInRange(From, To);

	}


}
int GetSumOfRandomArray(int arr[100], int arrLength) {
	int Sum = 0;
	int AVG;
	for (int i = 0; i < arrLength; i++) {
		Sum += arr[i];
	}
	return Sum;
}
float GetAverageOfRandomArray(int arr[100], int arrLength) {
	return((float)GetSumOfRandomArray(arr,arrLength) / arrLength);
}
void PrintArray(int arr[100], int arrLength) {
	cout << "Array elements : ";
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}

int main() {
	int arrLength;
	int From = 1, To = 100;
	int arr[100];
	ReadArrItemsInRange(arr, arrLength, From, To);
	PrintArray(arr, arrLength);
	int arrSum = GetSumOfRandomArray(arr, arrLength);
	cout << "Average of All Random array Numbers is : ";
	cout << GetAverageOfRandomArray(arr, arrLength) << endl;



	return 0;
}