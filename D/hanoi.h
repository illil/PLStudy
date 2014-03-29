#pragma once

enum Tower
{
	source = 1,
	temp = 2,
	dest = 3
};

extern void HanoiResursive(Tower source, Tower temp, Tower dest, int i);
extern void HanoiNonResursive(Tower source, Tower temp, Tower dest, int i);

struct HanoiData
{
	HanoiData()
	{
	}

	HanoiData(Tower source, Tower temp, Tower dest, int i)
	{
		height = i;
		this->source = source;
		this->temp = temp;
		this->dest = dest;
	}

	int height;
	Tower source;
	Tower temp;
	Tower dest;
};

