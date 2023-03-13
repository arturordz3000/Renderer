#include "Triangle.h"
#include "../math/vector.h"
#include "line.h"

namespace Renderer
{
	void drawTriangle1(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color);
	void drawTriangle2(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color);

	void drawTriangle(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		drawTriangle2(point1, point2, point3, image, color);
	}

	void drawTriangle(vector<Point> triangle, TGAImage& image, TGAColor color)
	{
		drawTriangle(triangle[0], triangle[1], triangle[2], image, color);
	}

	// This function draws the triangle edges only
	void drawTriangle1(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		drawLine(point1, point2, image, color);
		drawLine(point2, point3, image, color);
		drawLine(point3, point1, image, color);
	}

	// This function draws the two boundaries (A and B) of the triangle.
	// Boundary A (red color) is from point1 to point3 
	// Boundary B (green color) is point1 to point2 and then point2 to point3
	void drawTriangle2(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		// In order to get the correct boundaries, we need to order the points
		// from lower to upper using the Y-coordinate.
		if (point1.y > point2.y) swap(point1, point2);
		if (point1.y > point3.y) swap(point1, point3);
		if (point2.y > point3.y) swap(point2, point3);

		drawLine(point1, point3, image, RED);
		drawLine(point1, point2, image, GREEN);
		drawLine(point2, point3, image, GREEN);
	}
}