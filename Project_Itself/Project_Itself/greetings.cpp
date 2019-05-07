#include <iostream>
#include <fstream>
#include <string>
#include "greetings.h"
using namespace std;

void check_for_oppen(string *filename) {
	ifstream the_file(*filename);
	while (!the_file.is_open()) {
		the_file.close();
		cout << "File_name is incorrect!!! No such file!\nInput Again: ";
		getline(cin, *filename);
		cin.ignore();
		the_file.open(*filename);
	}
	cout << "File is oppened Succesfuly!!!\n";
}
