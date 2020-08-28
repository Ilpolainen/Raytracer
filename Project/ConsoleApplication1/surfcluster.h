#pragma once
#include "surf.h"
#include "hitrecord.h"
#include <vector>
#include <memory>


class surfcluster : public surf
{
public:
	surfcluster() = default;
	surfcluster(std::vector<std::unique_ptr<surf>> subsurfs);
	~surfcluster() = default;
	surfcluster(const surfcluster& other);
	surfcluster(surfcluster&& other) noexcept;
	surfcluster& operator=(const surfcluster& other);
	surfcluster& operator=(surfcluster&& other) noexcept;
	virtual bool hit(const ray &r, float min, float max, hitrecord &data) const;
	int size() const;
	std::vector<std::unique_ptr<surf>> subsurfs;
	int n;
};

