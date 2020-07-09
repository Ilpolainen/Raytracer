#include "stdafx.h"
#include "dielectric.h"
#include "material.h"
#include "specmath.h"
#include <cassert>


bool dielectric::scatter(const ray & r, hitRecord & data, vec3 & attenuation, ray & scattered, const light *l)
{
	vec3 out_normal;
	float ni_over_nt;
	vec3 refracted;
	float reflectprob;
	float cosine;
	attenuation = albedo;
	float entering_cosine = r.rawDirection() * data.normal;
	if (entering_cosine > 0) {
		out_normal = -data.normal;
		ni_over_nt = ref_idx;
		cosine = ref_idx * entering_cosine / r.rawDirection().length();
	}
	else {
		out_normal = data.normal;
		ni_over_nt = 1 / ref_idx;
		cosine =  -ref_idx * entering_cosine / r.rawDirection().length();
	}
	if (material::refract(r.rawDirection(), out_normal, ni_over_nt, refracted)) {
		reflectprob = material::schlick(cosine, ref_idx);
	}
	else {
		reflectprob = 1.0f;
	}
	if (specmath::randFloat() < reflectprob) {
		scattered = ray(data.p, material::reflect(r.rawDirection(), data.normal));
	}
	else {
		scattered = ray(data.p, refracted);
	}
	return true;
}

dielectric::dielectric(const vec3 &att, float ri)
{
	ref_idx = ri;
	albedo = att;
}

dielectric::~dielectric()
{
}

vec3 dielectric::lighting(const light * l, const hitRecord & data, const ray & r) const
{
	vec3 out_normal;
	float ni_over_nt;
	vec3 refracted;
	float reflectprob;
	float cosine;
	float entering_cosine = r.rawDirection() * data.normal;
	if (entering_cosine > 0) {
		out_normal = -data.normal;
		ni_over_nt = ref_idx;
		cosine = ref_idx * entering_cosine / r.rawDirection().length();
	}
	else {
		out_normal = data.normal;
		ni_over_nt = 1 / ref_idx;
		cosine = -ref_idx * entering_cosine / r.rawDirection().length();
	}
	if (material::refract(r.rawDirection(), out_normal, ni_over_nt, refracted)) {
		reflectprob = material::schlick(cosine, ref_idx);
	}
	else {
		reflectprob = 1.0f;
	}
	if (specmath::randFloat() < reflectprob) {
		vec3 lambertian = albedo.had(l->getColor(r.direction()));
		vec3 H = (l->getDir(data.p) - r.direction()).normalized();
		float NdotH = -out_normal * H;
		float spec = pow(std::max(NdotH, 0.0f), 16.0f);
		vec3 specular = l->getColor() * spec;
		return specular;
	}
	else {
		vec3 lambertian = albedo.had(l->getColor(r.direction()));
		vec3 H = (l->getDir(data.p) - r.direction()).normalized();
		float NdotH = -out_normal * H;
		float spec = pow(std::max(NdotH, 0.0f), 16.0f);
		vec3 specular = l->getColor() * spec;
		return specular;
	}
}

float dielectric::energyDraw()
{
	return 1.0f;
}


