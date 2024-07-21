#include <iostream>
using namespace std;

long readTime(){
	int days,hours,minutes,seconds;
	cin>>days>>hours>>minutes>>seconds;
	long totalseconds=days*24*60*60+hours*60*60+minutes*60+seconds;
	return totalseconds;
}
void printTotalSeconds(long totalseconds){
		cout<<totalseconds<<endl;
}
int main(){
	printTotalSeconds(readTime());
	
}