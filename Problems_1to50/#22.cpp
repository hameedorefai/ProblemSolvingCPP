#include <iostream>
using namespace std; 
float readArea(){
	const float PI=3.14;
	float a,b;
	cout<<"Enter A and B"<<endl;
	cin>>a>>b;
	float area =(  (PI*((b*b)/4)  )*(  ((2*a)-b) / ((2*a)+b)  ));
	return area;
	}
void printArea(float area){
	cout<<"Area = "<<area<<endl;
 	

}
void test(){
	const float PI=3.14;
	float a=10,b=10;
//	cout<<"Enter A and B"<<endl;
//	cin>>a>>b;
	float area =(     (PI*((b*b)/4)  )      *    (  ((2*a)-b) / ((2*a)+b)  ));
	float B=PI*((b*b)/4);
	float V=((2*a)-b);
	float C=((2*a)+b);
	float L=B*(V/C);
	cout<<L<<endl;
	cout<<area<<endl;
	
	
}

int main (){

	printArea(readArea());
//	test();
	
}