#pragma once
#include <iostream>

class Figure
{
public:
	Figure()
	{
		Test();
	}
	virtual ~Figure()
	{
	}

	virtual float GetArea() = 0;

	void Test()
	{
		GetArea();
	}
private:

protected:

	int a;

};

class Rectangle : public Figure
{
public:
	Rectangle(float x, float y, float width, float height)
	{

		_x = x;
		_y = y;
		_width = width;
		_height = height;
	}

	 ~Rectangle()
	{
		std::cout << "!!";
	}

	virtual float GetArea()
	{
		return _width * _height;
	}

private:
	float _x;
	float _y;
	float _width;
	float _height;
};

class Circle : public Figure
{

};