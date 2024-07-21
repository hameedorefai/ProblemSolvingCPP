#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number;
	do{
	cout << Message << endl;
	cin >> Number;
	return Number;
	} while (Number <= 0);
}
int ReadNumber(string Message) {
	int Number;
		cout << Message;
		cin >> Number;
		return Number;
}
void ReadArrItems(int arr[100],int&arrLength) {
	arrLength = ReadPositiveNumber("How Much Numbers You Want to Entrer?");
	string PrintTimes;
	for (int i = 0; i < arrLength; i++) {
		PrintTimes = to_string(i+1);
		arr[i] = ReadNumber("Element ["+ PrintTimes +"] : ");

	}

	
}
bool IsExistInArray(int Number, int searchfor) {
	return(Number == searchfor);
}
int	 TimesRepeatedInArray(int arr[100], int arrLength, int searchfor) {
	int ItemRepeatsCounter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (IsExistInArray(arr[i], searchfor))
			ItemRepeatsCounter++;
	}
	cout << searchfor << " is repeated " << ItemRepeatsCounter << " time(s)." << endl;
	return ItemRepeatsCounter;
}
void PrintArray(int arr[100], int arrLength) {
	cout << "Original array : ";
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

}

int main() {
	int arrLength;
	int arr[100];
	ReadArrItems(arr,arrLength);
	int searchfor = ReadNumber("Enter the number you want to search for ? ");
	PrintArray(arr, arrLength);
	TimesRepeatedInArray(arr, arrLength, searchfor);

	

	return 0;
} 