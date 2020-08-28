#include "stdafx.h"
#include "scene.h"
#include <memory>


scene::scene(std::unique_ptr<surfcluster> cluster, std::vector<material> materials) :
cluster(std::move(cluster)),
materials(materials)
{
	std::cout << "\nIn the scene constructor the sizes are:\n";
	std::cout << "\nMaterials: " << materials.size() << "?\n";
	std::cout << "\nSurfaces: " << this->cluster->size() << "?\n";
}


