#include "../math/vector.h"
#include "Triangle.h"
#include "line.h"
#include "../math/BoundingBox2d.h"
#include "../math/Barycentric.h"

namespace Renderer
{
	void drawTriangle1(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color);
	void drawTriangle2(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color);
	void drawTriangle3(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color);
	void drawTriangle4(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color);

	void drawTriangle(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		drawTriangle4(point1, point2, point3, image, color);
	}

	void drawTriangle(vector<Point> triangle, TGAImage& image, TGAColor color)
	{
		drawTriangle(triangle[0], triangle[1], triangle[2], image, color);
	}

	// In order to get the correct boundaries, we need to sort the points
	// from lower to upper using the Y-coordinate.
	void sortPoints(Point& point1, Point& point2, Point& point3)
	{
		if (point1.y > point2.y) swap(point1, point2);
		if (point1.y > point3.y) swap(point1, point3);
		if (point2.y > point3.y) swap(point2, point3);
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
		sortPoints(point1, point2, point3);

		drawLine(point1, point3, image, RED);
		drawLine(point1, point2, image, GREEN);
		drawLine(point2, point3, image, GREEN);
	}

	// This function draws the triangle and fills it with color using the 2-boundaries algorithm.
	void drawTriangle3(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		sortPoints(point1, point2, point3);

		int triangleHeight = point3.y - point1.y;

		/*
		* With this algorithm, we need to split the rendering of the triangle
		* in two parts, since we have two boundaries. The first half will render
		* from the lowest point (point1) to the middle point (point2). Then,
		* we render from the middle point (point2) to the upper-most point (point3).
		*
		* We need to split the rendering process in two parts because we need the X-boundaries
		* of 2 points, since we can't use the algorithm with the 3 points at the same time.
		*/

		// We render the first segment of the triangle,
		// from point1.y to point2.y
		for (int y = point1.y; y <= point2.y; y++)
		{
			int segmentHeight = point2.y - point1.y;
			float alpha = (float)(y - point1.y) / triangleHeight;
			float beta = (float)(y - point1.y) / segmentHeight;

			// Remember that SegmentA is the red one.
			Vector2<int> segmentA = point1 + (point3 - point1) * alpha;

			// Remember that SegmentB is the green one.
			Vector2<int> segmentB = point1 + (point2 - point1) * beta;

			// Swap the X if needed so that we render from left to right
			if (segmentA.x > segmentB.x) swap(segmentA, segmentB);

			for (int x = segmentA.x; x <= segmentB.x; x++)
			{
				image.set(x, y, color);
			}
		}

		// Next, we render the second segment
		for (int y = point2.y; y <= point3.y; y++)
		{
			int segmentHeight = point3.y - point2.y;
			float alpha = (float)(y - point1.y) / triangleHeight;
			float beta = (float)(y - point2.y) / segmentHeight;

			// Remember that SegmentA is the red one.
			Vector2<int> segmentA = point1 + (point3 - point1) * alpha;

			// Remember that SegmentB is the green one.
			Vector2<int> segmentB = point2 + (point3 - point2) * beta;

			// Swap the X if needed so that we render from left to right
			if (segmentA.x > segmentB.x) swap(segmentA, segmentB);

			for (int x = segmentA.x; x <= segmentB.x; x++)
			{
				image.set(x, y, color);
			}
		}
	}

	// Checks if point is inside a triangle using barycentric coordinates.
	bool isPointInside(const std::vector<Point> triangle, const Point& point)
	{
		Vector3<float> barycentricCoordinate = computeBarycentricVector(triangle, point);

		if (barycentricCoordinate.x < 0 || barycentricCoordinate.y < 0 || barycentricCoordinate.z < 0)
			return false;

		return true;
	}

	// This function draws the triangle using barycentric coordinates and bounding box.
	void drawTriangle4(Point& point1, Point& point2, Point& point3, TGAImage& image, TGAColor color)
	{
		std::vector<Point> triangle = { point1, point2, point3 };
		BoundingBox2d boundingBox(triangle, Point(image.get_width() - 1, image.get_height() - 1));

		for (int x = boundingBox.minPoint.x; x < boundingBox.maxPoint.x; x++)
		{
			for (int y = boundingBox.minPoint.y; y < boundingBox.maxPoint.y; y++)
			{
				if (isPointInside(triangle, Point(x, y)))
					image.set(x, y, color);
			}
		}
	}
}