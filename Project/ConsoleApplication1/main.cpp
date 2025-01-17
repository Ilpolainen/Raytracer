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
#include "specmath.h"
#include "sceneCreator.h"
#include "renderer.h"
#include "directionallight.h"

static const int NUM_samples = 10;
static const int MAX_BOUNCES = 3;
static const float BOUNCE_ENERGY = 1.0f;
static const int w = 200;
static const int h = 200;
static const float aperture = 0.1f;
static const float dx = 1.0f / float(w);
static const float light_intensity = 2.0f;
static const vec3 light_tint = vec3(0.65f, 0.5f, 0.25f);
static const vec3 light_dir = vec3(-0.7f, -1.0f, 1.0f);
static const float ambience_intensity = 1.0f;
static const vec3 ambience_tint = vec3(0.5f, 0.7f, 1.0f);;

int main()
{
	float fieldOfView = 35.0f;
	vec3 look_from = vec3(12.0f,2.2f,3.5f);
	vec3 look_at = vec3(0.0f, 1.1f, 0.0f);
	const int num = 2;
	const auto scene = sceneCreator::random_scene(look_from, look_at,num);

	float focus_dist = (look_from - look_at).length();

	cam camera = cam(look_from, look_at, float(w/h), fieldOfView, aperture, focus_dist);
	renderer rend = renderer(w,h);
	std::string fname = "test.ppm";

	rend.render(camera, scene, std::make_unique<directionallight>(light_dir, light_intensity * light_tint).get(), ambience_tint, ambience_intensity, NUM_samples, MAX_BOUNCES,BOUNCE_ENERGY, fname);

	std::cin.get();
}








