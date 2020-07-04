#include "stdafx.h"
#include "ImHelper.h"
#include <iostream>
#include <fstream>


ImHelper::ImHelper()
{
}


ImHelper::~ImHelper()
{
}

void ImHelper::testImage(int w, int h)
{
	std::ofstream myfile;
	myfile.open("testIm.ppm");
	myfile << "P3\n" << w << " " << h << "\n255\n";
	for (int j = h - 1; j >= 0; j--)
	{
		for (int i = 0; i < w; i++)
		{
			float r = float(i) / float(w);
			float g = float(j) / float(h);
			float b = 0.2f;
			myfile << int(255.99f * r) << " " << int(255.99f * g) << " " << int(255.99f * b) << "\n";
		}
	}
	myfile.close();
}
