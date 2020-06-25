#include <iostream>
#include <vector>  
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "vector.h"
using namespace std;

int main()
{
	vector<double> numbers = GetVector();

	CountVector(numbers);
	sort(numbers.begin(), numbers.end());
	PrintVector(numbers);

	return 0;
}