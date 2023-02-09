#include <iostream>
#include "vendor/tga/tgaimage.h"
#include "geometry/geometry.h"

using namespace std;
using namespace Renderer;

const TGAColor RED = TGAColor(255, 0, 0, 255);

int main()
{
	TGAImage image(100, 100, TGAImage::RGB);

	drawLine(Point(20, 13), Point(40, 80), image, RED);
	drawLine(Point(80, 40), Point(13, 20), image, RED);

	image.flip_vertically(); // Origin from left bottom corner
	image.write_tga_file("output.tga");

	return 0;
}