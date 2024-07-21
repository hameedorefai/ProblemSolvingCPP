#include <iostream>
using namespace std; 
float readArea(){
	const float PI=3.14;
	float l;
	cout<<"Enter L"<<endl;
	cin>>l;
	float area =(l*l)/(4*PI);
	return area;
	}
void printArea(float area){
		cout<<"Area = "<<area<<endl;

}



int main (){
	printArea(readArea());
	
	
}