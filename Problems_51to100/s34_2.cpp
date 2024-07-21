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
int RandomNumberInRange(int From, int To) {
	int RandomNumber = (rand() % (To - From + 1)) + From;
	return RandomNumber;
}
void ReadArrLength(int&arrLength) {
	arrLength = ReadPositiveNumber("Enter array length : ");
}
void FillArrayWithRandomNumbers(int arr[100], int arrLength,int From,int To) {
	for (int i = 0; i < arrLength; i++) {
		arr[i] = RandomNumberInRange(From, To);
	}
}
void PrintArray(int arr[100], int arrLength) {
	cout << "Array elements : ";
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}
short FindNumberPositionInArray(int arr[100], int arrLength, int CheckItem) {
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] == CheckItem)
			return i;
	}
	return -1;

}
//bool SearchFor(int arr[100], int arrLength, int& CheckItem, int& NumPosition, int& NumOrder) {
//	if (CheckItem == -1)
//		CheckItem = ReadPositiveNumber("Enter a number to search for : ");
//	int Counter = 0;
//	for (int i = 0; i < arrLength; i++) {
//		Counter++;
//		if (CheckItem == arr[i]) {
//			NumPosition = i;
//			NumOrder = Counter;
//			return 1;
//
//		}
//	}
//	return 0;
//}
void PrintInfoNumberChecked(int arr[100], int arrLength, int CheckItem) {
	if (CheckItem == -1)
		CheckItem = ReadPositiveNumber("Enter a number to search for : ");	
	short NumPosition = FindNumberPositionInArray(arr,arrLength,CheckItem);
	short NumOrder = NumPosition + 1;
	if (NumPosition != -1) {
		cout << "Number you are looking for is_: " << CheckItem << endl;
		cout << "The Number found at Position__: " << NumPosition << endl;
		cout << "The number found its order____: " << NumOrder << endl;
	}
	else {
		cout << "Number you are looking for is_: " << CheckItem << endl;
		cout << "The number is not found! ." << endl;
	}

}

int main() {
	int arrLength = 0;
	int From = 1, To = 100;
	int arr[100];
	int CheckItem = -1;
	ReadArrLength(arrLength);
	FillArrayWithRandomNumbers(arr, arrLength, From, To);
	PrintArray(arr, arrLength);

	PrintInfoNumberChecked(arr, arrLength, CheckItem);


	return 0;
}