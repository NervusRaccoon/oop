#include <iostream>
#include <fstream>
#include <string>

using namespace std;
	
string InvalidArgument = "Invalid argument count";
string NotExist = "File not exist";
string EmptyString = "String can`t be empty";
const int NumberArgs = 5;

string ReplaceString(const string& subject,
	const string& searchString, const string& replacementString)
{
	size_t pos = 0;
	string result;
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		result.append(subject, pos, foundPos - pos);
		if (foundPos != string::npos)
		{
			result.append(replacementString);
			pos = foundPos + searchString.length();
		}
		else
		{
			break;
		}
	}
	return result;
}

void CopyFileWithReplace(istream& input, ostream& output,
	const string& searchString, const string& replacementString)
{
	string line;

	while (getline(input, line))
	{
		string replStr = ReplaceString(line, searchString, replacementString);
		output << replStr << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != NumberArgs)
	{
		cout << InvalidArgument << endl;
		return 1;
	}

	ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		cout << NotExist << endl;
		return 1;
	}

	ofstream outputFile;
	outputFile.open(argv[2]);
	if (!outputFile.is_open())
	{
		cout << NotExist << endl;
		return 1;
	}

	string search = argv[3];
	if (search.empty())
	{
		cout << EmptyString << endl;
		return 1;
	}

	string replace = argv[4];
	if (replace.empty())
	{
		cout << EmptyString << endl;
		return 1;
	}

	CopyFileWithReplace(inputFile, outputFile, search, replace);
	outputFile.flush();

	return 0;
}