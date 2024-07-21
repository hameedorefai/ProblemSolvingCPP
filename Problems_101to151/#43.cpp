#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string Message = "")
{
	string S1;
	cout << "Enter your string? ";
	getline(cin, S1);
	return S1;
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

string LowerAllString(string S)
{
	for (short i = 0; i < S.length(); i++)
		S[i] = tolower(S[i]);
	return S;
}
string ReplaceWord(string S1, string ReplaceFrom, string RepalceTo, bool MatchCase = false)
{
	static vector <string> vS1 = SplitString(S1);
	string S2 = "";

	for (string Letter : vS1)
	{
		if (MatchCase)
		{
			if (Letter == ReplaceFrom)
				Letter = RepalceTo;
		}
		else
		{
			if (LowerAllString(Letter) == LowerAllString(ReplaceFrom))
				Letter = RepalceTo;
		}

		S2 += Letter + " ";
	}

	S2 = S2.substr(0, S2.length() - 1);

	return S2;
}


int main()
{

	string S1 = "Welcome to ramallah , Ramallah is a nice country.";
	string ReplaceFrom = "ramallah";
	string RepalceTo = "Palestine";
	
	
	cout << "\Original String : " << endl;
	cout << S1 << endl;

	cout << "\nReplace with match case : " << endl;
	cout << ReplaceWord(S1, ReplaceFrom, RepalceTo, true) << endl << endl;

	cout << "\nReplace without match case : " << endl;
	cout << ReplaceWord(S1, ReplaceFrom, RepalceTo) << endl << endl;
	return 0;
}