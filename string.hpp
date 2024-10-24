#ifndef STRING_HPP
#define STRING_HPP

#include <fstream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include "helper_functions.hpp"

void generateStringTests(std::ostream& outFS);

std::string generateString(const std::vector<int> params);

char random_char(bool spaces_allowed, bool nums_allowed, bool symbols_allowed);

void set_capitalization(char& letter, bool uppercase_allowed, bool lowercase_allowed);

void printStringType(std::unordered_map<int, bool>& valid_chars);

enum StringParameters {
  MAX_LENGTH   = 0,
  MIN_LENGTH   = 1,
  UPPERCASE    = 2,
  LOWERCASE = 3,
  SPACES = 4,
  DIGITS = 5,
  SYMBOLS = 6,
  NUM_STRINGS = 7,
};

#endif