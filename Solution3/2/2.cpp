// 2.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "2.h"
#include <math.h>

// ���ǵ���������һ��ʾ��
MY2_API int nMy2=0;

// ���ǵ���������һ��ʾ����
MY2_API int fnMy2(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� 2.h
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