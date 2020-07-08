#pragma once
#include "material.h";
#include "light.h"
class lambertian : public material
{
public:
	virtual bool scatter(const ray & r, hitRecord & data, vec3 &attenuation, ray & scattered, const light *l) const;
	vec3 albedo;
	lambertian(const vec3 a);
	~lambertian();

	// Inherited via material
	virtual vec3 lighting(const light * light, const hitRecord & data, const ray & r) const override;
};

