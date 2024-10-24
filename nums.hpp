#ifndef NUMS_HPP
#define NUMS_HPP

#include <algorithm>
#include "helper_functions.hpp"
#include <iostream>
// #include <fstream>

enum NumsParameters {
	NUM_VALUES = 0,
	MAX_VALUE = 1,
	MIN_VALUE = 2,
	GROUPING = 3,
	SORTING = 4,
	UNIQUE_NUMS = 5,
};

void generateNumbers(std::ostream& outFS);

void removeDuplicates(std::vector<int>& nums);

#endif
