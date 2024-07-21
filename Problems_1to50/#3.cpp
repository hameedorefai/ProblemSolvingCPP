#include <iostream>
using namespace std;

bool isOdd(int number){
	if(number%2!=0)
		return true;
	else 
		return false;
}
bool isEven(int number){
	if(number%2==0)
		return true;
	else 
		return false;
}
int readNumber(){
	int number;
	cout<<"Enter a number : "<<endl;
	cin>>number;
	return number;
}
void checkIfOddOrEven(int number){
	if(isOdd( number))
		cout<<"It's Odd"<<endl;
	else if(isEven( number))
		cout<<"It's Even"<<endl;
		
}
int main(){
	checkIfOddOrEven(readNumber());
	
	return 0;
}