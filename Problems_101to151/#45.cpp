#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
};

stClient ReadNewClientData()
{
	stClient stClient;

	cout << "Enter Client Data : \n" << endl;

	cout << "Enter AccountNumber? ";
	getline(cin, stClient.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, stClient.PinCode);
	cout << "Enter Name? ";
	getline(cin, stClient.Name);
	cout << "Enter Phone? ";
	getline(cin, stClient.Phone);
	cout << "Enter AccountBalance? ";
	cin >> stClient.AccountBalance;

	return stClient;
}
string ConvertRecordToLine(stClient stClient, string Seperator = "#//#")
{
	string stClientRecord = "";
	
	stClientRecord += stClient.AccountNumber + Seperator;
	stClientRecord += stClient.PinCode + Seperator;
	stClientRecord += stClient.Name + Seperator;
	stClientRecord += stClient.Phone + Seperator;
	stClientRecord += to_string(stClient.AccountBalance) + Seperator;

	return stClientRecord;


}

int main()
{
	
	stClient stClient;
	

	stClient = ReadNewClientData();
	
	cout << "\nClient Record for Saving is:\n";
	cout << ConvertRecordToLine(stClient) << endl;
	

	return 0;
}

