#include "stdafx.h"
#include "metal.h"
#include "specmath.h"
#include "material.h"
#include "light.h"

bool metal::scatter(const ray & r, hitRecord & data, vec3 & attenuation, ray & scattered, const light *l) const
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

metal::metal(const vec3 a,float f)
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

vec3 metal::lighting(const light * l, const hitRecord & data, const ray & r) const
{
	return l->getColor(data.normal);
}
