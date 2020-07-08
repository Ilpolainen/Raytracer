#pragma once
#include "cam.h"
#include "surf.h"
#include "light.h"
class renderer
{
public:
	renderer(int w, int h);
	~renderer();
	void render(cam &camera, surf *world, light *l, int num_samples, int max_bounces, std::string fname);
private:
	int width;
	int height;
	float dx;
	vec3 color_in_pixel(int i, int j, cam &camera, surf *world, light*l, int num_samples, int max_bounces);
	vec3 color(ray &r, surf *world, light *l, int maxbounce);
};

