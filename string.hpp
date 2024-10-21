#ifndef STRING_HPP
#define STRING_HPP

#include <fstream>
#include <vector>
#include <cassert>
#include "helper_functions.hpp"

void generateString(std::ostream& outFS);

char random_char(bool spaces_allowed, bool nums_allowed, bool symbols_allowed);

void set_capitalization(char& letter, bool uppercase_allowed, bool lowercase_allowed);

enum StringParameters {
  MAX_LENGTH   = 0,
  MIN_LENGTH   = 1,
  UPPERCASE    = 2,
  LOWERCASE = 3,
  SPACES = 4,
  DIGITS = 5,
  SYMBOLS = 6
};

#endif