#include <iostream>
using namespace std;


int main (){
	float penny=1,nickel=5,dime=10,quarter=25,dollar=100;
	cin>>penny>>nickel>>dime>>quarter>>dollar;
	
	float totatalpenies= (penny+nickel*5+dime*10+quarter*25+dollar*100);
	float totalDollars = (penny+nickel*5+dime*10+quarter*25+dollar*100)/100;
	cout<<"Pennies : "<<totatalpenies<<endl;
	cout<<"Dollar  : "<<totalDollars<<endl;

	
}