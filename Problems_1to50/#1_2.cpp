#include <iostream>
using namespace std;

void PrintTableHeader() {
	cout << endl << "\t\t\t Multiplication Table From 1 To 10\n" << endl;
	cout << "\t  1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << endl;
	cout << "___________________________________________________________________________________" << endl;

}
string ColumSperator(int i) {
	if (i < 10)
		return "   | ";
	else if (i < 100)
		return "  | ";
	else
		return " | ";
}
void PrintMultiplicationTable() {
	PrintTableHeader();

	for (int i = 1; i <= 10; i++) {
		cout << i << ColumSperator(i)<<"\t";
		for (int j = 1; j <= 10; j++) {
			cout << i * j << "\t";

		}
		cout << endl;
	}
	
}

int main(){
	PrintMultiplicationTable();


	return 0;
}