#pragma once
#include <string>

struct MountainData
{
public:
	
	MountainData()
	{

	}

	MountainData(std::string name, int elevation)
		:_name(name), _elevation(elevation)
	{
	}

	std::string _name;
	int _elevation;	
};

struct MountainComparer
{
public:
	bool operator ()(const MountainData &a, const MountainData &b)
	{
		return a._elevation > b._elevation;
	}
};