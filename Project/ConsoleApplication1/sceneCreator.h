#pragma once
#include "scene.h"
class sceneCreator
{
public:
	static scene random_scene(vec3 &look_from, vec3 &look_to, const int num);
};

