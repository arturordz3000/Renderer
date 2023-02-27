#include "LineDemo.h"
#include "../geometry/line.h"

namespace Renderer
{
	int LineDemo::Start()
	{
		TGAImage image(100, 100, TGAImage::RGB);

		drawLine(Point(20, 13), Point(40, 80), image, RED);
		drawLine(Point(80, 40), Point(13, 20), image, GREEN);
		drawLine(Point(70, 40), Point(70, 20), image, BLUE);

		image.flip_vertically(); // Origin from left bottom corner
		image.write_tga_file("output.tga");

		return 0;
	}
}