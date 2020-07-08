#include "stdafx.h"
#include "lambertian.h"
#include "specmath.h"

bool lambertian::scatter(const ray & r, hitRecord & data, vec3 & attenuation, ray & scattered, const light *l) const
{
	scattered = ray(data.p, data.normal + specmath::random_inside_unit_sphere());
	attenuation = albedo;
	if (data.receiveDirectLight) {
		attenuation *= l->getColor(scattered.direction());
	}
	return true;
}

lambertian::lambertian(const vec3 a) : albedo(a)
{
}


lambertian::~lambertian()
{
}

vec3 lambertian::lighting(const light * l, const hitRecord & data, const ray & r) const
{
	
	vec3 H = 0.5f * (l->getDir(data.p) + r.direction());
	float NdotH = data.normal * H;
	return l->getColor(data.normal);
}
