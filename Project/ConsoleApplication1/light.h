#pragma once
#include "ray.h"
#include "vec3.h"
class light
{
public:
	virtual vec3 getColor(const vec3 &incoming) const = 0;
	virtual vec3 getColor() const = 0;
	virtual vec3 getDir(const vec3& point) const = 0;
};

