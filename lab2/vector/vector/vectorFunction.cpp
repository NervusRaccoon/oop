#include <iostream>
#include <vector>  
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

vector<double> GetVector()
{
	return vector<double>(istream_iterator<double>(cin), (istream_iterator<double>()));
}

void PrintVector(const vector<double>& numbers)
{
	cout << setprecision(3);
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
}

void CountVector(vector<double>& numbers)
{
	if (!numbers.empty())
	{
		double halfMax = *max_element(numbers.begin(), numbers.end()) / 2;
		if (halfMax)
		{
			transform(numbers.begin(), numbers.end(), numbers.begin(), [&halfMax](double current)
			{
				return (current / halfMax);
			});
		}
	}

}