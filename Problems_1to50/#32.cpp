#include <iostream>
#include <cmath>
using namespace std;

void readNum_and_M(float& number, float& m) {
	cout << "Enter the number and its M" << endl;
	cin >> number >> m;
}
float getPowerOf(float number, float m) {
	float result = 1;
	while ( m--) {
		result *= number;
	}
	return result;
}
void printPowerOf_result(float result) {
	cout << result << endl;
}
int main() {
	float number, m;
	readNum_and_M(number, m);
	printPowerOf_result(getPowerOf(number, m));
}