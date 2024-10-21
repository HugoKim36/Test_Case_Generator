#include <iostream>
#include <fstream>

#include "helper_functions.hpp"
#include "nums.hpp"
#include "string.hpp"

using namespace std;

int main(int argc, char** argv) {
	if (argc > 2) {
		cout << "USAGE: main.exe [test case type]\n";
		return 1;
	}

	ofstream outFS("test_case.txt");
	if (!outFS.is_open()) {
		cout << "ERROR: output file failed to open.\n";
		return 1;
	}

	if (argc == 1 || string(argv[1]) == "ints" || stoi(argv[1]) == 1) {
		generateNumbers(outFS);
	}
	else if (string(argv[1]) == "string" || stoi(argv[1]) == 2) {
		generateString(outFS);
	}
}