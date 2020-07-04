#include "stdafx.h"
#include "lambertian.h"
#include "specmath.h"

bool lambertian::scatter(const ray & r, hitRecord & data, vec3 & attenuation, ray & scattered) const
{
	scattered = ray(data.p, data.normal + specmath::random_inside_unit_sphere());
	attenuation = albedo;
	return true;
}

lambertian::lambertian(const vec3 a) : albedo(a)
{
}


lambertian::~lambertian()
{
}
