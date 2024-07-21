#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
const string ClientsFileName = "Clients.txt";



struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
};
bool ReadMore(string Message = "")
{
	char C;
	cout << Message;
	cin >> C;
	return (C == 'Y' || C == 'y');
}
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
	stClient Client;

	cout << "Enter AccountNumber? ";
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}
string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

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
void AddClientDataToFile(string FileName, string ClientDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out || ios::app);

	if (MyFile.is_open())
	{
		MyFile << ClientDataLine << endl;
		MyFile.close();
	}

}
void AddNewClient()
{
	stClient stClient;
	stClient = ReadNewClientData();
	AddClientDataToFile(ClientsFileName, ConvertRecordToLine(stClient));

}
void AddClients()
{

	do {
		system("cls");
		cout << "Adding New Clients:\n\n";
		AddNewClient();
		cout << "Client Added Successfully, do you want to add more clients?";
	} while (ReadMore());
}
int main()
{
	AddClients();

	return 0;
}

