#include <iostream>
#include "vendor/tga/tgaimage.h"

using namespace std;

int main()
{
	TGAImage image(100, 100, TGAImage::RGB);
	image.flip_vertically(); // Origin from left bottom corner
	image.set(50, 50, TGAColor(255, 0, 0, 255));
	image.write_tga_file("output.tga");

	return 0;
}