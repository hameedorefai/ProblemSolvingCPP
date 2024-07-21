#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void PrintLettersFromAAAtoZZZ() {
	for (int i = 65; i <=90; i++) {
		for (int j = 65; j <= 90; j++) {
			for (int v = 65; v <= 90; v++) {
				cout << char(i) << char(j) << char(v);
				cout << endl;
			}
		}
		
	}
}

int main() {
	PrintLettersFromAAAtoZZZ();
	return 0;
}