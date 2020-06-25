#include "CTVSet.h"

void CTVSet::turnOn()
{
	m_isTurnedOn = true;
}

void CTVSet::turnOff()
{
	m_isTurnedOn = false;
}

bool CTVSet::channelRange(const int channel) const
{
	return m_minChannel <= channel && channel <= m_maxChannel;
}

void CTVSet::selectChannel(const int channel)
{
	if (channelRange(channel) && m_isTurnedOn)
	{
		m_currentChannel = channel;
	}
}

int CTVSet::getChannel() const
{
	if (m_isTurnedOn)
	{
		return m_currentChannel;
	}
	return 0;
}

bool CTVSet::isTurnedOn() const
{
	return m_isTurnedOn;
}