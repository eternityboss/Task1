// task1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Point3f.h"
#include <algorithm>
#include "task.h"
#include <string>
#include <sstream>

using namespace std;

bool ReadSTLFile::ReadFile(const char *cfilename)
{
	FILE *pfile;
	long  size;
	char *buffer;
	size_t result;

	
	//打开文件
	fopen_s(&pfile, cfilename, "rb");
	if (pfile == NULL) 
	{
		fputs("file error", stderr);
		exit(1);

	}
	//获取文件大小
	fseek(pfile, 0, SEEK_END);
	size = ftell(pfile);
	
	rewind(pfile);
	//为文件分配内存
	buffer =(char*) malloc(sizeof(char)*size);
	if (buffer == NULL)
	{
		fputs("memory error", stderr);
		exit(2);
	}
	//将文件拷贝到buffer中
	result = fread(buffer, 1, size, pfile);
	if (result != size)
	{
		fputs("reading error 12312313", stderr);
		exit(3);
	}
	//关闭文件，释放内存
	fclose(pfile);

	ios::sync_with_stdio(false);
	ReadASCII(buffer);
	ios::sync_with_stdio(true);
	free(buffer);
	return true;
}
const bool unique_finder(const Point3f& first, const Point3f& second)
 {
	
	
		return (first.x == second.x&&first.y == second.y&&first.z == second.z);
	
	    
 }
const bool sort_finder(const Point3f &a, const Point3f &b)
{
	return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y)) || ((a.x == b.x) && (a.y == b.y) && (a.z < b.z));
}
bool ReadSTLFile::ReadASCII(const char *buffer)
{
	unTriangles = 0;//面片数
	pointnum = 0;//节点数
	double x, y, z;
	int i;
	string name, useless;
	stringstream ss(buffer);
	ss.get();
	getline(ss, useless);
	//
	/*ss >> useless;
	//if (useless != "facet")
		
	getline(ss, useless);
	getline(ss, useless);
	for (i = 0; i < 3; i++)
	{
		ss >> useless >> x >> y >> z;
		pointnum++;
		pointlist.push_back(Point3f(x, y, z));
		
		
	}
	unTriangles++;
	getline(ss, useless);
	getline(ss, useless);
	getline(ss, useless);
	*/
	do {
		ss >> useless;
		if (useless != "facet")
			break;
		getline(ss, useless);
		getline(ss, useless);
		for (i = 0; i < 3; i++)
		{
			ss >> useless >> x >> y >> z;
			
			pointlist.push_back(Point3f(x, y, z));
			//结点数据去重
			
		//	pointnum++;
		//	pointlist.push_back(Point3f(x, y, z));
			/*for(vector<int>::size_type j = 0; j < pointlist.size();j++)
			{
				//测试cout << pointlist[j].x<<" "<< pointlist[j].y<< " "<<pointlist[j].z << endl;
				if (pointlist[j].x == x) {
					if (pointlist[j].y == y) 
					{
						if (pointlist[j].z== z)
						{
							break;
						}
						else
						{
							pointnum++;
							pointlist.push_back(Point3f(x, y, z));
						}
					}
					else
					{
						pointnum++;
						pointlist.push_back(Point3f(x, y, z));
					}
				}
				else 
				{
					pointnum++;
					pointlist.push_back(Point3f(x, y, z));
				}
				//cout << pointlist[j].x<<" "<< pointlist[j].y<< " "<<pointlist[j].z << endl;
				
			} */


			
			
		}
		unTriangles++;
		getline(ss, useless);
		getline(ss, useless);
		getline(ss, useless);
	} while (1);
	
	sort(pointlist.begin(),pointlist.end(),sort_finder);	
	pointlist.erase(unique(pointlist.begin(), pointlist.end(), unique_finder), pointlist.end());
	for (vector<int>::size_type j = 0; j < pointlist.size(); j++)
	{
		pointnum++;
	}
	return true;
}

//获取面片数
int ReadSTLFile::Numtri()
{
	return unTriangles;
}
//获取节点数
 int ReadSTLFile::Numtri1()
{
	return pointnum;
}

int main()
{
	
	ReadSTLFile RC;
	
	
	
	RC.ReadFile("test.stl");

	cout <<"面片数："<< RC.Numtri() << endl;
	cout<<"未去重的节点数：" << RC.Numtri1() << endl;



	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
