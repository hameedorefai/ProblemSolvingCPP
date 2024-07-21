#include <iostream>
using namespace std;


struct stPersonInfo{
	string firstName;
	string lastName;
	unsigned int age;
	string phoneNumber;
};

void readPersonInfo(stPersonInfo &person){
	cout<<"Enter first name  "<<endl;
	cin>>person.firstName;
	cout<<"Enter last name  "<<endl;
	cin>>person.lastName;
	cout<<"Enter age "<<endl;
	cin>>person.age;
	cout<<"Enter phone number  "<<endl;
	cin>>person.phoneNumber;
}
void printPersonInfo(stPersonInfo person){
	cout<<"*************************************"<<endl;
	cout<<"Full name______ : "<<person.firstName<<" "<<person.lastName<<endl;
	cout<<"Age____________ : "<<person.age<<endl;
	cout<<"Phone Number___ : "<<person.phoneNumber<<endl;
	cout<<"*************************************"<<endl;		
}
void readInfo(stPersonInfo person[2],int &numberOfPersons){
	cout<<"How many Persons You want to read Info ? ";
	cin>>numberOfPersons;
		for(int i=0;i<numberOfPersons;i++)
		readPersonInfo(person[i]);
}
void printInfo(stPersonInfo person[2],int numberOfPersons){
	for(int i=0;i<numberOfPersons;i++)
	printPersonInfo(person[i]);
}
int main(){
	int numberOfPersons=0;
	
	stPersonInfo person[2];
	
	readInfo(person,numberOfPersons);
	printInfo(person,numberOfPersons);
	
	
	return 0;
}