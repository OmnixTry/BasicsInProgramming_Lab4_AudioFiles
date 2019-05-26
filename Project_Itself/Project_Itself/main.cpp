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
	float times = -1.5;

	wild_nixon_metadata(input_file, output_file, abs(times));
	wild_nixon_metadata(input_file, "prev.wav", abs(times));
	if (times > 0) linear_interpolation(times, input_file, output_file);
	else if (times < 0) linear_interpolation_minus(times, input_file, output_file);
	//linear_interpolation();



	system("pause");
	return 0; 
}