// GCDandLCM.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Greatest Common Divisor and Lowest Common Multiple algorithm

#include <algorithm>
#include "GCD.h"
#include <iostream>
#include "LCM.h"
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

typedef int long long ill;

//function prints the instruction set
void instructions()
{
	cout << "Instructions:\n";
	cout << "-Use command 'gcd' to search Greatest Common Divisor.\n";
	cout << "-Use command 'lcm' to search Lowest Common Multiple.\n";
	cout << "-Use command 'help' to display this set of instructions.\n";
	cout << "-Use command 'exit' to terminate.\n\n";
}

string getInput()
{
	cout << "Enter numbers seperated by comma (,) : ";

	char lines[1024];

	std::cin.ignore(1024, '\n');
	std::cin.getline(lines, 1024);

	string line = lines;
	
	return line;
}

//predicate return false if whitespace found
bool isWhitespace(char ch)
{
	if (ch == ' ')
		return false;
	return true;
}

//function returns string without namespaces
string removeWhitespace(string str)
{
	string::iterator it = std::stable_partition(str.begin(), str.end(), isWhitespace);
	str.erase(it, str.end());
	return str;
}

//function returns vector with numbers extracted from string
vector<ill> extractNumsFromLine(string str)
{
	str = removeWhitespace(str);
	vector<ill> v;
	v.reserve(10);

	//begin extracting loop
	while (str.length() > 0)
	{
		ill index = 0;
		string temp;

		//extract number
		while (str[index] != ',' && index < str.length())
		{
			if (!isdigit(str[index]))	//if not digit, we don't care
			{
				str.erase(str.begin() + index);	//erase
			}
			temp += str[index];
			index++;
		}
		str.erase(0, index + 1);	//erase
		ill num = std::stoi(temp);	//convert to integer

		v.push_back(num);
	}

	v.shrink_to_fit();
	return v;
}




//function gets all the inputs
int getInput(string& command)
{
	//get command string
	cout << "Write command: ";
	cin >> command;

	std::transform(command.begin(), command.end(), command.begin(), ::toupper);	//transform command line to uppercase
	//gcd
	if (command == "GCD")	//if command is 'gcd'
	{
		string line = getInput();
		vector<ill> numbers = extractNumsFromLine(line);

		try 
		{
			ill gcd = GCD(numbers);
			cout << "GCD = " << gcd << "\n";
		}
		catch (const char* msg)
		{
			cout << msg;
		}
	}

	//lcm
	if (command == "LCM")
	{
		string line = getInput();
		vector<ill> numbers = extractNumsFromLine(line);

		try
		{
			ill lcm = LCM(numbers);
			cout << "LCM = " << lcm << "\n";
		}
		catch (const char* msg)
		{
			cout << msg;
		}
	}

	if (command == "EXIT")
		return 0;

	if (command == "HELP")
		instructions();
	//end of 'input gcd'
	return 1;
}

int main()
{
	cout << "An application that is able to find Greatest Common Divisor and/or Lowest Common Multiple.\n";

	//instruction
	instructions();
	
	//variables
	string command;

	//get input
	while (1)
	{
		int val = getInput(command);
		if (val == 0)
			return 0;
	}
	
}


