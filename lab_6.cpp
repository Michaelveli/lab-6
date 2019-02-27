#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string  password;
	string password_2; // compare against 1st password for step 8
	bool valid_password = false;



	cout << "Password Requirements" << endl
		<< "1.Password must be at least 8 characters." << endl
		<< "2.Password must contain at least one number." << endl
		<< "3.Password must contain at least one special character." << endl
		<< "4.Password must contain at least one letter of the alphabet." << endl
		<< "5.Password must contain at least one uppercase letter." << endl
		<< "6.Password must contain at least one lowercase letter." << endl
		<< "7.Password must not contain a whitespace character such as a space, a tap, a newline character." << endl
		<< "8.If the user modifies the old password, the new password must not be the same as the previous password" << endl << endl;
	cout << "Enter a New Password: ";
	getline(cin, password);

	while (!valid_password) {
		bool valid_password = true;


		// 1. password length 
		if (password.length() < 8) {
			cout << "Password must be at least 8 characters. \n";
			valid_password = false;
		}

		// 2. checks for number
		int index = password.find_first_of("0123456789");
		if (index == -1) {
			cout << "Password must include a number \n";
			valid_password = false;
		}

		//3. checks for special character
		bool special_character = false;
		for (char c : password) {
			if (ispunct(c)) {
				special_character = true;
				
			}
			else {
				cout << "Password must include a special character. \n";
				valid_password = false;
				
			}

		}

		//4. checks for letters
		bool password_letters = false;
		for (char c : password) {
			if (isalpha(c)) {
				password_letters = true;

			}
			else {
				cout << "Password must include letters. \n";
				valid_password = false;
			}
			
		}

		//5. checks for uppercase
		bool uppercase_letters = false;
		for (char c : password) {
			if (isupper(c)) {
				uppercase_letters = true;

			}
			else {
				cout << "Password must include an uppercase letter. \n";
				valid_password = false;
			}

		}

		//6. checks for lowercase
		bool lowercase_letters = false;
		for (char c : password) {
			if (islower(c)) {
				lowercase_letters = true;

			}
			else {
				cout << "Password must contain lowercase letters. \n";
				valid_password = false;
			}
			
		}
		//7. checks for white space, tap, or newline
		bool whitespace = true;
		for (char c : password) {
			if (isspace(c)) {
				whitespace = false;
			}
			else {
				cout << "Password must not contain whitespace. \n";
				valid_password = false;
			}
			
		}

		if (!valid_password) {
			cout << "Enter another password. \n";
			cin >> password;
		}
		
		break;
		
	} // while closing bracket

	cout << "Your password is " << password << endl;

} // main closing bracket
