#include <iostream>
using namespace std;

enum enDays{sunday=1,monday,tuesday,wednessday,thursday,friday,saturday};

int readDay(){
	int day;
	cout<<"Enter number of this day : "<<endl;
	cin>>day;
	return day;
}
int main(){
	
		 	 
    switch (readDay()){
    	
	case enDays::sunday:
		cout<<"It's SUNDAY"<<endl;
		break;
	case enDays::monday:
		cout<<"It's monday"<<endl;
		break;		
	case enDays::tuesday:
	 	cout<<"It's tuesday"<<endl;
		break;
	case enDays::wednessday:
	 	cout<<"It's wednessday"<<endl;
		break;
	case enDays::thursday:
	 	cout<<"It's thursday"<<endl;
		break;
	case enDays::friday:
	 	cout<<"It's friday"<<endl;
		break;
	case enDays::saturday:
	 	cout<<"It's saturday"<<endl;
		break;
	default :
		cout<<"Wrong input"<<endl;
	 		
	 	
	 }
	
	
	
	
	return 0;
}