#pragma once
#include "material.h"
#include "vec3.h"
#include "ray.h"
#include "light.h"
class dielectric : public material
{
public:
	virtual bool scatter(const ray &r, hitrecord & data, vec3 &attenuation, ray &scattered, const light *l) const override;
	dielectric(const vec3 &atte, float ri, float directLightAmount);
	~dielectric();
	dielectric() = default;
	float ref_idx;
	vec3 albedo;

	// Inherited via material
	virtual vec3 lighting(const light * light, const hitrecord & data, const ray & r) const override;

	// Inherited via material
	virtual float energyDraw() const override;
private:
	bool reflected; // for optimization
	float directLightAmount;
};


