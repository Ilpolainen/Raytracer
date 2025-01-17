#pragma once
#include "vec3.h"
class ray
{
public:
	ray(const vec3& stp,const vec3& dir);
	ray();
	~ray();

	vec3 rawDirection() const;
	vec3 direction() const;
	vec3 origin() const;
	vec3 p(float t) const;
private:
	vec3 orig;
	vec3 rawDir;
};

