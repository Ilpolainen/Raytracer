#pragma once
#include "material.h"
#include "vec3.h"
#include "light.h"
#include <algorithm>
class metal : public material
{
public:
	vec3 albedo;
	float fuzz;
	virtual bool scatter(const ray & r, hitRecord & data, vec3 &attenuation, ray & scattered, const light *l);
	metal(const vec3 a, float f, float shininess, float specularAmount, float diffuse_amount);
	~metal();

	// Inherited via material
	virtual vec3 lighting(const light * light, const hitRecord & data, const ray & r) const override;
private:
	float shininess;
	float specularAmount;
	float diffuseAmount;
	// Inherited via material
	virtual float energyDraw() override;
};

