#pragma once
#include "material.h"
#include "vec3.h"
#include "light.h"
#include <algorithm>
class metal : public material
{
public:
	metal() = default;
	vec3 albedo;
	float fuzz;
	virtual bool scatter(const ray & r, hitrecord & data, vec3 &attenuation, ray & scattered, const light *l) const override;
	metal(const vec3 a, float f, float shininess, float specularAmount);
	~metal();

	// Inherited via material
	virtual vec3 lighting(const light * light, const hitrecord & data, const ray & r) const override;
private:
	float shininess;
	float specularAmount;
	// Inherited via material
	virtual float energyDraw() const override;
};

