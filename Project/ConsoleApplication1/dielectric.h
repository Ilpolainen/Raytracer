#pragma once
#include "material.h"
#include "vec3.h"
#include "ray.h"
#include "light.h"
class dielectric : public material
{
public:
	virtual bool scatter(const ray &r, hitRecord & data, vec3 &attenuation, ray &scattered, const light *l) const;
	dielectric(const vec3 &atte, float ri);
	~dielectric();
	float ref_idx;
	vec3 albedo;

	// Inherited via material
	virtual vec3 lighting(const light * light, const hitRecord & data, const ray & r) const override;
};


