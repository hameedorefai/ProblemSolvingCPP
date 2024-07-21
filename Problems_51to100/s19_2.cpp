#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumberInRange(int From, int To) {
	int RandomNumber = (rand() % (To - From + 1))+ From;
	return RandomNumber;
}
int main() {
	srand((unsigned)time(NULL));
	cout << RandomNumberInRange(90, 100) << endl;

	return 0;
}