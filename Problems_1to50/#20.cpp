#include <iostream>
using namespace std; 
float readArea(){
	const float PI=3.14;
	float a,area;
	cout<<"Enter A "<<endl;
	cin>>a;
	 area =(PI*a*a)/4;
	return area;
	}
void printArea(float area){
	cout<<"Area = "<<area<<endl;
}


int main (){

	printArea(readArea());
	
	
}