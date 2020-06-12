#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
		output << ReplaceString(line, searchString, replacementString) << "\n";
	}
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid argument count\n"
			<< "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
		return 1;

	ofstream outputFile;
	outputFile.open(argv[2]);
	if (!outputFile.is_open())
		return 1;

	string search = argv[3];
	if (search.empty())
		return 1;
	string replace = argv[4];
	if (replace.empty())
		return 1;

	CopyFileWithReplace(inputFile, outputFile, search, replace);
	outputFile.flush();

	return 0;
}