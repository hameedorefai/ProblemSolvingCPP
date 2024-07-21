#include <iostream>
using namespace std;

long readTimeBySeconds(){
	long numberofSeconds,seconds;
	cin>>numberofSeconds;	
	return numberofSeconds;
}

void printTimeChlock(long numberofSeconds){
		long days=numberofSeconds/86400;
		numberofSeconds=numberofSeconds-days*86400;
	long hours=numberofSeconds/3600;
		numberofSeconds=numberofSeconds-hours*3600;
	long minutes=numberofSeconds/60;
		numberofSeconds=numberofSeconds-minutes*60;
		
	cout<<days<<":"<<hours<<":"<<minutes<<":"<<numberofSeconds<<endl;

}

int main(){
	printTimechlock(readTimeBySeconds());

}