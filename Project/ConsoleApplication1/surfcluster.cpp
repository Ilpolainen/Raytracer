#include "stdafx.h"
#include "surfcluster.h"
#include "float.h"
#include "sphere.h"



bool surfcluster::hit(const ray &r, float min, float max, hitRecord &data) const
{
	
	bool hit_anything = false;
	hitRecord temp;
	float closest = FLT_MAX;
	for (int i = 0; i < N; i++)
	{
		if (subSurfs[i]->hit(r,min,max, temp)) {
			hit_anything = true;
			if (temp.t < closest) {
				data.t = temp.t;
				data.normal = temp.normal;
				data.p = temp.p;
				data.mat = temp.mat;
				closest = temp.t;
			}
		}
	}
	return hit_anything;
}

surfcluster::surfcluster()
{
}

surfcluster::surfcluster(surf ** l, int n)
{
	N = n;
	subSurfs = l;
}


surfcluster::~surfcluster()
{
	for (size_t i = 0; i < N; i++)
	{
		delete subSurfs[i];
		subSurfs[i] = nullptr;
	}
	delete [] subSurfs;
	subSurfs = nullptr;
}
