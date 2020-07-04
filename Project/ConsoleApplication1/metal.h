#pragma once
#include "material.h"
#include "vec3.h"
class metal : public material
{
public:
	vec3 albedo;
	float fuzz;
	virtual bool scatter(const ray & r, hitRecord & data, vec3 &attenuation, ray & scattered) const;
	metal(const vec3 a, float f);
	~metal();
};

