#pragma once
#include "light.h"
#include "vec3.h"
#include "ray.h"
class directionallight : public light
{
public:
	directionallight(const vec3 &rawDirection, const vec3 &color);
	~directionallight();
private:
	vec3 color;
	vec3 direction;

	// Inherited via light
	virtual vec3 getColor(const vec3 & incoming) const override;

	// Inherited via light
	virtual vec3 getDir(const vec3 & point) const override;

};

