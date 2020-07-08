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
#include "directionallight.h"

static const int NUM_samples = 200;
static const int MAX_BOUNCES = 4;
static const int w = 300;
static const int h = 200;
static const float aperture = 0.1f;
static const float dx = 1.0f / float(w);


int main()
{
	float fieldOfView = 35.0f;
	vec3 look_from = vec3(12.0f,2.2f,3.5f);
	vec3 look_at = vec3(0.0f, 1.1f, 0.0f);

	surf *scene = sceneCreator::random_scene(look_from, look_at);

	float focus_dist = (look_from - look_at).length();

	cam camera = cam(look_from, look_at, float(w/h), fieldOfView, aperture, focus_dist);
	renderer rend = renderer(w,h);
	std::string fname = "test.ppm";

	rend.render(camera, scene,new directionallight(vec3(0.3f,-1.0f,0.5f),1.1f*vec3(0.5f,0.4f,0.3f)), NUM_samples, MAX_BOUNCES, fname);

	delete scene;
}








