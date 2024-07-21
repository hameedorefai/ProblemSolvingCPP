#include <iostream>
using namespace std;

int main(){
	int num1,num2;
	char operation;
	cout<<"Enter two numbers : "<<endl;
	cin>>num1>>num2,operation;
	cout<<"Enter the operator\n(1) +\n(2) -\n(3) *\n(4) /\n";
	cin>>operation;
	
	switch(operation){
	
		case '+':
			cout<<"Result : "<<num1+num2<<endl;
			break;
		case '-':
			cout<<"Result : "<<num1-num2<<endl;
			break;
		case '*':
			cout<<"Result : "<<num1*num2<<endl;
			break;
		case '/':
			cout<<"Result : "<<num1/num2<<endl;
			break;
		default:
			cout<<"Wrong Input"<<endl;

	}
	return 0;
}