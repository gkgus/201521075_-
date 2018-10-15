#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char encrypt(char input);
//Precondition: inputfile�� �� ���ھ� �޾ƿ� �����ڵ� ���� ���Ѵ�.
//Postcondition: ���� ���ڸ� �ٲ� ���� �����Ѵ�.
char decrypt(char input);
//Precondition: inputfile�� �� ���ھ� �޾ƿ� �����ڵ� ���� ���Ѵ�.
//Postcondition: ���� ���ڸ� �ٲ� ���� �����Ѵ�.

int main()
{
	ifstream inputfile;
	ofstream outputfile;
	char ans;
	char infilename[12];
	char outfilename[12];
	char inputdata;
	cout << "Please enter either E)ncryption or D)ecryption." << endl;
	cin >> ans;

	cout << "Enter an input file name: " << endl;
	cin >> infilename;
	inputfile.open(infilename);
	if (inputfile.fail())
	{
		cout << "Input file opening failed" << endl;
		cout << "Aborting program" << endl;
		exit(1);
	}

	cout << "Enter an output file name: " << endl;
	cin >> outfilename;
	outputfile.open(outfilename);
	if (outputfile.fail())
	{
		cout << "Output file opening failed" << endl;
		cout << "Aborting program" << endl;
		exit(1);
	}
	else 
	{ 
		cout << "Output file is created" << endl;
	}

	if (ans == 'E' || ans == 'e')	
	{
		while (inputfile >> inputdata)
		{
			outputfile << encrypt(inputdata);	//outputfile�� ���ڸ� ������.

		}
	}

	if (ans == 'D' || ans == 'd')
	{
		while (inputfile >> inputdata)
		{
			outputfile << decrypt(inputdata); //outputfile�� ���ڸ� ������.
		}
		
	}
	
	inputfile.close();
	outputfile.close();
}

char encrypt(char input)
{
	char tempinput = input;

	if (input == 90)
	{
		tempinput = 65;
	}
	else if (input == 122)
	{
		tempinput = 97;
	}
	else
	{
		tempinput += 1;
	}
	return tempinput;
}

char decrypt(char input)
{
	char tempinput = input;
	
	if (input == 65)
	{
		tempinput = 90;
	}
	else if (input == 97)
	{
		tempinput = 122;
	}
	else
	{
		tempinput -= 1;
	}
	return tempinput;
}