//Encryptor Copyright (C) 2019 David Badiei
#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

void encrypt();
void checkforillegalchar();
void decrypt();
void checkforillegalletter();
void useAgain();
string userInput;
string encryptedStr;
char list[27] = {'1','1','1','1','1','2','2','2','2','2','3','3','3','3','3','4','4','4','4','4','5','5','5','5','5','9','7'};
char list2[27] = { '1','2','3','4','5','1','2','3','4','5','1','2','3','4','5','1','2','3','4','5','1','2','3','4','5','3','8'};
char list3[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
int val, val1;
char tmp, tmp2;

int main()
{
	char userChoice;
	cout << "Encryptor Copyright (C) 2019 David Badiei \nEnter 1 for encrypt \nEnter 2 for decrypt" << endl;
	cin >> userChoice;
	if (userChoice == '1')
	{
		encrypt();
	}
	else if (userChoice == '2')
	{
		decrypt();
	}
	else
	{
		exit(0);
	}
}

void encrypt()
{
	cout << "Enter string to encrypt: ";
	cin.ignore();
	getline(cin, userInput);
	checkforillegalchar();
	for (int i = 0; i < userInput.size(); i++)
	{
		if (userInput.at(i) >= 0x41 && userInput.at(i) <= 0x5A)
		{
			val = userInput.at(i) - 0x41;
			encryptedStr.push_back(list[val]);
			encryptedStr.push_back(list2[val]);
			encryptedStr.push_back(' ');
		}
		else if (userInput.at(i) >= 0x61 && userInput.at(i) <= 0x7A)
		{
			val = userInput.at(i) - 0x61;
			encryptedStr.push_back(list[val]);
			encryptedStr.push_back(list2[val]);
			encryptedStr.push_back(' ');
		}
		else if (userInput.at(i) == 0x20)
		{
			val = 0x1B;
			encryptedStr.push_back('7');
			encryptedStr.push_back('8');
			encryptedStr.push_back(' ');
		}
	}
	cout << "Answer: " << encryptedStr << endl;
	useAgain();
}

void checkforillegalchar()
{
	for (int i = 0; i < userInput.size(); i++)
	{
		if (isalpha(userInput.at(i)) || isspace(userInput.at(i))){}
		else
		{
			cout << "Error: Only letters or spaces permitted" << endl;
			system("pause");
			exit(0);
		}
	}
}

void decrypt()
{
	cout << "Enter values to decrypt (with spaces between each number combination): ";
	cin.ignore();
	getline(cin, userInput);
	checkforillegalletter();
	for (int i = 0; i < userInput.size(); i+=3)
	{
		tmp = userInput.at(i);
		tmp2 = userInput.at(i + 1);
		if (tmp == '1')
		{
			if (tmp2 == '1')
			{
				encryptedStr.push_back('a');
			}
			else if (tmp2 == '2')
			{
				encryptedStr.push_back('b');
			}
			else if (tmp2 == '3')
			{
				encryptedStr.push_back('c');
			}
			else if (tmp2 == '4')
			{
				encryptedStr.push_back('d');
			}
			else if (tmp2 == '5')
			{
				encryptedStr.push_back('e');
			}
		}
		else if (tmp == '2')
		{
			if (tmp2 == '1')
			{
				encryptedStr.push_back('f');
			}
			else if (tmp2 == '2')
			{
				encryptedStr.push_back('g');
			}
			else if (tmp2 == '3')
			{
				encryptedStr.push_back('h');
			}
			else if (tmp2 == '4')
			{
				encryptedStr.push_back('i');
			}
			else if (tmp2 == '5')
			{
				encryptedStr.push_back('j');
			}
		}
		else if (tmp == '3')
		{
			if (tmp2 == '1')
			{
				encryptedStr.push_back('k');
			}
			else if (tmp2 == '2')
			{
				encryptedStr.push_back('l');
			}
			else if (tmp2 == '3')
			{
				encryptedStr.push_back('m');
			}
			else if (tmp2 == '4')
			{
				encryptedStr.push_back('n');
			}
			else if (tmp2 == '5')
			{
				encryptedStr.push_back('o');
			}
		}
		else if (tmp == '4')
		{
			if (tmp2 == '1')
			{
				encryptedStr.push_back('p');
			}
			else if (tmp2 == '2')
			{
				encryptedStr.push_back('q');
			}
			else if (tmp2 == '3')
			{
				encryptedStr.push_back('r');
			}
			else if (tmp2 == '4')
			{
				encryptedStr.push_back('s');
			}
			else if (tmp2 == '5')
			{
				encryptedStr.push_back('t');
			}
		}
		else if (tmp == '5')
		{
			if (tmp2 == '1')
			{
				encryptedStr.push_back('u');
			}
			else if (tmp2 == '2')
			{
				encryptedStr.push_back('v');
			}
			else if (tmp2 == '3')
			{
				encryptedStr.push_back('w');
			}
			else if (tmp2 == '4')
			{
				encryptedStr.push_back('x');
			}
			else if (tmp2 == '5')
			{
				encryptedStr.push_back('y');
			}
		}
		else if (tmp == '9')
		{
			encryptedStr.push_back('z');
		}
		else
		{
			encryptedStr.push_back(' ');
		}
	}
	cout << "Answer: " << encryptedStr << endl;
	useAgain();
}

void checkforillegalletter()
{
	for (int i = 0; i < userInput.size(); i++)
	{
		if (isdigit(userInput.at(i)) || isspace(userInput.at(i))){}
		else
		{
			cout << "Error: Only numbers permitted with no spaces" << endl;
			system("pause");
			exit(0);
		}
	}
}

void useAgain()
{
	char userChoice = 0;
	cout << "Do you want to use this program again? 1.Yes 2.No";
	cin >> userChoice;
	if (userChoice == '1')
	{
		userInput = "";
		encryptedStr = "";
		val = 0;
		val1 = 0;
		tmp = 0;
		tmp2 = 0;
		main();
	}
	else
	{
		exit(0);
	}
}
