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
		cout << "The file is found." << endl;
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
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}
	else if (num >= 2) {
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
	else {
		return 0;
	}
}

bool openFile(ifstream &inFile) {
	string filePath;

	cout << "Please enter the file path ";
	cin >> filePath;

	inFile.open(filePath);

	if (!inFile) {
		return false;
	}
	else {
		return true;
	}
}
