#include <iostream>
using namespace std;

float totalBill(float BillValue){
	 return (BillValue+BillValue*0.1+BillValue*0.16);
}
int main (){
	float BillValue;
	cin>>BillValue;
	cout<<totalBill(BillValue)<<endl;
}