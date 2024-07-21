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
vector <string> SplitString(string S1, string Delim)
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
string ReverseWordInString(string S1)
{
	vector <string> vS1;
	string S2 = "";
	vS1 = SplitString(S1, " ");

	vector <string>::iterator iter = vS1.end();

	while (iter != vS1.begin())
	{
		iter--;
		
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1);
	return S2;

}


int main()
{
	cout << ReverseWordInString(ReadString());

	return 0;
}