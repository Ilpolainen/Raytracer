#include "stdafx.h"
#include "surfcluster.h"
#include "hitrecord.h"
#include "float.h"
#include "sphere.h"



//surfcluster::surfcluster(const surfcluster & other)
//{
//	std::cout << "\nSurfcluster MOVE constructor called!\n";
//}
//
//surfcluster::surfcluster(surfcluster && other) noexcept :
//	subsurfs(std::move(other.subsurfs))
//{
//	std::cout << "\nSurfcluster MOVE constructor called!\n";
//	n = subsurfs.size();
//}
//
//surfcluster & surfcluster::operator=(const surfcluster & other)
//{
//	std::cout << "\nSurfcluster COPY assignment called!\n";
//	return *this;
//}
//
//surfcluster & surfcluster::operator=(surfcluster && other) noexcept
//{
//	std::cout << "\nSurfcluster MOVE assignment called!\n";
//	subsurfs = std::move(other.subsurfs);
//	n = subsurfs.size();
//	return *this;
//}

bool surfcluster::hit(const ray &r, float min, float max, hitrecord &data) const
{
	bool hit_anything = false;
	hitrecord temp;
	float closest = FLT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (subsurfs[i]->hit(r,min,max, temp)) {
			hit_anything = true;
			if (temp.t < closest) {
				data.t = temp.t;
				data.normal = temp.normal;
				data.p = temp.p;
				data.matId = temp.matId;
				closest = temp.t;
			}
		}
	}
	return hit_anything;
}

surfcluster::surfcluster(std::vector<std::unique_ptr<surf>> subsurfs) : subsurfs(std::move(subsurfs))
{
	n = this->subsurfs.size();
}

int surfcluster::size() const
{
	return n;
}

