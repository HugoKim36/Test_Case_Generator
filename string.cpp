#include <iostream>
#include <cmath>
#include "string.hpp"

using namespace std;

void generateString() {
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

	bool spaces_allowed = params[SPACES_ALLOWED];
	bool nums_allowed = params[DIGITS_ALLOWED];
	bool symbols_allowed = params[SYMBOLS_ALLOWED];
	bool uppercase_allowed = params[UPPERCASE_ALLOWED];
	bool lowercase_allowed = params[LOWERCASE_ALLOWED];

	for (int i = 0; i <= len; ++i) {
		char character = random_char(spaces_allowed, nums_allowed, symbols_allowed);
		if (isalpha(character)) {
			set_capitalization(character, uppercase_allowed, lowercase_allowed);
		}
		str += character;
	}

	str += "\"";
	ofstream outFS("test_case.txt");
	outFS << str;
	cout << "Generated a string of length ";
	printBigNum((str.length() - 2));
	cout << " containing\033[1;37m ";
	if (!spaces_allowed && !nums_allowed && !symbols_allowed) {
		cout << "only ";
	}
	if (!uppercase_allowed) {
		cout << "lowercase ";
	}
	else if (!lowercase_allowed) {
		cout << "uppercase ";
	}
	cout << "English letters";
	if (spaces_allowed) {
		cout << " + spaces";
	}
	if (nums_allowed) {
		cout << " + digits";
	}
	if (symbols_allowed) {
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