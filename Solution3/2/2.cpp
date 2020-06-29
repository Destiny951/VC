// 2.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "2.h"
#include <math.h>

// 这是导出变量的一个示例
MY2_API int nMy2=0;

// 这是导出函数的一个示例。
MY2_API int fnMy2(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 2.h
CMy2::CMy2()
{
	return;
}

MY2_API int factorial(int n)
{
	if (n < 10)
	{
		for (int i = n - 1; i > 1; i--)
		{
			n = n*i;
		}
	}
	return n;
}

float FAC ::convert(float deg)
{
	float rad_deg = 45.0 / atan(1.0);
	float rad = deg / rad_deg;
	return rad;
}