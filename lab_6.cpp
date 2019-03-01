#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string password;
string password_2;



void user_menu() {
	cout << "Password Requirements" << endl
		<< "1.Password must be at least 8 characters." << endl
		<< "2.Password must contain at least one number." << endl
		<< "3.Password must contain at least one special character." << endl
		<< "4.Password must contain at least one letter of the alphabet." << endl
		<< "5.Password must contain at least one uppercase letter." << endl
		<< "6.Password must contain at least one lowercase letter." << endl
		<< "7.Password must not contain a whitespace character such as a space, a tap, a newline character." << endl
		<< "8.If the user modifies the old password, the new password must not be the same as the previous password" << endl
		<< "Enter a Password: " << endl;
}

void password_main() {
	getline(cin, password);

	bool valid_password = false;
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

		}

		//4. checks for letters
		bool password_letters = false;
		for (char c : password) {
			if (isalpha(c)) {
				password_letters = true;
			}

		}

		//5. checks for uppercase
		bool uppercase_letters = false;
		for (char c : password) {
			if (isupper(c)) {
				uppercase_letters = true;

			}

		}

		//6. checks for lowercase
		bool lowercase_letters = false;
		for (char c : password) {
			if (islower(c)) {
				lowercase_letters = true;
			}

		}
		//7. checks for white space, tap, or newline
		bool whitespace = true;
		for (char c : password) {
			if (isspace(c)) {
				whitespace = false;

			}

		}

		if (!password_letters) {
			cout << "Password must include letters. \n";
			valid_password = false;
		}
		if (!special_character) {
			cout << "Password must include a special character. \n";
			valid_password = false;
		}

		if (!uppercase_letters) {
			cout << "Password must include an uppercase letter. \n";
			valid_password = false;
		}

		if (!lowercase_letters) {
			cout << "Password must contain lowercase letters. \n";
			valid_password = false;
		}

		if (whitespace) {
			cout << "Password must not contain a whitespace. \n";
			valid_password = false;
		}


		if (valid_password = false) {
			cout << "Enter another password. \n";
			password_main();
		}

		if (password == password_2) {
			cout << "If you're seeing this you entered the same password. Enter a new password." << endl;
			password_main();
		}


	}// while closing bracket
}
//closing menu

void user_menu2() {
	char user_input;

	cout << "Your password is " << password << endl << endl;

	cout << "Enter 1 to create another password, or 2 to exit. \n";
	cin >> user_input;

	if (user_input == '1') {
		cout << "Enter old password for confirmation.";
		getline(cin, password_2);

		// fix this line, it doesnt compare and it throws the entire loop off
		if (password != password_2) {
			cout << "Password does not match old password. Try again. \n";
			user_menu2();
		}
		  else {
			password_main();
		    
		}

	}

	if (user_input == '2') {
		cout << "Goodbye! ";
	}

}

int main()
{
	user_menu();
	password_main();
	user_menu2();
	return 0;
}
// main closing br
