#include <iostream>
#include <fstream>
#include <string>
#include "greetings.h"
using namespace std;

void check_for_oppen(string filename) {
	ifstream the_file(filename);
	while (!the_file.is_open()) {
		cout << "File_name is incorrect!!! No such file!\nInput Again: ";
		getline(cin, filename);
	}
	cout << "file "
}