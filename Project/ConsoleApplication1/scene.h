#pragma once
#include <memory>
#include "surfcluster.h"
#include "material.h"
class scene
{
public:
	scene(std::unique_ptr<surfcluster> cluster, std::vector<material> materials);
	scene() = default;
	std::unique_ptr<surfcluster> cluster;
	std::vector<material> materials;
};

