#include <iostream>
using namespace std;

float readArea(){
		float a,b;
	cout<<"Input A and B"<<endl;
	cin>>a>>b;
	float area=a*b;
	return area;
}
void printArea(float area){
	cout<<"Area = "<<area<<endl;
}
int main(){
;
	printArea(readArea());
	
	
}