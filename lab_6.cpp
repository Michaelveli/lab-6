// lab_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
		for (char c : password){
			if (ispunct(c)) {
				special_character = true;
				break;
			}
			else {
				cout << "Password must include a special character. \n";
				valid_password = false;
				break;
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
				break;
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
				break;
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
				break;
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
				break;
			}

			if (!valid_password) {
				cout << "Please try again. \n";
			
			}
			break;

			cout << "Your password is " << password << endl;
		} // while closing bracket

	cout << "Your password is " << password << endl;

} // main closing bracket


	




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
