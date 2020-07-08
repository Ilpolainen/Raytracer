#include "stdafx.h"
#include "directionallight.h"


directionallight::directionallight(const vec3 & rawDirection, const vec3 & color)
	: color(color)
{
	direction = rawDirection.normalized();
}

directionallight::~directionallight()
{
}

vec3 directionallight::getColor(const vec3 & incoming) const
{
	float tempIntensity = (-incoming * direction);
	return color * (tempIntensity < 0 ? 0 : tempIntensity);
}

vec3 directionallight::getDir(const vec3 & point) const
{
	return -direction;
}

