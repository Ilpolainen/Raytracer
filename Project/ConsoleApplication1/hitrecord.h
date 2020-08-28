#pragma once
#include "vec3.h"
struct hitrecord
{
	float t;
	vec3 p;
	vec3 normal;
	int matId;
	bool receiveDirectLight = true;
};

