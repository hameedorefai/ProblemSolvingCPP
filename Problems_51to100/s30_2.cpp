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
	if(arrLength==0)
	arrLength = ReadPositiveNumber("How Much Numbers You Want to Entrer?");
	for (int i = 0; i < arrLength; i++) {
		arr[i] = RandomNumberInRange(From, To);

	}


}
void Sum2Arrays(int arr1[100], int arr2[2], int arrSum[100],int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		arrSum[i] = arr1[i] + arr2[i];
	}
}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}


int main() {
	int arrLength=0, arr2Length;
	int From = 1, To = 100;
	int arr1[100];
	int arr2[100];
	int arrSum[100];

	ReadArrItemsInRange(arr1, arrLength, From, To);
	ReadArrItemsInRange(arr2, arrLength, From, To);
	cout << "Array 1 : ";
	PrintArray(arr1, arrLength);
	cout << "Array 2 : ";
	PrintArray(arr2, arrLength);
	cout << "Sum of two Arrays : ";
	Sum2Arrays(arr1, arr2, arrSum, arrLength);
	PrintArray(arrSum, arrLength);




	return 0;
}