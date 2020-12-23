#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>

using std::cout;
using std::cin;;
using std::endl;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x, int y)
		:xpos(x), ypos(y)
	{
	};
	void ShowPointInfo()
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point cir1;
	int radius;
public:
	Circle(int a, int b, int c)
		:cir1(a, b),radius(c)
	{
	}
	void ShowR()
	{
		cir1.ShowPointInfo();
		cout << "¹ÝÁö¸§ :" << radius << endl;
	}
};

class Ring
{
private:
	Circle cir1;
	Circle cir2;
public:
	Ring(int a,int b,int c,int d,int e,int f)
		:cir1(a,b,c),cir2(d,e,f)
	{}
	void ShowShow()
	{
		cir1.ShowR();
		cir2.ShowR();
	}
};

int main()
{
	Ring Cir1(5, 10, 30,6,20,50);
	Cir1.ShowShow();

	return 0;
}