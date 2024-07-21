#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void AutoFillArray(int arr[100], int& arrLength) {
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	arr[5] = 4;
	arr[6] = 3;
	arr[7] = 2;
	arr[8] = 1;
	arr[9] = 0;
	arrLength = 10;
}
bool IsArrayPalindrome(int arr[100],int arrLength) {
	int HalfArrLength = ceil(arrLength / 2);
	for (int i = 0, j = arrLength - 1; i <= HalfArrLength, j >= 0; i++, j--) {
		cout << arr[i] << " " << arr[j] << endl;
		if (j ==HalfArrLength) {
			break;
		}
	}
	return 1;
}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) 
		cout << arr[i] << "  ";
	
	cout << endl;

}

int main() {
	int arrLength = 10;
	int arr[100];
	AutoFillArray(arr, arrLength);

	PrintArray(arr,arrLength);
	if (IsArrayPalindrome(arr, arrLength))
		cout << "Array is a Palindrome" << endl;
	else
		cout << "Array is not a Palindrome" << endl;

	




	return 0;
}