#pragma once
#include "vec3.h"
#include "surf.h"
class sphere : public surf
{
public:
	sphere(vec3 in_o, float in_r, material *mat);
	~sphere();
	virtual bool hit(const ray &r,float min, float max, hitRecord &data) const;
	vec3 origin() const;
	float radius() const;

private:
	vec3 orig;
	float rad;
	material *mat;
};

