#include "stdafx.h"
#include "metal.h"
#include "specmath.h"
#include "material.h"
#include "light.h"
#include <cassert>

bool metal::scatter(const ray & r, hitrecord & data, vec3 & attenuation, ray & scattered, const light *l) const
{
	vec3 v = r.rawDirection().normalized();
	vec3 n = data.normal;
	vec3 reflected = material::reflect(v, n);
	if (fuzz > 0) {
		scattered = ray(data.p, reflected + fuzz * specmath::random_inside_unit_sphere());
	}
	else {
		scattered = ray(data.p, reflected);
	}
	
	attenuation = albedo;
	return (scattered.rawDirection() * data.normal > 0);
}

metal::metal(const vec3 a,float f, float shininess, float specularAmount) : shininess(shininess), specularAmount(specularAmount)
{
	albedo = a;
	if (f < 0) {
		f = 0;
	}
	if (f > 1) {
		f = 1;
	}
	fuzz = f;
}

metal::~metal()
{
}

vec3 metal::lighting(const light * l, const hitrecord & data, const ray & r) const
{
	float spec = blinnPhong(-r.direction(), l->getDir(data.p), data.normal, shininess);
	vec3 specular = l->getColor() * spec;
	return specular * specularAmount;
}

float metal::energyDraw() const
{
	return std::max(1.0f - fuzz , 0.7f);
}
