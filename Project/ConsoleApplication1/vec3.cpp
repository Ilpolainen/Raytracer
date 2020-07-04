#include "stdafx.h"
#include "vec3.h"

vec3::vec3()
{
}

vec3::~vec3()
{
}

vec3::vec3(const int i, const int j, const int k)
{
	e[0] = float(i); e[1] = float(j), e[2] = float(k);
}

vec3::vec3(const float x, const float y, const float z)
{
	e[0] = x; e[1] = y; e[2] = z;
}

vec3::vec3(const double x, const double y, const double z)
{
	e[0] = float(x); e[1] = float(y), e[2] = float(z);
}


