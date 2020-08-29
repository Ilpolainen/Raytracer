#pragma once
#include <math.h>
#include <algorithm>
#include "light.h"
#include "hitrecord.h"
class material
{
public:
	std::string name;
	virtual ~material() = default;
	virtual bool scatter(const ray &r, hitrecord & data, vec3 &attenuation, ray &scattered, const light* l) const = 0;
	virtual vec3 lighting(const light *light, const hitrecord &data, const ray &r) const { return vec3(0, 0, 0); }
	virtual float energyDraw() const { return 0; }
	static vec3 reflect(const vec3 &in, const vec3 &normal);
	static bool refract(const vec3 &in, const vec3 &norm, float ni_over_nt, vec3 &refracted);
	static float schlick(float cosine, float ref_idx);
	static float blinnPhong(const vec3 viewerDir, const vec3 lightSourceDir, const vec3 normal, float specCoeff);

};

