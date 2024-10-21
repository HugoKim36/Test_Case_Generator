#include <iostream>
// #include <cmath>
#include <algorithm>

#include "helper_functions.hpp"
#include "string.hpp"

using namespace std;

// Test case generator functions
void generateNumbers();

int main(int argc, char** argv) {
	if (argc > 2) {
		cout << "USAGE: main.exe [test case type]\n";
		return 1;
	}
	// ofstream outFS("test_case.txt");
	if (argc == 1 || string(argv[1]) == "ints" || stoi(argv[1]) == 1) {
		generateNumbers();
	}
	else if (string(argv[1]) == "string" || stoi(argv[1]) == 2) {
		generateString();
	}
}

void generateNumbers() {
	ofstream outFS("test_case.txt");
	vector<int> params;
		// int num_values; // index 0
		// int max_value; // index 1
		// int min_value; // index 2
		// int grouping; // index 3
		// int sorting; // index 4
		ifstream inFS("test_case_numbers.config");
		string str, junk;
		while (inFS >> junk >> str) {
			if (isExponent(str)) {
				int exp = readExponent(str);
				params.push_back(exp);
			}
			else {
				params.push_back(stoi(str));
			}
		}
		vector<int> input_nums;
		for (int i = 0; i < params[0]; ++i) {
			int random = (rand() % (params[1] + 1));
			if (rand() % 2 == 0) { random *= -1; }
			if (random < params[2]) {
					random = params[2] + (rand() % (params[1] - params[2]));
			}
			input_nums.push_back(random);
		}
		
		if (params[4] == 1) {
			if (params[3] > 1) {
				auto it = input_nums.begin();
				auto it2 = it + (params[3]);
				while (it2 <= input_nums.end()) {
					std::sort(it, it2);
					it += params[3];
					it2 += params[3];
				}
			}
			else {
				std::sort(input_nums.begin(), input_nums.end());
			}
		}
		outFS << '[';
		int i = 0;
		for (; i < (input_nums.size()); ++i) {
			if (params[3] == 2) {
				if (i % 2 == 0) {
					outFS << '[' << input_nums[i] << ',';
				}
				else if (i % 2 == 1) {
					outFS << input_nums[i] << ']';
					if (i < (input_nums.size() - 1)) {
						outFS << ',';
					}
				}
			}
			else {
				outFS << input_nums[i];
				if (i < (input_nums.size() - 1)) {
						outFS << ',';
				}
			}
		}
		outFS << ']';
	if (params[2] >= 0) {
		// cout << "PrintBigNum test: ";
		cout << "Generated ";
		printBigNum((params[0] - 0)); 
		cout << " values in the range of\033[1;37m["  
			<< params[2] << "," << params[1] << "]\n"
			<< "\33[0m";
	}
	else {
		cout << "Generated "; 
		printBigNum((params[0] - 0));
		cout << " values in the range of \033[1;37m[" << (params[2]) << "," << params[1] << "]\n"
			<< "\33[0m";
	}
}