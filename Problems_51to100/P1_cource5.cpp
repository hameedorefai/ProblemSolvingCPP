#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;


int main() {

	string S1 = "My Name is Mahmoud Refai";

	cout << S1 << endl;

	cout << S1.length() << endl;
	
	cout << S1.at(3) << endl;

	S1.append("The professional");
	cout << S1 << endl;

	S1.insert(11, "Mister ");

	cout << S1 << endl;

	cout << S1.substr(19, 7) << endl;

	S1.push_back('X');
	cout << S1 << endl;

	S1.pop_back();
	cout << S1 << endl;

	cout << S1.find("Mister") << endl;

	cout << S1.find("ali") << endl;

	S1.clear();



	return 0;
}