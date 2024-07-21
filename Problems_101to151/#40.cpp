#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> &vS1, string Delim = " ")
{	
	short vSize = vS1.size()-1;
	string NewString = "";

	for (string&S1 : vS1)
	{
		if (vSize--)
			S1 += Delim;

		NewString += S1;
	}
	return NewString;
}
string JoinString(string arrString[100], short Length, string Delim = " ")
{
	string S1 = "";
	for (short i = 0; i < Length; i++)
	{
		S1 += arrString[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}
void PrintVector(vector <string> vS1)
{
	for (string Name : vS1)
	{
		cout << Name;

	}
}

int main()
{
	vector <string> vNames = { "Ahmad","Mahmoud","Majd", "Ammar" };
	 string arrNames[] = {"Ahmad","Mahmoud","Majd", "Ammar"};
	 short Length = 4;
	 string Delim = ", ";
	

	cout << "\nVector after join : " << endl;
	JoinString(vNames, Delim);
	PrintVector(vNames);
	cout << endl << endl;

	cout << "\Array after join : " << endl;
	cout << JoinString(arrNames, Length, Delim) << endl;
	cout << endl << endl;

	return 0;
}

