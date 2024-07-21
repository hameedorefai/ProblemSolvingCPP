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
vector <string> SplitString(string S1, string Delim = " ")
{
	short pos = 0;
	string Word = "";
	vector <string> vS1;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		Word = S1.substr(0, pos);

		if (Word != "") vS1.push_back(Word);

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "") vS1.push_back(S1);

	return vS1;
}
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
stClient ConvertLineToRecord(string Line, string Seperator)
{
	stClient Client;
	vector <string> vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	
	return Client;
}
void PrintClientRecord(stClient Client)
{
	cout << "\n\nThe following is the extracted cloent record:\n";
	cout << "\nAccountNumber : " << Client.AccountNumber;
	cout << "\nPinCode       : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccountBalance: " << Client.AccountBalance;

}
int main()
{
	
	stClient stClient;

	stClient = ReadNewClientData();
	
	stClient = ConvertLineToRecord(ConvertRecordToLine(stClient), "#//#");
	
	PrintClientRecord(stClient);
	 
	return 0;
}

