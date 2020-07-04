
#include "stdafx.h"
#include "cam.h"
#include <math.h>
#include "specmath.h"
#include <cassert>
cam::cam(vec3 look_from, vec3 look_to, float aspectRatio, float fov, float aperture, float focus_dist)
{
	orig = look_from;

	float theta = fov / 180.0f * specmath::PI;
	float half_width_over_dist = tan(theta * 0.5);
	float half_height = half_width_over_dist / aspectRatio;

	vec3 world_up = vec3(0, 1, 0);

	w = (orig - look_to).normalized();
	u = world_up.cross(w).normalized();
	v = w.cross(u);

	llc = orig - half_width_over_dist * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
	horiz = 2.0f * u * half_width_over_dist * focus_dist;
	vert = 2.0f * v * half_width_over_dist * focus_dist;

	lens_radius = aperture / 2;
}



vec3 cam::origin() const
{
	return orig;
}

vec3 cam::horizontal() const
{
	return horiz;
}

vec3 cam::vertical() const
{
	return vert;
}

ray cam::getRay(float s, float t) const
{
	vec3 rd = specmath::random_inside_unit_disk() * lens_radius;
	vec3 offset = rd.x() * u + rd.y() * v;
	/*std::cout << offset;
	assert(false);*/
	return ray(orig + offset, llc + s * horiz + t * vert - orig - offset);
}



cam::~cam()
{
}
