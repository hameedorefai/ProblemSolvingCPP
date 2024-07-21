#include <iostream>
using namespace std;

int sumUntil(){
	int number=0,sum=0;
	while(number!=-99){
		cin>>number;
		if(number!=-99)
		sum+=number;
	}
	return sum;
}
void printSum(int sum){
	cout<<"Sum : "<<sum<<endl;
}
int main(){
	printSum(sumUntil());
	return 0;
}