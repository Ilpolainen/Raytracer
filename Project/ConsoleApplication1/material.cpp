#include "stdafx.h"
#include "material.h"
#include <cassert>




bool material::scatter(const ray & r, hitRecord & data, vec3 & attenuation, ray & scattered) const
{
	return false;
}

vec3 material::reflect(const vec3 & in, const vec3 & normal)
{
	return in - 2 * (in * normal) * normal;
}

bool material::refract(const vec3 &in, const vec3 &n, float ni_over_nt, vec3 &refracted) {
	vec3 uv = in.normalized();
	float dt = uv * n;
	float discriminant = 1.0f - ni_over_nt * ni_over_nt * (1.0f - dt * dt);
	if (discriminant < 0) {
		return false;
	}
	refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
	return true;
}

float material::schlick(float cosine, float ref_idx)
{
	float r0 = (1.0f - ref_idx) / (1.0f + ref_idx);
	r0 *= r0;
	return r0 + (1.0f - r0) * pow(1.0f - cosine,5);
}

material::material()
{
}


material::~material()
{
}
