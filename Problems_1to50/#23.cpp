#include <iostream>
#include <cmath>
using namespace std;

float readArea() {
	const float PI=3.14;
	float a,b,c;
	cout<<"Enter A ,B and C"<<endl;
	cin>>a>>b>>c;
	float p=(a+b+c)/2;
	return (PI*((a*b*c)    /     (4*(sqrt(p*(p-a)*(p-b)*(p-c) )) )   ));
}
void printArea(float area){
	cout<<"Area = "<<area<<endl;
}
int main() {

	printArea(readArea());
}