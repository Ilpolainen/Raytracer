#include "stdafx.h"
#include "specmath.h"
#include <math.h>
#include <random>
#include <functional>

specrand specmath::sprand = specrand();

vec3 specmath::random_inside_unit_sphere()
{
	float x = 2 * sprand.pull()  - 1;
	float y = 2 * sprand.pull() - 1;
	float z = 2 * sprand.pull() - 1;
	while (x*x + y * y + z * z > 1)
	{
		x = 2 * sprand.pull() - 1;
		y = 2 * sprand.pull() - 1;
		z = 2 * sprand.pull() - 1;
	}
	return vec3(x, y, z);
}

vec3 specmath::random_inside_unit_disk()
{
	float x = 2 * sprand.pull() - 1;
	float y = 2 * sprand.pull() - 1;
	float z = 0;
	vec3 disk = vec3(x, y, z);
	while (disk * disk >= 1)
	{
		x = 2 * sprand.pull() - 1;
		y = 2 * sprand.pull() - 1;
		disk = vec3(x, y, z);
	}
	return disk;
}

float specmath::randFloat()
{
	return sprand.pull();
}

specmath::specmath()
{
}


specmath::~specmath()
{
}



specrand::specrand()
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	gen = std::mt19937(rd()); //Standard mersenne_twister_engine seeded with rd()
	dis = std::uniform_real_distribution<float>(0.0f, 1.0f);
}

float specrand::pull()
{
	return dis(gen);
}
