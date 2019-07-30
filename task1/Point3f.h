#pragma once
#include <d3d9.h>
#include <Windows.h>
//¶¥µã½á¹¹
struct Vertex
{
	Vertex(){}
	Vertex(double x, double y, double z)
	{
		_x = x; _y = y; _z = z;
	}
	double _x, _y, _z;
	static const DWORD FVF;
};

class Point3f
{
public:
	Point3f();
	Point3f(double _x, double _y, double _z);
	int SetParam(double _x, double _y, double _z);
	inline Vertex IVertex()
	{
		return Vertex(x, y, z);
	}

	double x, y, z;
};