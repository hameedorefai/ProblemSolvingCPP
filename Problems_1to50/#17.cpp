#include <iostream>
using namespace std; 
float ReadArea(){
	float a,h;
	cout<<"Input A and H"<<endl;
	cin>>a>>h;
	float area=0.5*a*h;
	return area;
}
void printArea(float area){
	cout<<"Area = "<<area<<endl;
	
}
int main (){
	printArea(ReadArea());
	
	
}