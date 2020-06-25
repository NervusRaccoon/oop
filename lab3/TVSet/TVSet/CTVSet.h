#pragma once

class CTVSet
{
public:
	void turnOn();
	void turnOff();
	void selectChannel(const int channel);
	int getChannel() const;
	bool isTurnedOn() const;
	bool channelRange(const int channel) const;

private:
	int m_currentChannel = 1;
	bool m_isTurnedOn = false;
	const int m_minChannel = 1;
	const int m_maxChannel = 99;
};