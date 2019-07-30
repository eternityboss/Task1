#pragma once
#include <vector>
#include "Point3f.h"
#include <algorithm>
using namespace std;
  
class ReadSTLFile
{
public:
	bool ReadFile(const char *cfilename);
	int Numtri();
	int Numtri1();
	vector<Point3f>& Pointlist();
private :
	vector<Point3f> pointlist;
	unsigned int unTriangles;
	unsigned int pointnum;
	bool ReadASCII(const char *cfilename);

	char *memwriter;
	int cpyint(const char *& p);
	float cpyfloat(const char *& p);
};
