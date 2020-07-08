#include "stdafx.h"
#include "ray.h"
#include "vec3.h"

ray::ray(const vec3& orig, const vec3& dir) : rawDir(dir), orig(orig)
{
}

ray::ray()
{
}


ray::~ray()
{
}

vec3 ray::rawDirection() const
{
	return rawDir;
}

vec3 ray::direction() const
{
	return rawDir.normalized();
}

vec3 ray::origin() const
{
	return orig;
}

vec3 ray::p(float t) const
{
	return orig + t * rawDir;
}
