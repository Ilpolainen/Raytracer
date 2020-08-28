#pragma once
#include "material.h"
#include "light.h"
class lambertian : public material
{
public:
	virtual bool scatter(const ray & r, hitrecord & data, vec3 &attenuation, ray & scattered, const light *l) const override;
	vec3 albedo;
	lambertian(const vec3 a,float shininess, float specularRC);
	~lambertian();
	lambertian() = default;
	// Inherited via material
	virtual vec3 lighting(const light * light, const hitrecord & data, const ray & r) const override;
private:
	float shininess;
	float specularAmount;
	float diffuseAmount;

	// Inherited via material
	virtual float energyDraw() const override;
};

