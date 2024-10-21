#ifndef STRING_HPP
#define STRING_HPP

#include <fstream>
#include <vector>
#include <cassert>
#include "helper_functions.hpp"

void generateString();

char random_char(bool spaces_allowed, bool nums_allowed, bool symbols_allowed);

void set_capitalization(char& letter, bool uppercase_allowed, bool lowercase_allowed);

enum StringArguments {
  MAX_LENGTH   = 0,
  MIN_LENGTH   = 1,
  UPPERCASE_ALLOWED    = 2,
  LOWERCASE_ALLOWED = 3,
  SPACES_ALLOWED = 4,
  DIGITS_ALLOWED = 5,
  SYMBOLS_ALLOWED = 6
};

#endif