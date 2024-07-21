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

int main()
{
	vector <string> Names = { "Ahmad","Mahmoud","Majd", "Ammar" };
	string Delim = ", ";
	
	cout << "\nVector before joinString : " << endl;
	for (string Name : Names)
	{
		cout << Name;

	}

	cout << endl << endl;

	cout << "\nVector after joinString : " << endl;
	cout << JoinString(Names, Delim) << endl;
	cout << endl << endl;

	cout << "\nVector after joinString (using &vector) : " << endl;
	for (string Name : Names)
	{
		cout << Name;
	}
	cout << endl << endl;

	return 0;
}

