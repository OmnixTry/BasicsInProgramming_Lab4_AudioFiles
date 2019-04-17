#include <iostream>
#include <cstdint>
#include <string>
#include "greetings.h"
using namespace std;

int main(int argc, char *argv[]) {
	string input_file = argv[1];
	string output_file = argv[2];
	float times = stof(argv[3]);
	cout << input_file << endl << output_file << endl << times << endl;
	check_for_oppen(&input_file);





	system("pause");
	return 0; 
}