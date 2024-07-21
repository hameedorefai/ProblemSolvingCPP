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
	for (int i = 0; i < arrLength; i++) {
		arr[i] = RandomNumberInRange(From, To);

	}


}
void ReversedArray(int arr[100], int arrReversed[100], int arrLength)
{

	for (int j = 0; j<arrLength; j++) {
		arrReversed[j] = arr[arrLength-1-j];
	}

}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}

int main() {
	int arrLength;
	int From = 1, To = 100;
	int arr[100];
	int arrReversed[100];
	ReadArrItemsInRange(arr, arrLength, From, To);
	cout << "The Real Array is     : ";
	PrintArray(arr, arrLength);
	ReversedArray(arr,arrReversed,arrLength);
	cout << "The Reversed Array is : ";
	PrintArray(arrReversed, arrLength);




	return 0;
}