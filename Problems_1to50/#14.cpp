#include <iostream>
using namespace std;

void readTwoNum(int& n1, int& n2) {

	cout << "Enter two numbers" << endl;
	cin >> n1 >> n2;
	
}
void displayTwoNum(int n1, int n2) {
	cout << n1 << "\t" << n2 << endl;

}
int swapfun(int& number1, int& number2) {
	int temp;
	temp = number1;
	number1 = number2;
	number2 = temp;

}
int main() {
	int number1, number2;
	readTwoNum(number1, number2);
	displayTwoNum(number1, number2);
	swapfun(number1, number2);
	displayTwoNum(number1, number2);


}