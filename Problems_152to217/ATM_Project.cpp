#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
using namespace std;
const string ClientsFileName = "Clients.txt";
void GoBackToMainMenue(int);
void ShowMainMenue(int);
void LoginATM();
//void ShowGoBackToATMMenu();
void GoBackToATMMenu();
//void ShowTransactionsATMMenue();
void Login();
void ShowManageUser(int);
void ShowLoginScreen();
//void ShowTransactionsMenue();
//void ShowTransactionsATMMenue();

struct stClient
{
	string AccountNumber = " ";
	string PinCode = " ";
	string Name = " ";
	string Phone = " ";
	double AccountBalance = 0.0;
	bool MarkForDelete = false;
	bool MakeForUpdate = false;
};
enum enMainMenueOptions
{
	ShowClientsList = 1, eAddNewClient = 2, DeleteClient = 3,
	UpdateClientInformations = 4, FindCliend = 5, Transactions = 6,
	ManageUser = 7, eLogout = 8,
};
enum enATMMenueOptions
{
	eQuickWithdraw = 1, eNormalWithdraw,
	eDeposit, eCheckBalance, eLougout
};
void PerformATMOption(enATMMenueOptions);

string ReadText(string Message = "")
{
	string S;
	cout << Message;
	cin >> S;
	return S;
}
stClient DefaultClient()
{
	stClient Client;
	Client.AccountNumber = "";
	Client.PinCode = "";
	Client.Name = "";
	Client.Phone = "";
	Client.AccountBalance = 0.0;
	Client.MarkForDelete = false;
	Client.MakeForUpdate = false;
	return Client;
}
string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "Please enter Account Number ? ";
	cin >> AccountNumber;
	return AccountNumber;
}
enMainMenueOptions ReadMainMenueOption()
{
	short  Choice;
	do {
		cout << "Choose what do you want to do [1 to 8] : ";
		cin >> Choice;
	} while (Choice > 8 || Choice < 1);
	return (enMainMenueOptions)Choice;
}
enATMMenueOptions ReadATMMenueOption()
{
	short  Choice;
	do {
		cout << "Choose what do you want to do? [1 to 5] : ";
		cin >> Choice;
	} while (Choice > 5 || Choice < 1);
	return (enATMMenueOptions)Choice;
}

double ReadNumberWidthAmount(double Balance)
{
	double Amount;
	cout << "Please enter Withdraw amount ? ";
	cin >> Amount;
	while (Amount < 0 || Amount > Balance)
	{
		cout << "amount exceeds the balance, you can withdraw up to " << Balance << endl;
		cout << "Enter another amount : ";
		cin >> Amount;
	}
	return Amount;
}
bool ReadMore(string Message = "")
{
	char C;
	cout << Message;
	cin >> C;
	return (C == 'Y' || C == 'y');
}
bool ReadAnswer(string Message = "")
{
	char Answer;
	cout << Message;
	cin >> Answer;
	return (Answer == 'Y' || Answer == 'y');
}
string tolowerCase(string S)
{
	for (int i = 0; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
	}
	return S;
}
vector <string> SplitString(string S1, string Delim = " ")
{
	size_t pos = 0;
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
stClient ConvertLineToRecordClient(string Line, string Seperator = "#//#")
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

vector <string> GetAccountsNumbers(vector <stClient>& vClients)
{
	vector <string> AccountsNumbers;
	for (stClient Client : vClients)
	{
		AccountsNumbers.push_back(Client.AccountNumber);
	}
	return AccountsNumbers;
}
void ShowEndProgram()
{
	system("cls");
	cout << "\n___________________________________\n";
	cout << "\t Program Ends :-)";
	cout << "\n___________________________________\n\n";
}

void AddClientDataToFile(string FileName, string ClientDataLine)
{
	fstream MyFile;
	stClient Client = ConvertLineToRecordClient(ClientDataLine);
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open() && Client.MarkForDelete == false)
	{
		MyFile << ClientDataLine << endl;
		MyFile.close();
	}

}
void AddAllClientsDataFromVToFile(string FileName, vector <stClient>& vClients)
{
	for (stClient Client : vClients)
	{
		if (Client.MarkForDelete == false)
			AddClientDataToFile(ClientsFileName, ConvertRecordToLine(Client));
	}
}
void ClearAllDataFile(string FileName)
{
	fstream File;

	File.open(FileName, ios::out);

	if (File.is_open())
	{
		File.clear();
		File.close();
	}
}

bool IsAccountNumberExists(string AccNum, vector <string>& AccountsNumbers)
{
	for (string ExistsAccNum : AccountsNumbers)
	{
		if (AccNum == ExistsAccNum)
		{
			return 1;
		}
	}
	return 0;
}
stClient ReadNewClientData(vector <string>& AccountsNumbers)
{
	stClient Client;
	string AccountNum;

	cout << "Enter AccountNumber? ";
	getline(cin >> ws, AccountNum);

	while (IsAccountNumberExists(AccountNum, AccountsNumbers))
	{
		cout << "Client with [" << AccountNum << "] is already exists,";
		cout << " Enter another Account Number? ";
		getline(cin >> ws, AccountNum);

	}

	Client.AccountNumber = AccountNum;
	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}
void AddNewClient(vector <string>& AccountsNumbers)
{

	stClient stClient;
	stClient = ReadNewClientData(AccountsNumbers);
	AddClientDataToFile(ClientsFileName, ConvertRecordToLine(stClient));

}
void AddClients(vector <stClient>& vClients)
{
	vector <string> AccountsNumbers = GetAccountsNumbers(vClients);
	do {
		cout << "\n___________________________________\n";
		cout << "\t Add New Clients Screen";
		cout << "\n___________________________________\n";
		AddNewClient(AccountsNumbers);
		cout << "Client Added Successfully, do you want to add more clients? ";
	} while (ReadMore());
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
			Client = ConvertLineToRecordClient(Line);

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
	cout << "\n___________________________________\n";
	cout << "AccountNumber  : " << Client.AccountNumber << endl;
	cout << "PinCode        : " << Client.PinCode << endl;
	cout << "Client         : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "AccountBalance : " << Client.AccountBalance << endl;
	cout << "\n___________________________________\n";
}


bool FindClientByAccountNumber(vector <stClient>& vClients, stClient& Client, string AccountNumber)
{
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
void DeleteAccountFromClientsVector(vector <stClient>& vClients, string AccountNumber)
{
	string Message = "Are you sure you want to delete this account? Y/N : ";

	if (ReadAnswer(Message))
	{
		vector <stClient> vC;

		for (stClient& C : vClients)
		{
			if (C.AccountNumber != AccountNumber)
			{
				vC.push_back(C);
			}
			else
			{
				C.MarkForDelete = true;
			}
		}
		cout << "Client deleted successfully!\n";
		vClients = vC;
	}
	else
	{
		cout << "Good choice <3\n";
	}
}
void DeleteClientByAccountNumber(vector <stClient>& vClients, string AccountNumber)
{
	stClient Client;

	if (FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		PrintClientData(Client);
		DeleteAccountFromClientsVector(vClients, AccountNumber);
		ClearAllDataFile(ClientsFileName);
		AddAllClientsDataFromVToFile(ClientsFileName, vClients);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
	}

}

void ReadNewInfoForClient(stClient& Client)
{

	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;


}
void UpdateMarkedAccounts(vector <stClient>& vClients)
{
	vector <stClient> vC;
	for (stClient& Client : vClients)
	{
		if (Client.MakeForUpdate)
		{
			ReadNewInfoForClient(Client);
		}
	}
}
void MakeAMarkForUpdateAccount(vector <stClient>& vClients, string AccountNumber)
{
	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
			C.MakeForUpdate = true;
		break;
	}

}
void UpdateClientByAccountNumber(vector <stClient>& vClients, string AccountNumber)
{
	stClient Client;

	if (FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		PrintClientData(Client);
		string Message = "Are you sure you want to update this account? Y/N : ";
		if (ReadAnswer(Message))
		{
			MakeAMarkForUpdateAccount(vClients, AccountNumber);
			UpdateMarkedAccounts(vClients);
			ClearAllDataFile(ClientsFileName);
			AddAllClientsDataFromVToFile(ClientsFileName, vClients);
			cout << "Client updated successfully!\n";
		}
		else
		{
			cout << "Account will not be updated\n";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
	}

}

void PrintAllClientsData(vector <stClient> vClients)
{

	cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") Clients(s)." << endl;
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;

	for (stClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}


}



void ShowClientList(vector <stClient>& vClients)
{
	PrintAllClientsData(vClients);
}
void AddNewClientScreen(vector <stClient>& vClients)
{
	AddClients(vClients);

}
void DeleteClientScreen(vector <stClient>& vClients)
{
	cout << "\n___________________________________\n";
	cout << "\t Delete Client Screen";
	cout << "\n___________________________________\n";
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(vClients, AccountNumber);
}
void UpdateClientInfo(vector <stClient>& vClients)
{
	cout << "\n___________________________________\n";
	cout << "\t Update Client Screen";
	cout << "\n___________________________________\n";
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(vClients, AccountNumber);
}
void AutoSaveClientsInfo(vector <stClient> vClients)
{
	ClearAllDataFile(ClientsFileName);
	AddAllClientsDataFromVToFile(ClientsFileName, vClients);
}
void FindAccount(vector <stClient>& vClients)
{
	stClient Client;
	string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		PrintClientData(Client);
	}
	else
		cout << "Client with Number (" << AccountNumber << ") is NOT found.\n";
}


void DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <stClient> vClients)
{
	stClient Client;
	for (stClient& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client.AccountBalance += Amount;
			AutoSaveClientsInfo(vClients);
			cout << "Done successfully!\n";
			cout << "New Balance : " << Client.AccountBalance << endl;
			break;
		}
	}

}
void Deposite()
{
	cout << "\n___________________________________\n";
	cout << "\t\tDeposit Screen";
	cout << "\n___________________________________\n";
	double Amount = 0;
	stClient Client;

	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		cout << "Client with Number (" << AccountNumber << ") is NOT found.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientData(Client);
	cout << "Please enter deposit amount? ";
	cin >> Amount;
	string Message = "Are you sure you want Deposit? Y/N : ";
	if (ReadAnswer(Message))
	{
		DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);

	}

}
void Withdraw()
{
	cout << "\n___________________________________\n";
	cout << "\t\tWithdraw Screen";
	cout << "\n___________________________________\n";
	double Amount = 0;
	stClient Client;
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	while (!FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		cout << "Client with Number (" << AccountNumber << ") is NOT found.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientData(Client);

	Amount = ReadNumberWidthAmount(Client.AccountBalance);

	string Message = "Are you sure you want to Withdraw? Y/N : ";
	if (ReadAnswer(Message))
	{
		DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
	}

}
void ShowClientsTotalBalances()
{

	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);

	cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") Clients(s)." << endl;
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;

	double AllBalances = 0;
	for (stClient Client : vClients)
	{
		cout << "| " << setw(15) << Client.AccountNumber;
		cout << "| " << setw(40) << Client.Name;
		cout << "| " << setw(12) << Client.AccountBalance;
		AllBalances += Client.AccountBalance;
		cout << endl;
	}
	cout << "| Total Balances : " << AllBalances << endl;

}
//void ShowTransactionsMenue()
//{
//	system("cls");
//	cout << "====================================\n";
//	cout << "\tTransactions Menue Screen\n";
//	cout << "====================================\n";
//	cout << "\t[1] Deposit.\n";
//	cout << "\t[2] Withdraw.\n";
//	cout << "\t[3] Total Balances.\n";
//	cout << "\t[4] Main Menue.\n";
//	cout << "====================================\n";
//}
//void PerformTransactionsOption(enTransactionsmenueOptions TransactionOption)
//{
//	switch (TransactionOption)
//	{
//	case eDeposit:
//		system("cls");
//		Deposite();
//		GoBackToTransactions();
//		break;
//	case eWithdraw:
//		system("cls");
//		Withdraw();
//		GoBackToTransactions();
//		break;
//	case eTotalBalances:
//		system("cls");
//		ShowClientsTotalBalances();
//		GoBackToTransactions();
//		break;
//	case eMainMenue:
//		ShowMainMenue();
//		break;
//	}
//}
//
//void ShowTransactions()
//{
//	ShowTransactionsMenue();
//	PerformTransactionsOption(ReadTransactionsMenueOption());
//}
//void GoBackToTransactions()
//{
//	system("pause>0");
//	cout << "Press any key to go back to Transaction Menue...";
//	ShowTransactions();
//}

void ShowTransactions()
{
	cout << "\n\nFunction : ShowTransactions Is under repair.\n\n";
	//ShowTransactionsMenue();
	///PerformTransactionsOption(ReadTransactionsMenueOption());
}







void PerformMainMenuOption(int intPermissions, enMainMenueOptions MainMenueOption)
{

	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	if (intPermissions == -1) {
		switch (MainMenueOption)
		{
		case ShowClientsList:
			system("cls");
			ShowClientList(vClients);
			GoBackToMainMenue(intPermissions);
			break;
		case eAddNewClient:
			system("cls");

			AddNewClientScreen(vClients);
			GoBackToMainMenue(intPermissions);
			break;
		case DeleteClient:
			system("cls");

			DeleteClientScreen(vClients);
			GoBackToMainMenue(intPermissions);

			break;
		case UpdateClientInformations:
			system("cls");
			UpdateClientInfo(vClients);
			GoBackToMainMenue(intPermissions);
			break;
		case FindCliend:
			system("cls");
			FindAccount(vClients);
			GoBackToMainMenue(intPermissions);
			GoBackToMainMenue(intPermissions);
			break;
		case Transactions:

			ShowTransactions();
			break;
		case ManageUser:
			system("cls");

			ShowManageUser(intPermissions);

			break;
		case eLogout:
			system("clr");
			Login();
			break;
		default:
			cout << "Wrong in Function : PerformMainMenuOption\n";
		}
	}
	else
	{
		switch (MainMenueOption)
		{
		case ShowClientsList:
			system("cls");
			if ((intPermissions & 1) != 0)
			{
				ShowClientList(vClients);
				GoBackToMainMenue(intPermissions);
			}
			else
			{
				cout << "You are not allowed to access here, Please Go to your manager.\n";
				GoBackToMainMenue(intPermissions);
			}
			break;
		case eAddNewClient:
			system("cls");
			if ((intPermissions & 2) != 0)
			{
				AddNewClientScreen(vClients);
				GoBackToMainMenue(intPermissions);
			}
			else
			{
				cout << "You are not allowed to access here, Please Go to your manager.\n";
				GoBackToMainMenue(intPermissions);
			}			break;
		case DeleteClient:
			system("cls");
			if ((intPermissions & 4) != 0)
			{
				DeleteClientScreen(vClients);
				GoBackToMainMenue(intPermissions);
			}
			else
			{
				cout << "You are not allowed to access here, Please Go to your manager.\n";
				GoBackToMainMenue(intPermissions);
			}			break;
		case UpdateClientInformations:
			system("cls");
			if ((intPermissions & 8) != 0)
			{
				UpdateClientInfo(vClients);
				GoBackToMainMenue(intPermissions);
			}
			else
			{
				cout << "You are not allowed to access here, Please Go to your manager.\n";
				GoBackToMainMenue(intPermissions);
			}			break;
		case FindCliend:
			system("cls");
			if ((intPermissions & 16) != 0)
			{
				FindAccount(vClients);
				GoBackToMainMenue(intPermissions);
			}
			else
			{
				cout << "You are not allowed to access here, Please Go to your manager.\n";
				GoBackToMainMenue(intPermissions);
			}			break;
		case Transactions:
			system("cls");
			if ((intPermissions & 32) != 0)
			{
				ShowTransactions();
			}
			else
			{
				cout << "You are not allowed to access here, Please Go to your manager.\n";
				GoBackToMainMenue(intPermissions);
			}			break;
		case ManageUser:
			system("cls");
			if ((intPermissions & 64) != 0)
			{
				ShowManageUser(intPermissions);
			}
			else
			{
				cout << "You are not allowed to access here, Please Go to your manager.\n";
				GoBackToMainMenue(intPermissions);
			}			break;
		case eLogout:
			system("clr");
			Login();
			break;
		default:
			cout << "Wrong in Function : PerformMainMenuOption\n";
		}
	}
}
void ShowMainMenueScreen()
{
	system("cls");
	cout << "====================================\n";
	cout << "\tMain Menue Screen\n";
	cout << "====================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "====================================\n";

}
void ShowMainMenue(int intPermissions)
{
	ShowMainMenueScreen();
	PerformMainMenuOption(intPermissions, ReadMainMenueOption());
}
void GoBackToMainMenue(int intPermissions)
{
	cout << "\nPress any key to go back to main menue...";
	system("pause>0");
	ShowMainMenue(intPermissions);
}









const string UsersFileName = "Users.txt";

struct stPermissions
{

	bool ClientList = 0;
	bool AddNewClient = 0;
	bool DeleteClient = 0;
	bool UpdateClient = 0;
	bool FindClient = 0;
	bool Transactions = 0;
	bool ManageUsers = 0;

};
struct stUser
{
	string Username;
	string Password;
	stPermissions Permissions;// = DefaultPermissions();
	int intPermissions = 0;
	bool MarkForDelete = false;
	bool MakeForUpdate = false;
};
stUser CurrentUser;
enum enManageUsersOptions
{
	enShowUserList = 1, enAddNewUser, enDeleteUser,
	enUpdateUserInfo, enFindUser, enMainMenue
};
enum enPermissions {
	AllPermissions = -1,
	eClientList = 1,
	eeAddNewClient = 2,
	eDeleteClient = 4,
	eUpdateClient = 8,
	eFindClient = 16,
	eTransactions = 32,
	eManageUsers = 65
};
void UpdateUserByUsername(vector <stUser>& vUsers, string Username);
string ConvertRecordToLine(stUser User, string Seperator = "#//#")
{
	string stUserRecord = "";

	stUserRecord += User.Username + Seperator;
	stUserRecord += User.Password + Seperator;
	stUserRecord += to_string(User.intPermissions);

	return stUserRecord;
}
stUser ConvertLineToRecordUser(string Line, string Seperator = "#//#")
{
	stUser User;
	vector <string> vUserData = SplitString(Line, Seperator);

	User.Username = vUserData[0];
	User.Password = vUserData[1];
	// Here we'll Make method for this reason after to make Premissions acted by Binary(int Permissions).  (Done).
	User.intPermissions = stoi(vUserData[2]);
	return User;
}

stPermissions DefaultPermissions()
{
	stPermissions Permissions;
	Permissions.ClientList = 1;
	Permissions.AddNewClient = 1;
	Permissions.DeleteClient = 1;
	Permissions.UpdateClient = 1;
	Permissions.FindClient = 1;
	Permissions.Transactions = 1;
	Permissions.ManageUsers = 1;
	return Permissions;
}
stUser DefaultUser()
{
	stUser User;
	User.Username = "User" + to_string(rand() & 100);
	User.Password = "0000";
	User.Permissions = DefaultPermissions();
	User.MarkForDelete = false;
	User.MakeForUpdate = false;
	return User;
}

stPermissions ReadPermissions()
{
	stPermissions Permissions;
	string Message;
	Message = "Do you want this user to access to all methods Y/N? ";
	if (ReadAnswer(Message))
	{
		Permissions = DefaultPermissions();

	}
	else
	{
		cout << "Do you want this user to access These : \n";
		Message = "ClientList Y/N? ";
		Permissions.ClientList = ReadAnswer(Message);
		Message = "AddNewClient Y/N? ";
		Permissions.AddNewClient = ReadAnswer(Message);
		Message = "DeleteClient Y/N? ";
		Permissions.DeleteClient = ReadAnswer(Message);
		Message = "UpdateClient Y/N? ";
		Permissions.UpdateClient = ReadAnswer(Message);
		Message = "FindClient Y/N? ";
		Permissions.FindClient = ReadAnswer(Message);
		Message = "Transactions Y/N? ";
		Permissions.Transactions = ReadAnswer(Message);
		Message = "ManageUsers Y/N? ";
		Permissions.ManageUsers = ReadAnswer(Message);
	}
	return Permissions;
}
void RegistPermissionsInUser(stUser& User)
{
	// ?? ???????? ????? ???? ???? ??????? ????? ??? ??? ?????? ?????? ??????? ????
	// ????? ????? ?????? ???????.
	User.intPermissions = 0;
	User.Permissions = ReadPermissions();

	if (User.Permissions.ClientList)
	{
		User.intPermissions += 1;
	}
	if (User.Permissions.AddNewClient)
	{
		User.intPermissions += 2;
	}
	if (User.Permissions.DeleteClient)
	{
		User.intPermissions += 4;
	}
	if (User.Permissions.UpdateClient)
	{
		User.intPermissions += 8;
	}
	if (User.Permissions.FindClient)
	{
		User.intPermissions += 16;
	}
	if (User.Permissions.Transactions)
	{
		User.intPermissions += 32;
	}
	if (User.Permissions.ManageUsers)
	{
		User.intPermissions += 64;
	}
	if (User.intPermissions == 127)
	{
		User.intPermissions = -1;
	}


}
string ReadUsername()
{
	string Username;
	cout << "Please enter Username ? ";
	cin >> Username;
	return Username;
}
string ReadPassword()
{
	string Password;
	cout << "Enter Password? ";
	cin >> Password;
	return Password;
}

void PrintUserRecord(stUser User)
{
	cout << "| " << setw(15) << User.Username;
	cout << "| " << setw(10) << User.Password;
	cout << "| " << setw(40) << User.intPermissions;


}
void PrintUserData(stUser User)
{
	cout << "\nThe following are the User details:\n";
	cout << "\n___________________________________\n";
	cout << "User name  : " << User.Username << endl;
	cout << "Password   : " << User.Password << endl;
	cout << "Permission : " << User.intPermissions << endl;
	cout << "\n___________________________________\n";
}
void PrintAllUsersData(vector <stUser> vUsers)
{

	cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s)." << endl;
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Username";
	cout << "| " << left << setw(10) << "Password";
	cout << "| " << left << setw(40) << "Permissions";
	cout << "\n_________________________________________________________";
	cout << "__________________________________________\n" << endl;

	for (stUser User : vUsers)
	{
		PrintUserRecord(User);
		cout << endl;
	}


}
//1
bool FindUserByUsername(vector <stUser>& vUsers, stUser& User, string Username)
{
	for (stUser Userr : vUsers)
	{
		if (tolowerCase(Userr.Username) == tolowerCase(Username))
		{
			User = Userr;
			return 1;
		}
	}
	return 0;
}
void FindUser(vector <stUser> vUsers)
{
	string Username = ReadUsername();
	stUser User;
	if (FindUserByUsername(vUsers, User, Username))
	{
		PrintUserData(User);
	}
	else
		cout << "Username does not exists!\n";
}
//--
vector <stUser> LoadUsersDataFromFileToV(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	vector <stUser> vUsers;

	if (MyFile.is_open())
	{
		string Line;
		stUser User;

		while (getline(MyFile, Line))
		{
			User = ConvertLineToRecordUser(Line);

			vUsers.push_back(User);
		}
		MyFile.close();
	}
	return vUsers;
}
vector <string> GetUsersnames(vector <stUser>& vUser)
{
	vector <string> Username;
	for (stUser User : vUser)
	{
		Username.push_back(User.Username);
	}
	return Username;
}
void AddUserDataToFile(string FileName, string UserDataLine)
{
	fstream MyFile;
	stUser User = ConvertLineToRecordUser(UserDataLine);
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open() && User.MarkForDelete == false)
	{
		MyFile << UserDataLine << endl;
		MyFile.close();
	}

}
void AddAllUsersDataFromVToFile(string FileName, vector <stUser>& vUser)
{
	for (stUser User : vUser)
	{
		if (User.MarkForDelete == false)
			AddUserDataToFile(UsersFileName, ConvertRecordToLine(User));
	}
}
void AutoSaveUsersInfo(vector <stUser> vUsers)
{
	ClearAllDataFile(UsersFileName);
	AddAllUsersDataFromVToFile(UsersFileName, vUsers);
}
//2
bool IsUsernameExists(string Username, vector <string>& Usersnames)
{
	for (string ExistsUsername : Usersnames)
	{
		if (Username == ExistsUsername)
		{
			return 1;
		}
	}
	return 0;
}
stUser ReadNewUserData(vector <string>& Usersnames)
{
	stUser User;
	string Username;

	Username = ReadUsername();

	short Counter = 1;
	while (IsUsernameExists(Username, Usersnames))
	{
		cout << "User with [" << Username << "] is already exists.\n";
		if (Counter == 3)
		{
			//	cout << "Please try again later.\n"; (Has written in another place)
			User.Username = "Empty";
			return User;
		}
		Username = ReadUsername();
		Counter++;
	}

	User.Username = Username;
	User.Password = ReadPassword();
	RegistPermissionsInUser(User);

	return User;
}
bool AddNewUser(vector <stUser>& vUsers)
{
	vector <string> Usersames = GetUsersnames(vUsers);
	stUser User;
	User = ReadNewUserData(Usersames);
	if (User.Username != "Empty")
	{
		AddUserDataToFile(UsersFileName, ConvertRecordToLine(User));
		return 1;
	}
	else
		cout << "Please try again later.\n";
	return 0;

}
void AddNewUsers(vector <stUser>& vUsers)
{
	// NOTE : This is AddNewUsers Function and it adds Users to Vector by ref
	do {

		if (AddNewUser(vUsers))
		{
			cout << "User Added Successfully, do you want to add more Users? ";
		}
		else
			break;
	} while (ReadMore());
}
void AddNewUserScreen(vector <stUser>& vUsers)
{
	cout << "\n___________________________________\n";
	cout << "\t Add New User Screen";
	cout << "\n___________________________________\n";
	AddNewUsers(vUsers);
}
//3
void DeleteUserFromUsersVector(vector <stUser>& vUsers, string Username)
{
	vector <stUser> vU;

	for (stUser& U : vUsers)
	{
		if (U.Username != Username)
			vU.push_back(U);
		else
			U.MarkForDelete = true;

	}
	vUsers = vU;
}
void DeleteUserByUsername(vector <stUser>& vUsers, string Username)
{
	stUser User;
	if (FindUserByUsername(vUsers, User, Username))
	{
		if ("admin" == tolowerCase(User.Username))
		{
			cout << "\nYou can NOT Delete admin.\n";
			cout << "User will not be deleted.\n";
		}
		else
		{
			PrintUserData(User);

			string Message = "Are you sure you want to delete this User? Y/N : ";
			if (ReadAnswer(Message))
			{
				DeleteUserFromUsersVector(vUsers, Username);
				AutoSaveUsersInfo(vUsers);
				cout << "User deleted successfully!\n";
			}
			else
				cout << "User will not be deleted.\n";
		}
		cout << "\nNOTE: You have to block any user of editting on Admin user\n" <<
			"Fincton : (DeleteUserByUsername)\n\n";
	}
	else
		cout << "\nUser with Username (" << Username << ") is Not Found!\n";

}
void DeleteUser(vector <stUser>& vUsers, string Username)
{
	DeleteUserByUsername(vUsers, Username);
}
void DeleteUserScreen(vector <stUser>& vUsers)
{
	cout << "\n___________________________________\n";
	cout << "\t Delete User Screen";
	cout << "\n___________________________________\n";
	string Username = ReadUsername();
	DeleteUser(vUsers, Username);
}
//4
void UpdateUser(stUser& User)
{
	cout << "Input new date : \n";
	User.Password = ReadPassword();
	RegistPermissionsInUser(User);
}
void UpdateMarkedUsers(vector <stUser>& vUsers)
{
	vector <stUser> vU;
	for (stUser& User : vUsers)
	{
		if (User.MakeForUpdate)
		{
			UpdateUser(User);
			AutoSaveUsersInfo(vUsers);
		}
	}
}
void MakeAMarkForUpdateUser(vector <stUser>& vUsers, string Username)
{
	for (stUser& U : vUsers)
	{
		if (U.Username == Username)
		{
			U.MakeForUpdate = true;
			break;
		}
	}

}
void UpdateUserByUsername(vector <stUser>& vUsers, string Username)
{
	stUser User;

	if (FindUserByUsername(vUsers, User, Username))
	{
		if ("admin" == tolowerCase(User.Username))
		{

			cout << "\nYou can NOT Update admin.\n";
			cout << "User will not be Updated.\n";
		}
		else
		{
			PrintUserData(User);
			string Message = "Are you sure you want to update this User? Y/N : ";
			if (ReadAnswer(Message))
			{
				MakeAMarkForUpdateUser(vUsers, User.Username);
				UpdateMarkedUsers(vUsers);
				cout << "User updated successfully!\n";
			}
			else
			{
				cout << "User will not be updated\n";
			}
		}
		cout << "\nNOTE: You have to block any user of editting on Admin user\n" <<
			"Fincton : (UpdateUserByUsername)\n\n";
	}
	else
	{
		cout << "\nUser with Username (" << Username << ") is Not Found!\n";
	}

}
void ShowUpdateUserInfoScreen(vector <stUser>& vUsers)
{
	cout << "\n___________________________________\n";
	cout << "\t Update User Screen";
	cout << "\n___________________________________\n";
	string Username = ReadUsername();
	UpdateUserByUsername(vUsers, Username);
}
//5
void ShowUserList(vector <stUser>& vUsers)
{
	PrintAllUsersData(vUsers);
}

//6
void GoBackToManageUsers(int intPermissions)
{
	cout << "\nPress any key to go back to Manage Users Menue...\n";
	system("pause>0");
	ShowManageUser(intPermissions);
}
enManageUsersOptions ReadManageUsersOption()
{
	short  Choice;
	do {
		cout << "Choose what do you want to do [1 to 6] : ";
		cin >> Choice;
	} while (Choice > 8 || Choice < 1);
	return (enManageUsersOptions)Choice;
}
void PerformManageUsersOption(enManageUsersOptions ManageUsersOption, int intPermissions)
{
	vector <stUser> vUsers = LoadUsersDataFromFileToV(UsersFileName);

	switch (ManageUsersOption)
	{
	case enShowUserList:
	{
		system("cls");
		ShowUserList(vUsers);
		GoBackToManageUsers(intPermissions);
		break;
	}
	case enAddNewUser:
	{
		system("cls");
		AddNewUserScreen(vUsers);
		GoBackToManageUsers(intPermissions);
		break;
	}
	case enDeleteUser:
	{
		system("cls");
		DeleteUserScreen(vUsers);
		GoBackToManageUsers(intPermissions);
		break;
	}
	case enUpdateUserInfo:
	{
		system("cls");
		ShowUpdateUserInfoScreen(vUsers);
		GoBackToManageUsers(intPermissions);
		break;
	}
	case enFindUser:
	{
		system("cls");
		FindUser(vUsers);
		GoBackToManageUsers(intPermissions);
		break;
	}
	case enMainMenue:
	{
		ShowMainMenue(intPermissions);
		break;
	}
	default:
	{
		cout << "Error in Function : PerformManageUsersOption.\n";
	}
	}
}
void ShowManageUserScreen()
{
	system("cls");
	cout << "====================================\n";
	cout << "\tManage Users Menue Screen\n";
	cout << "====================================\n";
	cout << "\t[1] Show Users List.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User Info.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Main Menue.\n";
	cout << "====================================\n";
}
void ShowManageUser(int intPermissions)
{
	ShowManageUserScreen();
	PerformManageUsersOption(ReadManageUsersOption(), intPermissions);
}



bool CheckUserLogin(string Username, string Password)
{
	vector <stUser> vUsers = LoadUsersDataFromFileToV(UsersFileName);
	stUser User;

	if (FindUserByUsername(vUsers, User, Username))
	{
		if (Password == User.Password)
		{
			return 1;
		}
		else
		{
			system("cls");
			ShowLoginScreen();
			cout << "Password is incorrect!\n";
		}
	}
	else
	{
		system("cls");
		ShowLoginScreen();
		cout << "Username is not found!\n";
	}
	return 0;




}
void ShowLoginScreen()
{
	system("cls");
	cout << "\n___________________________________\n";
	cout << "\t Login screen ";
	cout << "\n___________________________________\n\n";
}
void Login()
{
	ShowLoginScreen();

	stUser User;
	vector <stUser> vUser = LoadUsersDataFromFileToV(UsersFileName);
	short Counter = 0;
	while (Counter != 3)
	{
		string Username = ReadUsername();
		string Password = ReadPassword();
		if (CheckUserLogin(Username, Password))
		{
			stUser User;
			FindUserByUsername(vUser, User, Username);
			ShowMainMenue(User.intPermissions);
			break;
		}
		if (Counter == 3)
		{
			cout << "You've tried 3 times, try again later.\n";
		}
		Counter++;
	}
}




stClient GeneralClient;

void DepositBalanceToClientByAccountNumberATM(string AccountNumber, double Amount, vector <stClient> vClients)
{
	stClient Client;
	for (stClient& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client.AccountBalance += Amount;
			AutoSaveClientsInfo(vClients);
			cout << "Done successfully!\n";
			cout << "New Balance : " << Client.AccountBalance << endl;
			GeneralClient.AccountBalance = Client.AccountBalance;
			break;
		}
	}

}

void ShowBalance()
{
	cout << "Balance is : " << GeneralClient.AccountBalance << endl;
}
void NormalDeposite()
{
	cout << "\n___________________________________\n";
	cout << "\t\tDeposit Screen";
	cout << "\n___________________________________\n";
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	double Amount = 0;
	while (Amount <= 0)
	{
		cout << "Please enter a positive deposit amount? ";
		cin >> Amount;
	}
	string Message = "Are you sure you want Deposit? Y/N : ";
	if (ReadAnswer(Message))
	{
		DepositBalanceToClientByAccountNumberATM(GeneralClient.AccountNumber, Amount, vClients);
	}

}

void PerformQuickWithdrawOptions(vector <stClient>& vClients)
{
	int Number;
	stClient Client;
	int Amount = 0;
	cout << "Choose what to withdraw from[1] to[8] : ";
	cin >> Number;

	if (Number > 0 && Number < 10)
	{
		switch (Number)
		{
		case 1:
			Amount = 20;
			break;
		case 2:
			Amount = 50;
			break;
		case 3:
			Amount = 100;
			break;
		case 4:
			Amount = 200;
			break;
		case 5:
			Amount = 400;
			break;
		case 6:
			Amount = 600;
			break;
		case 7:
			Amount = 800;
			break;
		case 8:
			Amount = 1000;
			break;
		case 9:
			return;
		default:
			cout << "Error" << endl;
		}
		string Message = "Are you sure you want to Withdraw? Y/N : ";
		if (ReadAnswer(Message))
		{
			DepositBalanceToClientByAccountNumberATM(GeneralClient.AccountNumber, Amount * -1, vClients);
		}
	}
}
void ShowQuickWithdrawScreen()
{
	cout << "\n___________________________________\n";
	cout << "\tQuick Withdraw Screen";
	cout << "\n___________________________________\n";
	cout << " [1] 20 \t[2] 50\n";
	cout << " [3] 100\t[4] 200\n";
	cout << " [5] 400\t[6] 600\n";
	cout << " [7] 800\t[8] 1000\n";
	cout << " [9] Exit\n";
}
void QuickWithdraw()
{

	double Amount = 0;
	stClient Client;
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	ShowQuickWithdrawScreen();
	ShowBalance();
	PerformQuickWithdrawOptions(vClients);
}
void NormalWithdraw()
{
	cout << "\n___________________________________\n";
	cout << "\tNormal Withdraw Screen";
	cout << "\n___________________________________\n";
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	int Amount;
	stClient Client;

	do
	{
		cout << "enter an amount multipli of 5's ? ";
		cin >> Amount;
	} while ((Amount <= 0 || Amount > Client.AccountBalance) && Amount && Amount % 5 != 0);
	string Message = "Are you sure you want to Withdraw? Y/N : ";
	if (ReadAnswer(Message))
	{
		DepositBalanceToClientByAccountNumberATM(GeneralClient.AccountNumber, Amount * -1, vClients);
	}

}

void ShowATMMenue()
{
	system("cls");
	cout << "====================================\n";
	cout << "\tATM Menue Screen\n";
	cout << "====================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposite.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "====================================\n";
}
void PerformATMOptions(enATMMenueOptions ATMOption)
{
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	switch (ATMOption)
	{
	case eQuickWithdraw:
		system("cls");
		QuickWithdraw();
		GoBackToATMMenu();
		break;
	case eNormalWithdraw:
		system("cls");
		NormalWithdraw();
		GoBackToATMMenu();
		break;
	case eDeposit:
		system("cls");
		NormalDeposite();
		GoBackToATMMenu();
		break;
	case eCheckBalance:
		system("cls");
		ShowBalance();
		GoBackToATMMenu();
		break;
	case eLougout:
		LoginATM();
		break;
	}
}
void ATM()
{
	ShowATMMenue();
	PerformATMOptions(ReadATMMenueOption());
}
void GoBackToATMMenu()
{
	cout << "Press any key to go back to ATM Menue...";
	system("pause>0");
	ATM();
}

bool IsFoundAccount(vector <stClient> vClients, stClient& Client, string AccountNumber)
{
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
bool CheckLogingATM(string AccountNumber, string PinCode)
{
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	stClient Client;

	if (IsFoundAccount(vClients, Client, AccountNumber))
	{
		if (PinCode == Client.PinCode)
		{
			GeneralClient = Client;
			return 1;
		}
		else
		{
			system("cls");
			ShowLoginScreen();
			cout << "Invalid PinCode\n";
		}
	}
	else
	{
		system("cls");
		ShowLoginScreen();
		cout << "Invalid Account Number\n";
	}
	return 0;
}
void LoginATM()
{
	ShowLoginScreen();

	stUser User;
	vector <stClient> vClients = LoadClientsDataFromFileToV(ClientsFileName);
	short Counter = 0;
	while (Counter != 3)
	{
		string AccountNumber = ReadClientAccountNumber();
		string PinCode = ReadText("Enter Pin : ");
			if (CheckLogingATM(AccountNumber, PinCode))
		{
			ATM();
			break;
		}
		if (Counter == 3)
		{
			cout << "\nYou've tried 3 times, try again later.\n\n";
		}
		Counter++;
	}
}


int main()
{

	LoginATM();
	return 0;
}






