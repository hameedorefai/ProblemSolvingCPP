#include <iostream>
using namespace std;

struct stInfo{
		bool drivenlicense;
		unsigned int age;
};

stInfo readInfo(stInfo&readInfo){
	cout<<"Do you have a drivenlicense? yes=1 no=0"<<endl;
	cin>>readInfo.drivenlicense;
	cout<<"How old are you?"<<endl;
	cin>>readInfo.age;
	return readInfo;
	
}
bool isAccepted(stInfo readInfo){
	if(readInfo.drivenlicense==1&&readInfo.age>21)
	 	return 1;
	else 
		return 0;
		
	}
void printResult(bool isAccepted){
		if(isAccepted==1)
			cout<<"Hired"<<endl;
		else 
			cout<<"Rejected"<<endl;

	}
int main(){
		stInfo person;
		printResult(isAccepted(readInfo(person)));
	
	
	return 0;
}