#include <iostream>
#include "vendor/tga/tgaimage.h"
#include "geometry/line.h"
#include "model/Model.h"
#include "model/ObjModelLoader.h"

using namespace std;
using namespace Renderer;

const TGAColor RED = TGAColor(255, 0, 0, 255);
const TGAColor GREEN = TGAColor(0, 255, 0, 255);
const TGAColor BLUE = TGAColor(0, 0, 255, 255);
const TGAColor WHITE = TGAColor(255, 255, 255, 255);

void lineDemo(TGAImage& image)
{
	drawLine(Point(20, 13), Point(40, 80), image, RED);
	drawLine(Point(80, 40), Point(13, 20), image, GREEN);
	drawLine(Point(70, 40), Point(70, 20), image, BLUE);
}

void modelWireframeDemo(TGAImage& image)
{
	ObjModelLoader modelLoader;
	Model model = modelLoader.Load("assets/african_head.obj");
	model.Draw(image, WHITE);
}

int main()
{
	TGAImage image(500, 500, TGAImage::RGB);

	modelWireframeDemo(image);

	image.flip_vertically(); // Origin from left bottom corner
	image.write_tga_file("output.tga");

	return 0;
}