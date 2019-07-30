#pragma once
#include "pch.h"
#include "Point3f.h"
Point3f::Point3f() :x(0), y(0), z(0)
{

}
Point3f::Point3f(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}
int Point3f::SetParam(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
	return 0;

}