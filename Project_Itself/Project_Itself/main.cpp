#include <iostream>
#include <cstdint>
#include <string>
#include "matadata.h"
#include "extention.h"
#include "greetings.h"
using namespace std;

int main(int argc, char *argv[]) {
	/*
	string input_file = argv[1];
	string output_file = argv[2];
	float times = stof(argv[3]);
	cout << input_file << endl << output_file << endl << times << endl;
	check_for_oppen(&input_file);
	*/

	string input_file = "-.wav";
	string output_file = "result.wav";
	float times = -1;

	wild_nixon_metadata(input_file, output_file, times);
	linear_interpolation(times, input_file, output_file);
	//linear_interpolation();



	system("pause");
	return 0; 
}