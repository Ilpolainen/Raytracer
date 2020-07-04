#pragma once
#include "surf.h"

class surfcluster : public surf
{
public:
	virtual bool hit(const ray &r, float min, float max, hitRecord &data) const;
	surfcluster();
	surfcluster(surf** l, int n);
	~surfcluster();
	surf **subSurfs;
	int N;
};

