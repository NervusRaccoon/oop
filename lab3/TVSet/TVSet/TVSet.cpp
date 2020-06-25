#include <iostream>
#include "CTVSet.h"

using namespace std;

string turned = "TV is turned ";
string on = "on";
string off = "off";
string alreadyOff = "TV is already off";
string err = "Error. ";
string outOfRange = "Channel is out of allow range";
string selected = "Selected channel ";
string errInput = "Enter an existing channel in range from 1 to 99";
string errCommand = "Unknown command, use: TurnOn, TurnOff, SelectChannel <channel number>, Info";
string currChannel = "Current channel ";

void turnOn(CTVSet& tv, ostream& output)
{
	if (!tv.isTurnedOn())
	{
		tv.turnOn();
		output << turned << on << endl;
	}
	else
	{
		output << turned << off << endl;
	}
}

void turnOff(CTVSet& tv, ostream& output)
{
	if (tv.isTurnedOn())
	{
		tv.turnOff();
		output << turned << off << endl;
	}
	else
	{
		output << alreadyOff << endl;
	}
}

void selectChannel(CTVSet& tv, istream& input, ostream& output)
{
	int channel;
	if (input >> channel)
	{
		if (!tv.isTurnedOn())
		{
			output << err << turned << off << endl;
			return;
		}
		else if (!tv.channelRange(channel))
		{
			output << err << outOfRange << endl;
			return;
		}
		tv.selectChannel(channel);
		output << selected << channel << endl;
	}
	else
	{
		output << err << errInput << endl;
		input.clear();
	}
}

void printInfo(CTVSet& tv, ostream& output)
{
	output << turned << (tv.isTurnedOn() ? on : off) << endl;
	output << currChannel << tv.getChannel() << endl;
}

void TVController(istream& input, ostream& output)
{
	CTVSet tv;
	string command;
	while (cin >> command)
	{
		if (command == "TurnOn")
		{
			turnOn(tv, output);
		}
		else if (command == "TurnOff")
		{
			turnOff(tv, output);
		}
		else if (command == "SelectChannel")
		{
			selectChannel(tv, input, output);
		}
		else if (command == "Info")
		{
			printInfo(tv, output);
		}
		else
		{
			output << err << errCommand << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	TVController(cin, cout);
}