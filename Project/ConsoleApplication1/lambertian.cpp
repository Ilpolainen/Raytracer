#include "stdafx.h"
#include "lambertian.h"
#include "specmath.h"
#include <cassert>

bool lambertian::scatter(const ray & r, hitRecord & data, vec3 & attenuation, ray & scattered, const light *l)
{
	scattered = ray(data.p, data.normal + specmath::random_inside_unit_sphere());
	attenuation = albedo;
	if (data.receiveDirectLight) {
		attenuation *= l->getColor(scattered.direction());
	}
	return true;
}

lambertian::lambertian(const vec3 a, float shininess, float specularRC, float diffuseRC) : albedo(a), shininess(shininess), specularAmount(specularRC), diffuseAmount(diffuseRC)
{
}


lambertian::~lambertian()
{
}

vec3 lambertian::lighting(const light * l, const hitRecord & data, const ray & r) const
{
	vec3 lambertian = albedo.had(l->getColor(r.direction()));
	if (specularAmount < 0.5f) {
		return lambertian;
	}
	vec3 H = (l->getDir(data.p) - r.direction()).normalized();
	float NdotH = data.normal * H;
	float spec = pow(std::max(NdotH, 0.0f), shininess);
	vec3 specular = l->getColor() * spec;
	return diffuseAmount * lambertian + specular * specularAmount;
}

float lambertian::energyDraw()
{
	return 0.5f;
}
