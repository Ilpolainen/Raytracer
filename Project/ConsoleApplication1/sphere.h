#pragma once
#include "vec3.h"
#include "surf.h"
class sphere : public surf
{
public:
	sphere() = default;
	sphere(sphere&& other) noexcept = default;
	sphere& operator=(sphere&& other) noexcept = default;
	sphere(vec3 in_o, float in_r, int matId);
	virtual bool hit(const ray &r,float min, float max, hitrecord &data) const;
	vec3 origin() const;
	float radius() const;

private:
	vec3 orig;
	float rad;
	int matId;
};

