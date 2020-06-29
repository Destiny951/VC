#include"stdafx.h"
#include "1.h"
#include<math.h>

int factorial(int n)
{
	if (n < 10)
	{
		for (int i = n - 1; i > 1; i--)
		{
			n = n*i;
		}
		return n;
	}
	else return 0;
}

float FAC::convert(float deg)
{
	float  rad_to_deg = 45.0 / atan(1.0);
	float rad = deg / rad_to_deg;
	return rad;
}