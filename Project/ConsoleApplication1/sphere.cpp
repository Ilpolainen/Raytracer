#include "stdafx.h"
#include "sphere.h"
#include <cassert>


sphere::sphere(vec3 in_o, float in_r, material *in_mat)
{
	orig = in_o;
	rad = in_r;
	mat = in_mat;
}

sphere::~sphere()
{
}

bool sphere::hit(const ray &r,float min, float max, hitRecord &data) const
{
	vec3 oc = r.origin()  - orig;
	const vec3 direction = r.direction();
	float a = direction * direction;
	float b = (oc * direction);
	float c = (oc * oc) - (rad * rad);
	float discriminant = b * b - a * c;
	if (discriminant > 0) {
		float sqr = sqrt(discriminant);
		float inva = 1.0f / a;
		float t = (-b - sqr) * inva;
		if (t > min && t < max) {
			data.t = t;
			data.p = r.p(t);
			data.normal = (data.p - orig) / rad;
			data.mat = mat;
			return true;
		}
		t = (-b + sqr) * inva;
		if (t > min && t < max) {
			data.t = t;
			data.p = r.p(t);
			data.normal = (data.p - orig) / rad;
			data.mat = mat;
			return true;
		}
	}
	return false;
}


vec3 sphere::origin() const
{
	return orig;
}

float sphere::radius() const
{
	return rad;
}
