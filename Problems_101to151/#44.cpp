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

bool IsPunct(char Letter)
{
	return (Letter > 32 && Letter < 48);
}
string RemovePauncuations(string S)
{
	string S2 = "";


	for (short i = 0; i < S.length(); i++)
	{
		if (!IsPunct(S[i]))
		{
			S2 += S[i];
		}
	}
	return S2;
}

int main()
{

	string S1 = "Welcome to Ramallah, It's a nice country.";
	 
	cout << "\nOriginal String  :\n";
	cout << S1 << endl;
	
	cout << "\nPauncuations Removed :\n";
	cout << RemovePauncuations(S1) << endl;
	return 0;
}