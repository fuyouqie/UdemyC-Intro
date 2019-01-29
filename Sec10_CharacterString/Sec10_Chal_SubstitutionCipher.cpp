#include <iostream>
#include <string>

using namespace std;

int main()
{
	string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

	string msg;
	cout << "Enter your secret: ";
	getline(cin, msg);

	cout << "*******Encrypting secret" << endl;
	string encrypted;
	for (auto c : msg)
	{
		size_t position = alphabet.find(c);
		if (position != string::npos)
			encrypted += key.at(position);
		else
			encrypted += c;
	}
	cout << "Encrypted message: " << encrypted << endl;


	cout << "*******Decrypting secret" << endl;
	string decrypted;
	for (auto c : encrypted)
	{
		size_t position = key.find(c);
		if (position != string::npos)
			decrypted += alphabet.at(position);
		else
			decrypted += c;
	}
	cout << "Decrypted message: " << decrypted << endl;

	return 0;
}