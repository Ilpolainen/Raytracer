#include "stdafx.h"
#include "dielectric.h"
#include "material.h"
#include "specmath.h"
#include <cassert>


bool dielectric::scatter(const ray & r, hitrecord & data, vec3 & attenuation, ray & scattered, const light *l) const
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

dielectric::dielectric(const vec3 &att, float ri, float directLightAmount) : ref_idx(ri), albedo(att), directLightAmount(directLightAmount)
{
}

dielectric::~dielectric()
{
}

vec3 dielectric::lighting(const light * l, const hitrecord & data, const ray & r) const
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
		return directLightAmount * l->getLight(-out_normal);
	}
	else {
		return directLightAmount * l->getLight(-out_normal);
	}
}

float dielectric::energyDraw() const
{
	return 1.0f;
}


