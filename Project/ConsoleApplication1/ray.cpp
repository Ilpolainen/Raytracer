#include "stdafx.h"
#include "ray.h"
#include "vec3.h"

ray::ray(const vec3& stp, const vec3& dir)
{
	A = stp;
	B = dir;
}

ray::ray()
{
}


ray::~ray()
{
}

vec3 ray::direction() const
{
	return B;
}

vec3 ray::origin() const
{
	return A;
}

vec3 ray::p(float t) const
{
	return A + t * B;
}
