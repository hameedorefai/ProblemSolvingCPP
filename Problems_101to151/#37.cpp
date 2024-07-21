#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

string ReadString(string Message = "")
{
	string Words;
	(Message == "" ? cout << "Enter a String : \n" : cout << Message);
	getline(cin, Words);
	return Words;
}
char ReadChar(string Message = "")
{
	char Letter;
	(Message == "" ? cout << "Enter a char : \n" : cout << Message);
	cin >> Letter;
	return Letter;
}
void PrintEachWordInString(string S1)
{

	short pos = 0;
	string delim = " ";
	string Word = "";
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		Word = S1.substr(0, pos);

		if (Word != "")
			cout << Word << endl;

		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
		cout << S1 << endl;


}
short GetCountWordsInString(string S1)
{

	short Counter = 0;
	short Postion = 0;
	string Delim = " ";
	string Word = "";

	while ((Postion = S1.find(Delim)) != std::string::npos)
	{
		Word = S1.substr(0, Postion);
		if (Word != "")
			Counter++;
		S1.erase(0, Postion + Delim.length());
	}

	if (Word != "")
		Counter++;

	return Counter;
}
vector <string> SplitString(string S1, string Delim)
{
	vector <string> vWords;
	string Word;
	short Position = 0;
	
	while ((Position = S1.find(Delim)) != std::string::npos)
	{
		Word = S1.substr(0, Position);

		if (Word != "")
			vWords.push_back(Word);
	
		S1.erase(0, Position + Delim.length());
	}

	if (S1 != "")
		vWords.push_back(S1);

	return vWords;
}

int main()
{
	vector <string> vWords;
	vWords = SplitString(ReadString(), " ");

	cout << "Token : " << vWords.size()<< endl;
	for (string SingleWord : vWords)
	{
		cout << SingleWord << endl;
	}

	return 0;

}

