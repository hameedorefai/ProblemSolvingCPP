#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ReadText(string Message) {
	string Input;
	cout << Message << endl;
	getline(cin, Input);
	return Input;
}
string EncryptText(string Text,const short EncryptionKey) {


	for (int i = 0; i <= Text.length(); i++) {
		Text[i] =  char((int)Text[i]+ EncryptionKey);

	}
	cout << "Encrypt Text : " << Text << endl;
	return Text;
}
string DecryptText(string Text, const short EncryptionKey) {

	for (int i = 0; i <Text.length(); i++) {
		Text[i] = char((int)Text[i] - EncryptionKey);

	}
	cout << "Decrypt Text : " << Text << endl;
	return Text;

}

int main() {
	const short EncryptionKey = 2;

	DecryptText(EncryptText(ReadText("Enter a Text :"), EncryptionKey), EncryptionKey);
	return 0;
}