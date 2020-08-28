#pragma once
#include "ray.h"
#include "vec3.h"
#include "hitrecord.h"


class surf
{
public:
	//virtual surf & operator=(surf&& other) noexcept { return other; }
	virtual bool hit(const ray &r,float min, float max, hitrecord &data) const = 0;
};



