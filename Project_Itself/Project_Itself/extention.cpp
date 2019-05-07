#include <iostream>
#include <fstream>
#include "extention.h"
using namespace std;

void simple_expansion(int times, string original_file, string result_file) {
	ifstream input_file(original_file, ios::binary);
	ofstream output_file(result_file, ios::binary | ios::app);

	input_file.seekg(44, ios::beg);
	char *buff = new char[16];

	while (!input_file.eof()){
		input_file.read(buff, 16);
		for (int i = 0; i < times; i++) {
			output_file.write(buff, 16);
		}
	}

	input_file.close();
	output_file.close();
}
