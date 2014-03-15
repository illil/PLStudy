#pragma once

enum Tower
{
	source = 1,
	temp = 2,
	dest = 3
};

extern void Hanoi(Tower source, Tower temp, Tower dest, int i);