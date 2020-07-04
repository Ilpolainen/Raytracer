#pragma once
#include "ray.h"
#include "vec3.h"

class material;
struct hitRecord;

class surf
{
public:
	virtual bool hit(const ray &r,float min, float max, hitRecord &data) const;
};

struct hitRecord {
	float t;
	vec3 p;
	vec3 normal;
	material *mat;
};


