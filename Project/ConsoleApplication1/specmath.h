#pragma once
#include "vec3.h"
#include "stdafx.h"
#include <random>
#include <stdlib.h>
#include <math.h>
#include <functional>
class specrand;

class specmath
{
public:
	static constexpr double PI = 3.14159265358979323846f;
	static specrand sprand;
	static vec3 random_inside_unit_sphere();
	static vec3 random_inside_unit_disk();
	static float randFloat();
	specmath();
	~specmath();
};

class specrand {
public:
	specrand();
	std::mt19937 gen;
	std::uniform_real_distribution<float> dis;
	float pull();
};


