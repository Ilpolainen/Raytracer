#pragma once
#include "cam.h"
#include "surf.h"
#include "light.h"
class renderer
{
public:
	renderer(int w, int h);
	~renderer();
	void render(cam &camera, surf *world, light *l, vec3 ambience_col, float ambience_strength, int num_samples, int max_bounces, float bounce_energy, std::string fname);
private:
	int width;
	int height;
	float dx;

	float ambience_amount;
	vec3 ambience_tint;
	float direct_diffuse_strength;

	vec3 color_in_pixel(int i, int j, cam &camera, surf *world, light*l, int num_samples, int max_bounces, float bounce_energy);
	vec3 color(ray &r, surf *world, light *l, int maxbounce, float bounce_energy);
	vec3 ambience(const vec3 &rdir);
};

