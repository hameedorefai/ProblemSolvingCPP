
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
void AddArrayElement(int Number, int arr[100], int& arrLength) {
	arr[arrLength] = Number;
	arrLength++;
}
void ReadArrItemsInRange(int arr[100], int& arrLength, int From, int To) {
	arrLength = ReadPositiveNumber("How Much Numbers You Want to Entrer?");
	string PrintTimes;
	for (int i = 0; i < arrLength; i++) {
		arr[i] = RandomNumberInRange(From, To);

	}


}
bool IsPrime(int Number) {
	int HalfNumber = ceil(Number / 2);
	for (int i = 2; i <= HalfNumber; i++) {
		if (Number % i == 0)
			return 0;
	}
	return 1;
}

void CopyPrimeNumbers(int arr[100], int arrLength, int arrCopied[100], int& arrCopiedLength) {
	for (int i = 0; i < arrLength; i++)
		if(IsPrime(arr[i]))
		AddArrayElement(arr[i], arrCopied, arrCopiedLength);

}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}

int main() {
	int arrLength, arrCopiedLength = 0;
	int From = 1, To = 100;
	int arr[100];
	int arrCopied[100];
	ReadArrItemsInRange(arr, arrLength, From, To);
	CopyPrimeNumbers(arr, arrLength, arrCopied, arrCopiedLength);

	cout << "The Real Array is   : ";
	PrintArray(arr, arrLength);

	cout << "The Prime Array is  : ";
	PrintArray(arrCopied, arrCopiedLength);




	return 0;
}