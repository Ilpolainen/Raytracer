#pragma once
#include "material.h";
class lambertian : public material
{
public:
	virtual bool scatter(const ray & r, hitRecord & data, vec3 &attenuation, ray & scattered) const;
	vec3 albedo;
	lambertian(const vec3 a);
	~lambertian();
};

