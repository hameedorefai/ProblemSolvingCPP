#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
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

string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "Please enter Account Number ? ";
	cin >> AccountNumber;
	return AccountNumber;
}
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

stClient ConvertLineToRecord(string Line, string Seperator = "#//#" )
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

vector <stClient> LoadClientsDataFromFileToV(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	vector <stClient> vClients;
	
	if (MyFile.is_open())
	{
		string Line;
		stClient Client;
		
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);

			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecord(stClient Client)
{
	cout << "| " << setw(15) << Client.AccountNumber;
	cout << "| " << setw(10) << Client.PinCode;
	cout << "| " << setw(40) << Client.Name;
	cout << "| " << setw(12) << Client.Phone;
	cout << "| " << setw(12) << Client.AccountBalance;

}

void PrintClientData(stClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "AccountNumber  : " << Client.AccountNumber << endl;
	cout << "PinCode        : " << Client.PinCode << endl;
	cout << "Client         : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "AccountBalance : " << Client.AccountBalance << endl;
}

void AddClientDataToFile(string FileName, string ClientDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

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

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);

	for (stClient Clientt : vClients)
	{
		if (Clientt.AccountNumber == AccountNumber)
		{
			Client = Clientt;
			return 1;
		}
	}
	return 0;
}

void PrintAllClientsData(vector <stClient> vstClients)
{

	cout << "\n\t\t\t\t\tClients List (" << vstClients.size() << ") Clients(s)." << endl;
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;

	for (stClient Client : vstClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}


}

int main()
{
	
	string AccountNumber = ReadClientAccountNumber();
	stClient Client;

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientData(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
	}

	return 0;
}

