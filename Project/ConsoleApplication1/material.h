#pragma once
#include "surf.h"
#include <math.h>
#include "light.h"
class material
{
public:
	virtual bool scatter(const ray &r, hitRecord & data, vec3 &attenuation, ray &scattered, const light* l) = 0;
	virtual vec3 lighting(const light *light, const hitRecord &data, const ray &r) const = 0;
	virtual float energyDraw() = 0;
	static vec3 reflect(const vec3 &in, const vec3 &normal);
	static bool refract(const vec3 &in, const vec3 &norm, float ni_over_nt, vec3 &refracted);
	static float schlick(float cosine, float ref_idx);
};

