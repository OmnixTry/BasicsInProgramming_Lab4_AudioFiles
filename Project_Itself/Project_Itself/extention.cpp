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

void linear_interpolation(float times, string original_file, string result_file) {
	// has to be changed
	// test version
	ifstream input(original_file, ios::binary);
	ofstream output(result_file, ios::app);

	char *buff0 = new char[44];
	input.read(buff0, 44);
	//output.write(buff0, 44);

	char buff;
	int aaa;
	float prev_coordinate = 0;
	float current_coordinate = 0;
	int last_read = 0;
	char prev_num;
	char next_num;
	float move = 1.0 / times;

	unsigned short fc_buff;
	unsigned short fc_prev;
	unsigned short fc_next;

	input.read(&buff, sizeof(buff));
	output.write(&buff, sizeof(buff));
	prev_num = buff;
	input.read(&buff, sizeof(buff));
	next_num = buff;
	while (!input.eof())
	{
		current_coordinate += move;
		if (prev_coordinate != (int)current_coordinate) {
			prev_num = next_num;
			prev_coordinate++;
			last_read++;
			input.read(&next_num, sizeof(buff));
		}
		
		fc_prev = (int)prev_num > 0 ? (int)prev_num : prev_num + 256;
		fc_next = (int)next_num > 0 ? (int)next_num : next_num + 256;

		fc_buff = fc_prev + (current_coordinate - prev_coordinate)*(fc_next - fc_prev);
		buff = fc_buff;

		output.write(&buff, sizeof(buff));
	}

	output.close();
}

void linear_interpolation() {
	// has to be changed
	// test version
	ifstream input("-.wav", ios::binary);
	ofstream output("result.wav", ios::trunc);

	char *buff0 = new char[44];
	input.read(buff0, 44);
	output.write(buff0, 44);

	float times = 1.5;
	char buff;
	int aaa;
	float prev_coordinate = 0;
	float current_coordinate = 0;
	int last_read = 0;
	char prev_num;
	char next_num;
	float move = 1.0 / times;

	unsigned short fc_buff;
	unsigned short fc_prev;
	unsigned short fc_next;

	input.read(&buff, sizeof(buff));
	output.write(&buff, sizeof(buff));
	prev_num = buff;
	input.read(&buff, sizeof(buff));
	next_num = buff;
	while (!input.eof())
	{
		current_coordinate += move;
		if (prev_coordinate != (int)current_coordinate) {
			prev_num = next_num;
			prev_coordinate++;
			last_read++;
			input.read(&next_num, sizeof(buff));
		}

		fc_prev = (int)prev_num > 0 ? (int)prev_num : prev_num + 256;
		fc_next = (int)next_num > 0 ? (int)next_num : next_num + 256;

		fc_buff = fc_prev + (current_coordinate - prev_coordinate)*(fc_next - fc_prev);
		buff = fc_buff;

		output.write(&buff, sizeof(buff));
	}

	output.close();
}

void linear_interpolation_minus(float times, string original_file, string result_file) {
	ifstream input(original_file, ios::binary);
	ofstream output_prev("prev.wav", ios::app);

	char *buff0 = new char[44];
	input.read(buff0, 44);
	//output_prev.write(buff0, 44);

	char buff;
	int aaa;
	float prev_coordinate = 0;
	float current_coordinate = 0;
	int last_read = 0;
	char prev_num;
	char next_num;
	float move = 1.0 / abs(times);

	unsigned short fc_buff;
	unsigned short fc_prev;
	unsigned short fc_next;

	input.read(&buff, sizeof(buff));
	output_prev.write(&buff, sizeof(buff));
	prev_num = buff;
	input.read(&buff, sizeof(buff));
	next_num = buff;
	while (!input.eof())
	{
		current_coordinate += move;
		if (prev_coordinate != (int)current_coordinate) {
			prev_num = next_num;
			prev_coordinate++;
			last_read++;
			input.read(&next_num, sizeof(buff));
		}

		fc_prev = (int)prev_num > 0 ? (int)prev_num : prev_num + 256;
		fc_next = (int)next_num > 0 ? (int)next_num : next_num + 256;

		fc_buff = fc_prev + (current_coordinate - prev_coordinate)*(fc_next - fc_prev);
		buff = fc_buff;

		output_prev.write(&buff, sizeof(buff));
	}

	output_prev.close();

	ofstream output(result_file, ios::app);
	ifstream to_reverse("prev.wav", ios::binary);
	to_reverse.seekg(-1, to_reverse.end);
	int stopposition = to_reverse.tellg();
	for (int i = 0; i <= stopposition; i++) {
		to_reverse.read(&buff, sizeof(buff));
		output.write(&buff, sizeof(buff));
		//cout << setw(4) << (int)buff;
		to_reverse.seekg(-2, ios::cur);
	}
	output.close();
	to_reverse.close();
}




