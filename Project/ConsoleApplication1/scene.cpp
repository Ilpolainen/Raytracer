#include "stdafx.h"
#include "scene.h"
#include <memory>


scene::scene(std::unique_ptr<surfcluster> cluster, std::vector<std::unique_ptr<material>> materials) :
cluster(std::move(cluster)),
materials(std::move(materials))
{
}


