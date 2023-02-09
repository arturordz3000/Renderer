#include "geometry.h"

namespace Renderer
{
	void drawLine(Point point1, Point point2, TGAImage& image, TGAColor color)
	{
		int dx = abs(point1.x - point2.x);
		int dy = abs(point1.y - point2.y);
		bool transposed = false;

		if (dx < dy)
		{
			// If the difference in y is larger than x,
			// we need to transpose the image to avoid
			// holes in the line.
			transposed = true;
			std::swap(point1.x, point1.y);
			std::swap(point2.x, point2.y);
		}

		if (point1.x > point2.x)
		{
			// We need to start from left to right.
			// If point1.x is greater than point2.x, that means we
			// need to start rendering the line from point2
			std::swap(point1, point2);
		}

		for (int x = point1.x; x <= point2.x; x++)
		{
			// t represents the percentage covered from point1.x to point2.x.
			// t will help us to calculate y
			float t = (x - point1.x) / (float)(point2.x - point1.x);

			// We do a linear interpolation to calculate y based on t (the percentage covered from point1.x to poin2.x)
			int y = point1.y * (1.0 - t) + point2.y * t;

			if (transposed)
			{
				// De-transpose the image
				image.set(y, x, color);
			}
			else
			{
				image.set(x, y, color);
			}
		}
	}
}