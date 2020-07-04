#include "stdafx.h"
#include "im.h"


im::im()
{
}

im::im(const int width, const int height)
{
	pixels[width * height];
}

vec3 im::pixel(int i, int j)
{
	return pixels[j * ];
}


im::~im()
{
}
