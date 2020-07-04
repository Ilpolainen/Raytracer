#pragma once
#include "material.h"
#include "vec3.h"
#include "ray.h"
class dielectric : public material
{
public:
	virtual bool scatter(const ray &r, hitRecord & data, vec3 &attenuation, ray &scattered) const;
	dielectric(const vec3 &atte, float ri);
	~dielectric();
	float ref_idx;
	vec3 albedo;
};


