#pragma once
#include "surf.h"
#include <math.h>
class material
{
public:
	virtual bool scatter(const ray &r, hitRecord & data, vec3 &attenuation, ray &scattered) const;
	static vec3 reflect(const vec3 &in, const vec3 &normal);
	static bool refract(const vec3 &in, const vec3 &norm, float ni_over_nt, vec3 &refracted);
	static float schlick(float cosine, float ref_idx);
	material();
	~material();
};

