#include <iostream>
using namespace std;

void read3Marks(float marks[3]){
	for(int i=0;i<3;i++){
	cout<<"Enter Mark "<<i+1<<endl;
	cin>>marks[i];
	}
}
float sum3Marks(float marks[3]){
		float sum =0;
	for(int i =0;i<3;i++){
		sum+=marks[i];
	}
	return sum;
}
float getAverage3Marks(float sum){
	float avg= sum/3;
	
}
void printAverage(float avg){
	cout<<"The average is : "<<avg<<endl;
}

int main(){
	float marks[3];
	read3Marks(marks);
	printAverage(getAverage3Marks(sum3Marks(marks)));
	
	
	return 0;
}

