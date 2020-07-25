#include "stdafx.h"
#include "directionallight.h"
#include <math.h>
#include <algorithm>

directionallight::directionallight(const vec3 & rawDirection, const vec3 & color)
	: color(color)
{
	direction = rawDirection.normalized();
}

directionallight::~directionallight()
{
}

vec3 directionallight::getLight(const vec3 & incoming) const
{
	float tempIntensity = (-incoming * direction);
	tempIntensity = std::max(tempIntensity, 0.0f);
	return color * std::pow(tempIntensity,6);
}

vec3 directionallight::getDir(const vec3 & point) const
{
	return -direction;
}

vec3 directionallight::getColor() const
{
	return color;
}

