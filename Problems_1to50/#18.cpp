#include <iostream>
#include <cmath>
using namespace std;

float ReadArea() {
	float R;
	cout<<"Enter R"<<endl;
	cin>>R;
	const float PI=3.14;
	return(ceil(PI*(pow(R,2))));
}
void printArea(float area){
	cout<<"Area = "<<area<<endl;
}
int main() {
	printArea(ReadArea());
	
}