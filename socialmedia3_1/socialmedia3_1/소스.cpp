#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char encrypt(char input);
//Precondition: inputfile을 한 글자씩 받아와 유니코드 값을 비교한다.
//Postcondition: 들어온 글자를 바꾼 값을 리턴한다.
char decrypt(char input);
//Precondition: inputfile을 한 글자씩 받아와 유니코드 값을 비교한다.
//Postcondition: 들어온 글자를 바꾼 값을 리턴한다.

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
			outputfile << encrypt(inputdata);	//outputfile에 문자를 넣은다.

		}
	}

	if (ans == 'D' || ans == 'd')
	{
		while (inputfile >> inputdata)
		{
			outputfile << decrypt(inputdata); //outputfile에 문자를 넣은다.
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