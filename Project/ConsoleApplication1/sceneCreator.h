#pragma once
#include "surfcluster.h"
class sceneCreator
{
public:
	sceneCreator();
	~sceneCreator();
	static surfcluster *random_scene(vec3 &look_from, vec3 &look_to, const int num);
};

