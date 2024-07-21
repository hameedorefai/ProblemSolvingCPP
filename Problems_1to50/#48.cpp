#include <iostream>
using namespace std;


int main(){
	float loanAmount,MonthlyInstallmentAmount=0,Months;
	cin>>loanAmount>>Months;
	MonthlyInstallmentAmount=loanAmount/Months;
	cout<<MonthlyInstallmentAmount<<endl;
}