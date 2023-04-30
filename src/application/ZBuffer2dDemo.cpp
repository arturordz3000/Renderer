#include "ZBuffer2dDemo.h"
#include "../geometry/line.h"

namespace Renderer
{
	int ZBuffer2dDemo::Start()
	{
		const int width = 800;

		TGAImage image(width, 500, TGAImage::RGB);

		int yBuffer[width];
		for (int i = 0; i < width; i++)
		{
			yBuffer[i] = std::numeric_limits<int>::min();
		}
		
		drawLine(Point(20, 34), Point(744, 400), image, RED);
		drawLine(Point(120, 434), Point(444, 400), image, GREEN);
		drawLine(Point(330, 463), Point(594, 200), image, BLUE);
		drawLine(Point(10, 10), Point(790, 10), image, WHITE);

		rasterize(Point(20, 34), Point(744, 400), image, RED, yBuffer);
		rasterize(Point(120, 434), Point(444, 400), image, GREEN, yBuffer);
		rasterize(Point(330, 463), Point(594, 200), image, BLUE, yBuffer);

		image.flip_vertically(); // Origin from left bottom corner
		image.write_tga_file("output.tga");

		return 0;
	}
}