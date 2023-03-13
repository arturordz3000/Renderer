#include "SimpleTrianglesDemo.h"
#include "../geometry/Triangle.h"
#include "../math/point.h"
#include <vector>

namespace Renderer
{
	int SimpleTrianglesDemo::Start()
	{
		TGAImage image(200, 200, TGAImage::RGB);

		vector<Point> triangle1 = { Point(10, 70), Point(50, 160), Point(70, 80) };
		vector<Point> triangle2 = { Point(180, 50), Point(150, 1), Point(70, 180) };
		vector<Point> triangle3 = { Point(180, 150), Point(120, 160), Point(130, 180) };

		drawTriangle(triangle1, image, RED);
		drawTriangle(triangle2, image, WHITE);
		drawTriangle(triangle3, image, GREEN);

		image.flip_vertically(); // Origin from left bottom corner
		image.write_tga_file("output.tga");

		return 0;
	}
}