#include "helper_functions.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int readExponent(string str) {
	bool contains_factor = false;
	for (auto& i : str) {
		if (i == '*') {
			contains_factor = true;
			break;
		}
	}
	if (!contains_factor) {
		string str_copy = str;
		string::iterator it = str_copy.begin();
		while (it < str_copy.end()) {
			if (*it == '^') {
				*it = ' ';
			}
			++it;
		}
		istringstream inSS(str_copy);
		int base, exponent;
		inSS >> base >> exponent;
		int num = pow(base, exponent);
		if (base < 0 && !(num < 0)) {
			num *= -1;
		}
		return num;
	}
	string str_copy = str;
	string::iterator it = str_copy.begin();
	while (it < str_copy.end()) {
		if (*it == '^' || *it == '*') {
			*it = ' ';
		}
		++it;
	}
	istringstream inSS(str_copy);
	int factor, base, exponent;
	inSS >> factor >> base >> exponent;
	// int exp_term = pow(base, exponent);
	return (pow(base, exponent) * factor);
}

bool isExponent(const string& str) {
	auto it = str.begin();
	while (it < str.end()) {
		if (*it++ == '^') {
			return true;
		}
		// ++it;
	}
	return false;
}

void printBigNum(int num) {
	if (abs(num) < 1000) {
		cout << "\033[1;37m" << num << "\33[0m";
		return;
	}
	string str = to_string(num);
	auto it = str.begin();
	cout << "\033[1;37m";
	int first_comma = (str.size() % 3 == 0) ? 3 : (str.size() % 3);
	while ((it - str.begin()) < (first_comma)) {
		cout << *it++;
	}
	cout << ',';
	int n = 1;
	while (it < str.end()) {
		cout << *it++;
		if ((n % 3) == 0 && (str.end() - it) > 1) {
			cout << ',';
		}
		++n;
	}
	cout << "\33[0m";
}