#include <iostream>
using namespace std;


unsigned int  readAge(){
	unsigned int age;
	cout<<"Enter your age : ";
	cin>>age;
	return age;
}
void Checkfrom18to45(int number){
	if(number>18&&number<45)
		cout<<"Valid"<<endl;
	else
		cout<<"Invalid"<<endl;
}


int main(){

	Checkfrom18to45(readAge());
	
	
	return 0;
}

