// main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <random>
#include <cassert>
#include <functional>
#include "ImHelper.h"
#include "ray.h"
#include "sphere.h"
#include "surfcluster.h"
#include "cam.h"
#include "vec3.h"
#include "surf.h"
#include "material.h"
#include "dielectric.h"
#include "lambertian.h"
#include "metal.h"
#include "specmath.h"
#include "sceneCreator.h"
#include "renderer.h";



vec3 color(ray &r, surf *world, int maxbounce);
vec3 color_in_pixel(int i, int j, cam &camera, surf * world);

void render(cam &camera, surf * world);

static const int NUM_samples = 20;
static const int MAX_BOUNCES = 5;
static const int w = 90;
static const int h = 60;

static const float dx = 1.0f / float(w);


int main()
{



	
	float fieldOfView = 35.0f;
	vec3 look_from = vec3(12.0f,2.6f,3.5f);
	vec3 look_at = vec3(0.0f, 1.7f, 0.0f);

	surf *world = sceneCreator::random_scene(look_from, look_at);

	float focus_dist = (look_from - look_at).length();
	float aperture = 0.05f;

	cam camera = cam(look_from, look_at, float(w/h), fieldOfView, aperture, focus_dist);
	renderer rend = renderer(w,h);
	std::string fname = "test.ppm";

	rend.render(camera, world, NUM_samples, MAX_BOUNCES, fname);

	delete world;
}

void render(cam &camera, surf * world)
{
	std::ofstream file;
	file.open("swap.ppm", std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
	file << "P3\n" << w << " " << h << "\n255\n";

	for (int j = h - 1; j >= 0; j--)
	{
		float percent = 100.0f * (h - j) / h;
		std::cout << "" << percent << "% done \n";
		for (int i = 0; i < w; i++)
		{
			vec3 col = color_in_pixel(i, j, camera, world);
			file << int(255.99f * col[0]) << " " << int(255.99f * col[1]) << " " << int(255.99f * col[2]) << "\n";
		}
	}

	file.close();
}

vec3 color_in_pixel(int i, int j, cam &camera, surf * world)
{
	vec3 col;
	vec3 sum = vec3(0, 0, 0);
	for (int s = 0; s < NUM_samples; s++)
	{
		float u = (i + specmath::randFloat()) * dx;
		float v = (j + specmath::randFloat()) * dx;
		ray r = camera.getRay(u, v);
		vec3 sample = color(r, world, MAX_BOUNCES);
		sum = sum + sample;
	}
	col = sum / NUM_samples;
	col[0] = sqrt(col[0]);
	col[1] = sqrt(col[1]);
	col[2] = sqrt(col[2]);
	return col;
}

vec3 color(ray &r, surf *world, int maxbounce) {
	hitRecord rec;
	if (world->hit(r,0.001f,1000.0f,rec) && maxbounce > 0) {
		ray scattered;
		vec3 attenuation;
		if (rec.mat->scatter(r, rec, attenuation, scattered)) {
			return attenuation.had(color(scattered, world, maxbounce - 1));
		}
		else {
			return vec3(0, 0, 0);
		}
	}
	else {	
		vec3 dir = r.direction().normalized();
		return sceneCreator::backGround(dir);
	}
}







