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
bool IsPrime(int number) {
	int HalfNumber = ceil(number / 2);
	for (int i = 2; i < HalfNumber; i++) {
		if (number % i == 0)
			return 0;
	}
	return 1;
}

void CoppyPrimeArray(int arr[100],int arrPrime[100], int arrLength,int&arr2Length) {
	int PrimeCounter = 0;
	for (int i = 0; i < arrLength; i++) {
		if(IsPrime(arr[i])){
			arrPrime[PrimeCounter] = arr[i];
			PrimeCounter++;
		}
	}
	arr2Length = PrimeCounter;
}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}

int main() {
	int arrLength, arr2Length;
	int From = 1, To = 100;
	int arr[100];
	int arrCopied[100];
	int arrPrime[100];
	ReadArrItemsInRange(arr, arrLength, From, To);
	CoppyPrimeArray(arr,arrPrime, arrLength, arr2Length);
	cout << "Array 1   : ";
	PrintArray(arr, arrLength);
	cout << "Prime Num : ";
	PrintArray(arrPrime, arr2Length);




	return 0;
}