#include <iostream>
#include <string>
using namespace std;

string readName(){
	string name;
	cout<<"Enter Your Name : ";
	getline(cin,name);
	return name;
}
void displayName(string n){
	string name=n;
	cout<<"Your name is "<<name<<endl;
}

int main (){
	displayName(readName());
}