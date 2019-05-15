#include <iostream>
#include <fstream>
#include <cstdint>
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

void wild_nixon_metadata(string input_file_name, string output_file_name, float times) {
	ifstream input_file(input_file_name, ios::binary);
	ofstream output_file(output_file_name, ios::trunc);

	char*buff = new char[40];
	input_file.read(buff, 40);
	output_file.write(buff, 40);

	delete[] buff;
	int32_t int_buff;
	input_file.read((char*)&int_buff, sizeof(int_buff));
	int num = int_buff;
	num *= times;
	int_buff = num;

	output_file.write((char*)&int_buff, sizeof(int_buff));

	input_file.close();
	output_file.close();
}