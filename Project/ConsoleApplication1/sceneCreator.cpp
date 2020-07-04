#include "stdafx.h"
#include "sceneCreator.h"
#include "sphere.h"
#include "lambertian.h"
#include "dielectric.h"
#include "metal.h"
#include "specmath.h"
#include "surfcluster.h"


sceneCreator::sceneCreator()
{
}


sceneCreator::~sceneCreator()
{
}

surf * sceneCreator::random_scene(vec3 & look_from, vec3 & look_to)
{
	int n = 3;
	float width = 4.0f;
	float groundRadius = 1000;
	int totalnum = 2 * n * 2 * n + 5;
	surf **list = new surf*[totalnum];
	int i = 1;

	list[0] = new sphere( vec3(0.0f, -groundRadius, -1.0f), groundRadius, new lambertian(vec3(0.5f, 0.7f, 0.4f)));  // ground

	list[i++] = new sphere( vec3(4, 1, 0), -1.0f, new dielectric(vec3(1.0f, 1.0f, 1.0f), 1.0f));

	list[i++] = new sphere( vec3(-4, 1, 0), 1.0f, new metal(vec3(0.4f, 0.2f, 0.1f), 0.2f));

	list[i++] = new sphere( vec3(0, 1, 0), 1.0f, new metal(vec3(0.65f, 0.6f, 0.65f), 0.0f));

	list[i++] = new sphere(vec3(0.0f, 0.8f, 2.0f), 0.8f, new dielectric(vec3(1.0f, 1.0f, 1.0f), 1.5f));

	for (float a = -n * width; a < n * width; a = a + width)
	{
		for (float b = -n * width; b < n * width; b = b + width)
		{
			float choose_mat = specmath::randFloat();
			vec3 rd = specmath::random_inside_unit_disk();
			float radius = 0.2f * specmath::randFloat() + 0.15f;
			vec3 center = vec3(a + width * rd.x() * 2.0f, radius, b + width * rd.y());

			if ((center - 0.5f * (look_to + look_from)).length() > 1.0f) {
				if (choose_mat < 0.5) {
					vec3 color = vec3(specmath::randFloat()*specmath::randFloat(), specmath::randFloat()*specmath::randFloat(), specmath::randFloat()*specmath::randFloat());
					list[i++] = new sphere(center, radius, new lambertian(color));
				}
				else if (choose_mat < 0.8) {
					vec3 color = vec3(0.5f * (1.0f + specmath::randFloat()), 0.5f * (1.0f + specmath::randFloat()), 0.5f * (1.0f + specmath::randFloat()));
					list[i++] = new sphere(center, radius, new metal(color, 0.5f * specmath::randFloat()));
				}
				else {
					list[i++] = new sphere(center, radius, new dielectric(vec3(1, 1, 1), 1.5f));
				}
			}
		}
	}
	return  new surfcluster(list, i);
}

vec3 sceneCreator::backGround(const vec3 &dir) {
	float t = 0.5f * (dir.y() + 1);
	vec3 bgTint = vec3(0.5f, 0.7f, 0.9f);
	return t * bgTint + (1.0f - t) * vec3(1, 1, 1);
}
