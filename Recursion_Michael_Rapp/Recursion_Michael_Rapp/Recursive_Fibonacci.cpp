/*
	CS 2420 Utah Valley University
	Recursive_Fibonacci.cpp
	Purpose: Takes input from data file and outputs the number in the 
			 position of the fibonacci sequence of the number input.
	Author: Michael Rapp
	Date: 8/28/2016
*/

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int fibonacci(int num);
bool openFile(ifstream &inFile);

int main() {

	int num;
	string filePath;
	ifstream inFile;

	if (openFile(inFile)) {
		cout << "The file outputs:" << endl;

		while (!inFile.eof()){
			inFile >> num;
			cout << num << " ---> " << fibonacci(num) << endl;
		}
	}
	else {
		cout << "File not found! Program terminates" << endl;
	}

	cin.ignore();
	cin.get();
	return 0;
}

int fibonacci(int num) {
	/*
		This function outputs the number in the fibonacci sequence at position "num"
	*/

	if (num <= 0) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}
	else if (num >= 2) {
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
}

bool openFile(ifstream &inFile) {
	/*
		This function takes the filepath entered by the user and esures the file
		exists. If file is opened returns true, else false.
	*/

	string filePath;

	cout << "Please enter the file path including the file extension ";
	cin >> filePath;

	inFile.open(filePath);

	if (!inFile) {
		return false;
	}
	else {
		return true;
	}
}
