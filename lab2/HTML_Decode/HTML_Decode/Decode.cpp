#include "htmlDecode.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

const vector <pair<string, string>> library =
{
	{"\"", "&quot;"},
	{"\'", "&apos;"},
	{"<", "&lt;"},
	{">", "&gt;"},
	{"&", "&amp;"}
};

string ReplaceString(string& subject, const string& searchString, const string& replacementString)
{
    string result = "";
    if (subject.empty())
    {
        return result;
    }
    size_t pos = 0;
    size_t replacementPos = 0;
    while (replacementPos != string::npos)
    {
        replacementPos = subject.find(replacementString, pos);
        if (replacementPos != string::npos)
        {
            result.append(subject, pos, replacementPos - pos);
            pos = replacementPos + replacementString.size();
            result.append(searchString);
        }
        else
        {
            result.append(subject, pos, subject.size());
            break;
        }
    }
    return result;
}

string HtmlDecode(const string& htmlCode)
{
    string decode = htmlCode;
    for (auto& i: library)
    {
        decode = ReplaceString(decode, i.first, i.second);
    }
    return decode;
}