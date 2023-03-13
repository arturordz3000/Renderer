#include "Triangle.h"
#include "../math/vector.h"
#include "line.h"

namespace Renderer
{
	void drawTriangle1(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color);

	void drawTriangle(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		drawTriangle1(point1, point2, point3, image, color);
	}

	void drawTriangle(vector<Point> triangle, TGAImage& image, TGAColor color)
	{
		drawTriangle(triangle[0], triangle[1], triangle[2], image, color);
	}

	// This function draws the edges only
	void drawTriangle1(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		drawLine(point1, point2, image, color);
		drawLine(point2, point3, image, color);
		drawLine(point3, point1, image, color);
	}
}