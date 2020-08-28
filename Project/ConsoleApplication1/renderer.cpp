#include "stdafx.h"
#include "renderer.h"
#include "ray.h"
#include "sceneCreator.h"
#include "surf.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <random>
#include <cassert>
#include <functional>
#include "specmath.h"
#include "light.h"
#include "material.h"


renderer::renderer(int w, int h)
{
	width = w;
	height = h;
	dx = 1.0f / width;
}


renderer::~renderer()
{
}

void renderer::render(cam &camera, const scene& scene, const light *l, vec3 ambience_col, float ambience_strength, int num_samples, int max_bounces, float bounce_energy, std::string fname)
{
	ambience_tint = ambience_col;
	ambience_amount = ambience_strength;
	std::ofstream file;
	file.open(fname, std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
	file << "P3\n" << width << " " << height << "\n255\n";

	for (int j = height - 1; j >= 0; j--)
	{
		float percent = 100.0f * (height - j) / height;
		std::cout << "" << percent << "% done \n";
		for (int i = 0; i < width; i++)
		{
			vec3 col = color_in_pixel(i, j, camera, scene, l, num_samples, max_bounces, bounce_energy);
			col = col.clamped(1.0f);
			file << int(255.99f * col[0]) << " " << int(255.99f * col[1]) << " " << int(255.99f * col[2]) << "\n";
		}
	}
	file.close();
}

vec3 renderer::color_in_pixel(int i, int j, cam &camera, const scene& world, const light *l, int num_samples, int max_bounces, float bounce_energy)
{
	vec3 col;
	vec3 sum = vec3(0, 0, 0);
	for (int s = 0; s < num_samples; s++)
	{
		float u = (i + specmath::randFloat()) * dx;
		float v = (j + specmath::randFloat()) * dx;
		ray r = camera.getRay(u, v);
		vec3 sample = color(r, world,l, max_bounces, bounce_energy);
		sum = sum + sample;
	}
	col = sum / num_samples;
	col[0] = sqrt(col[0]);
	col[1] = sqrt(col[1]);
	col[2] = sqrt(col[2]);
	return col;
}

vec3 renderer::ambience(const vec3 &dir) {
	float t = 0.5f * (dir.y() + 1);
	return ambience_amount * (t * ambience_tint + (1.0f - t) * vec3(1, 1, 1));
}



vec3 renderer::color(ray &r, const scene& world, const light *l, int maxbounce, float bounce_energy) {
	const vec3 dir = r.rawDirection().normalized();
	hitrecord rec;
	if (world.cluster->hit(r, 0.001f, 1000.0f, rec)) {
		if (maxbounce > 0 && bounce_energy > 0.25f) {
			ray scattered;
			vec3 attenuation;
			if (world.materials[rec.matId].scatter(r, rec, attenuation, scattered, l)) {
				vec3 indirect = color(scattered, world, l, maxbounce - 1, world.materials[rec.matId].energyDraw() * bounce_energy);
				hitrecord temp;
				//vec3 direct;
				vec3 lightDirection = l->getDir(rec.p);
				/*if (!world->hit(ray(rec.p, lightDirection), 0.001f, 1000.0f, temp)) {
					direct = rec.mat->lighting(l, rec, r);
				}
				else {
					direct = vec3(0, 0, 0);
				}*/
				return attenuation.had(indirect);
			}
			else {
				return vec3(0, 0, 0);
			}
		}
		else {
			return ambience(dir) + l->getLight(r.direction());
		}
	}
	else {
		return ambience(dir) + l->getLight(r.direction());
	}
}
