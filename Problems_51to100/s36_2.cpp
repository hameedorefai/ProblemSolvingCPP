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
void AddArrayElement(int arr[100],int&arrLength) {
	arr[arrLength] = ReadPositiveNumber("Enter array item : ");
	arrLength += 1;
}
void ReadArrayItems(int arr[100], int& arrLength,int To) {
	bool Continue = false;
	do {
		AddArrayElement(arr, arrLength);
		if (arrLength == To)
			break;
		cout << "Do you want to continue? [1]:yes | [0]:no : ";
		cin >> Continue;
	} while (Continue);
}
void PrintArray(int arr[100], int arrLength) {
	cout << "Array Length   : " << arrLength << endl;
	cout << "Array elements : ";
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}

int main() {
	int arrLength = 0, To = 10;
	int arr[100];
	ReadArrayItems(arr, arrLength,To);
	PrintArray(arr, arrLength);


	return 0;
}