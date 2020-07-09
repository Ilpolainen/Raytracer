#pragma once
#include "surf.h"
class sceneCreator
{
public:
	sceneCreator();
	~sceneCreator();
	static surf *random_scene(vec3 &look_from, vec3 &look_to);
};

