#pragma once
#include "material.h"
#include "vec3.h"
#include "light.h"
class metal : public material
{
public:
	vec3 albedo;
	float fuzz;
	virtual bool scatter(const ray & r, hitRecord & data, vec3 &attenuation, ray & scattered, const light *l) const;
	metal(const vec3 a, float f);
	~metal();

	// Inherited via material
	virtual vec3 lighting(const light * light, const hitRecord & data, const ray & r) const override;
};

