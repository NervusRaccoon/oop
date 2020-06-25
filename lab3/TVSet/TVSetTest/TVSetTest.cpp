#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../TVSet/CTVSet.h"

TEST_CASE("When you TurnOn should give channel 1")
{
	CTVSet tv;
	tv.turnOn();
	CHECK(tv.getChannel() == 1);
}

TEST_CASE("When you TurnOff should give channel 0")
{
	CTVSet tv;
	tv.turnOff();
	CHECK(tv.getChannel() == 0);
}

TEST_CASE("Select right channel")
{
	CTVSet tv;
	tv.turnOn();
	tv.selectChannel(99);
	CHECK(tv.getChannel() == 99);
}

TEST_CASE("When you TurnOn, SelectChannel, TurnOff and TurnOn should give previous channel")
{
	CTVSet tv;
	tv.turnOn();
	tv.selectChannel(40);
	tv.turnOff();
	tv.turnOn();
	CHECK(tv.getChannel() == 40);
}

TEST_CASE("When you TurnOff and try SelectChannel should give 0")
{
	CTVSet tv;
	tv.turnOff();
	tv.selectChannel(33);
	CHECK(tv.getChannel() == 0);
}

TEST_CASE("When you try to select nonexistent channel should give previous channel")
{
	CTVSet tv;
	tv.turnOn();
	tv.selectChannel(10);
	tv.selectChannel(100);
	CHECK(tv.getChannel() == 10);
}