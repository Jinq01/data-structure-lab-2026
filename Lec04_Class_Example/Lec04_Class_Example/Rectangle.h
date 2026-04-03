#pragma once
#include <iostream>

class Rectagle
{
private:
	double width;
	double height;
public:
	Rectagle(double w, double h)
	{
		width = w;
		height = h;
	}

	double getArea()
	{
		return width * height;
	}

	double getPerimeter()
	{
		return (2 * width) + (2 * height); 
	}

	bool isSquare()
	{
		if (width == height)
			return 1;
		else
			return 0;
	}
};