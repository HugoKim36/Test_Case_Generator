#include <iostream>
#include <cmath>
#include <unordered_map>
#include "string.hpp"

using namespace std;

void generateString(ostream& outFS) {
	ifstream inFS("test_case_string.config");
	vector<int> params;
	string input, junk;
	while (inFS >> junk >> input) {
		if (isExponent(input)) {
			int exp = readExponent(input);
			params.push_back(exp);
		}
		else { params.push_back(stoi(input)); }
	}

	if (params[MIN_LENGTH] < 0) { cout << "Error: string length must be >= 0\n"; }

	string str = "\"";
	int len = rand() % (params[MAX_LENGTH] - params[MIN_LENGTH] + 1) 
					   + params[MIN_LENGTH];

	unordered_map<int, bool> valid_chars = {
		{SPACES, params[SPACES]},
		{DIGITS, params[DIGITS]},
		{SYMBOLS, params[SYMBOLS]},
		{UPPERCASE, params[UPPERCASE]},
		{LOWERCASE, params[LOWERCASE]},
	};

	//bool spaces_allowed = params[SPACES];
	//bool nums_allowed = params[DIGITS];
	//bool symbols_allowed = params[SYMBOLS];
	//bool uppercase_allowed = params[UPPERCASE];
	//bool lowercase_allowed = params[LOWERCASE];

	for (int i = 0; i <= len; ++i) {
		char chr = random_char(valid_chars[SPACES], valid_chars[DIGITS], 
							   valid_chars[SYMBOLS]);
		if (isalpha(chr)) {
			set_capitalization(chr, valid_chars[UPPERCASE], valid_chars[LOWERCASE]);
		}
		str += chr;
	}

	str += "\"";
	// ofstream outFS("test_case.txt");
	outFS << str;
	cout << "Generated a string of length ";
	printBigNum((str.length() - 2));
	cout << " containing\033[1;37m ";
	if (!valid_chars[SPACES] && !valid_chars[DIGITS] && !valid_chars[SYMBOLS]) {
		cout << "only ";
	}
	if (!valid_chars[UPPERCASE]) {
		cout << "lowercase ";
	}
	else if (!valid_chars[LOWERCASE]) {
		cout << "uppercase ";
	}
	cout << "English letters";
	if (valid_chars[SPACES]) {
		cout << " + spaces";
	}
	if (valid_chars[DIGITS]) {
		cout << " + digits";
	}
	if (valid_chars[SYMBOLS]) {
		cout << " + symbols";
	}
	cout << '\n' << "\33[0m";
}

char random_char(bool spaces_allowed, bool nums_allowed, bool symbols_allowed) {
	char cch = 'a' + rand() % 26;
	char space = ' ';
	char num = '0' + rand() % 10;
	char symbol = '!' + rand() % 15; // generate ASCII char [33, 47]
	if (symbol == '\"' || symbol == '\'') {
		++symbol;
	}
	vector<char> chars = { cch };

	if (spaces_allowed) { chars.push_back(space); }
	if (nums_allowed) { chars.push_back(num); }
	if (symbols_allowed) { chars.push_back(symbol); }

	int idx = rand() % chars.size();
	return chars[idx];
}

void set_capitalization(char& letter, bool uppercase_allowed, bool lowercase_allowed) {
	assert(lowercase_allowed || uppercase_allowed);
	if (!lowercase_allowed) {
		letter = toupper(letter);
	}
	else if (lowercase_allowed && uppercase_allowed) {
		int num = rand() % 2;
		if (num) { // if num == 1, i.e., if num is odd
			letter = toupper(letter);
		}
	}
}