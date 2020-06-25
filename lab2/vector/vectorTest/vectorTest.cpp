#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../../catch2/catch.hpp"
#include "../vector/vector.h"
using namespace std;

TEST_CASE("Testing with an empty vector")
{
	double maxNumber = 0;

	vector<double> numbers;
	vector<double> result;
	CountVector(numbers);
	CHECK(numbers == result);
}

TEST_CASE("Negative, positive numbers and zeros in the input")
{
	vector<double> numbers;
	vector<double> result;

	numbers = { 0, 0, 0, 0 };
	result = { 0, 0, 0, 0 };
	CountVector(numbers);
	CHECK(numbers == result);

	numbers = { 1, 2, 3, 4 };
	result = { 0.5, 1, 1.5, 2 };
	CountVector(numbers);
	CHECK(numbers == result);

	numbers = { -1, -9, -3, -14 };
	result = { 2, 18, 6, 28 };
	CountVector(numbers);
	CHECK(numbers == result);

	numbers = { 3, 3, 3, 3 };
	result = { 2, 2, 2, 2 };
	CountVector(numbers);
	CHECK(numbers == result);

	numbers = { -1.25, -2.33, 6.81, -9.99 };
	result = { (-1.25/(6.81/2)), (-2.33/(6.81/2)), (6.81/(6.81/2)), (-9.99/(6.81/2)) };
	CountVector(numbers);
	CHECK(numbers == result);
}