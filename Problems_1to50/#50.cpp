#include <iostream>
using namespace std;

//bool check3tries(intoBankAccount&);
//void checkPIN(int, intoBankAccount&);
//int readPIN(intoBankAccount&);

struct intoBankAccount {
	int PIN = 1234;
	long balance = 7500;
	int tries = 0;
	int hasReadPIN;

};

int readPIN(intoBankAccount&user) {
	int PIN;
	cout << "Enter PIN : ";
	cin >> PIN;
	user.tries += 1;
	return PIN;
}

void checkPIN(int PIN, intoBankAccount&user) {
	
		if (PIN == user.PIN)
			cout << "Balance is : " << user.balance << endl;
		else 
			cout << "Wrong PIN" << endl;
}
bool tried3Times(intoBankAccount&user) {
	if (user.tries == 3&& user.hasReadPIN!=user.PIN) {
		cout << "Card locked" << endl;
		return true;
	}
	else
		return false;
	}
void loginToBankAccount(intoBankAccount&user1) {
	do {
		user1.hasReadPIN = readPIN(user1);
		checkPIN(user1.hasReadPIN, user1);

	} while (tried3Times(user1) == false && user1.hasReadPIN != user1.PIN);
}
int main() {

		intoBankAccount user1;
		loginToBankAccount(user1);

		return 0;
	}