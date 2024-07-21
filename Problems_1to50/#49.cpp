#include <iostream>
using namespace std;

struct intoBankAccount{
	int PIN=1234;
	long balance=7500;
	
};

int readPIN(){
	int PIN;
	cout<<"Enter PIN : ";
	cin>>PIN;
	return PIN;
}

void checkPIN(int PIN,intoBankAccount user){

	if(PIN==user.PIN)
		cout<<"Balance is : "<<user.balance<<endl;
	else 
		cout<<"Wrong PIN"<<endl;
}

int main (){
		intoBankAccount user1;
	checkPIN(readPIN(),user1);
	
	
	return 0;
}