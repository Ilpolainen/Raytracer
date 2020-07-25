#include "stdafx.h"
#include "lambertian.h"
#include "specmath.h"
#include <cassert>

bool lambertian::scatter(const ray & r, hitRecord & data, vec3 & attenuation, ray & scattered, const light *l)
{
	scattered = ray(data.p, data.normal + specmath::random_inside_unit_sphere());
	attenuation = albedo;
	if (data.receiveDirectLight) {
		attenuation *= l->getLight(scattered.direction());
	}
	return true;
}

lambertian::lambertian(const vec3 a, float shininess, float specularRC) : albedo(a), shininess(shininess), specularAmount(specularRC)
{
}


lambertian::~lambertian()
{
}

vec3 lambertian::lighting(const light * l, const hitRecord & data, const ray & r) const
{
	float spec = blinnPhong(-r.direction(), l->getDir(data.p), data.normal, shininess);
	vec3 specular = l->getColor() * spec;
	return specular * specularAmount;
}

float lambertian::energyDraw()
{
	return 0.5f;
}
