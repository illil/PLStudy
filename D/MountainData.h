#pragma once
#include <string>

struct MountainData
{
public:
	
	MountainData(std::string name, int elevation)
	{
		_name = name;
		_elevation = elevation;
	}

	std::string _name;
	int _elevation;
};