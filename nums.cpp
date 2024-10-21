#include <iostream>
#include <fstream>
#include "nums.hpp"

using namespace std;

void generateNumbers(ostream& outFS) {
	// ofstream outFS("test_case.txt");
	vector<int> params;
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
	for (int i = 0; i < params[NUM_VALUES]; ++i) {
		int random = (rand() % (params[MAX_VALUE] + 1));
		if (rand() % 2 == 0) { random *= -1; }
		if (random < params[MIN_VALUE]) {
			random = params[MIN_VALUE] 
				   + (rand() % (params[MAX_VALUE] - params[MIN_VALUE]));
		}
		input_nums.push_back(random);
	}

	if (params[SORTING]) {
		if (params[GROUPING] > 1) {
			auto it = input_nums.begin();
			auto it2 = it + (params[GROUPING]);
			while (it2 <= input_nums.end()) {
				std::sort(it, it2);
				it += params[GROUPING];
				it2 += params[GROUPING];
			}
		}
		else {
			std::sort(input_nums.begin(), input_nums.end());
		}
	}
	outFS << '[';
	int i = 0;
	for (; i < (input_nums.size()); ++i) {
		if (params[GROUPING] == 2) {
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
	if (params[MIN_VALUE] >= 0) {
		// cout << "PrintBigNum test: ";
		cout << "Generated ";
		printBigNum((params[NUM_VALUES] - 0));
		cout << " values in the range of\033[1;37m["
			<< params[MIN_VALUE] << "," << params[MAX_VALUE] << "]\n"
			<< "\33[0m";
	}
	else {
		cout << "Generated ";
		printBigNum((params[NUM_VALUES] - 0));
		cout << " values in the range of \033[1;37m[" << (params[MIN_VALUE]) << "," 
			 << params[MAX_VALUE] << "]\n"
			 << "\33[0m";
	}
}