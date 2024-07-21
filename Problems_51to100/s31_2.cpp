#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void ShuffleArray(int arr[100], int arrShuffle[100], int arrLength, int From, int To) {
	int RandNumber;
	arrShuffle[0] = -1;
	for (int i = 0; i < arrLength; i++) {
		 RandNumber= ((rand() % (To - From + 1)) + From);
		while (arr[i] == RandNumber && arrShuffle[i] == RandNumber
			&&arrShuffle[i-1]!=RandNumber) {
			RandNumber = ((rand() % (To - From + 1)) + From);
		}
		arrShuffle[i] = RandNumber;

	}
}
int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
		return Number;
	} while (Number <= 0);
}
void ReadOrderArrayInRange(int arr[100], int& arrLength, int From, int To) {
	for (int i = 0; i < To; i++){
		arr[i] = From+i;
		arrLength++;
	}
}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}


int main() {
	int arrLength = 0;
	int From = 1, To = 10;
	int arr[100],arrShuffle[100];
	ReadOrderArrayInRange(arr, arrLength, From, To);
	cout << "Array Before Shuffle : ";
	PrintArray(arr, arrLength);
	cout << "Array After Shuflle  :";
	ShuffleArray(arr, arrShuffle, arrLength, From, To);
	PrintArray(arrShuffle, arrLength);
	




	return 0;
}