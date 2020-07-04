#pragma once
#include "vec3.h"
#include "ray.h"
class cam
{
public:
	cam(vec3 look_from, vec3 look_to, float aspectRatio, float fov, float aperture, float focus_dist);
	vec3 origin() const;
	vec3 horizontal() const;
	vec3 vertical() const;
	ray getRay(float u, float v) const;
	~cam();
private:
	vec3 orig;
	vec3 horiz;
	vec3 vert;
	vec3 llc;
	vec3 v, u, w;
	float lens_radius;
};

