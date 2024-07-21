#include <iostream>
using namespace std; 

int main (){
	int grade;
	cin>>grade;
	
	if (grade>=90&&grade<101)
	cout<<"A"<<endl;
	
	else if (grade>=80)
	cout<<"B"<<endl;
		
	else if (grade>=70)
	cout<<"C"<<endl;
		
	else if (grade>=60)
	cout<<"D"<<endl;
		
	else if (grade>=50)
	cout<<"E"<<endl;
	
	else 
	cout<<"F"<<endl;
}