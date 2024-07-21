#include <iostream>
#include <cmath>
using namespace std;

float readArea() {
	float a, b, c, p;
	cout<<"Enter A,B and C"<<endl;
	cin >> a >> b >> c;
	const float PI = 3.14;
	 p = (a + b + c) / 2;
	float area = ((a * b * c) / (4 * (sqrt(p * (p - a) * (p - b) * (p - c)))));
	return area;
}
void printArea(float area){
	cout <<"Area = "<<area<< endl;
}
int main() {
	printArea(readArea());
		
}