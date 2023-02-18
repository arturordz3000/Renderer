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

		int deltaX = point2.x - point1.x;
		int deltaY = point2.y - point1.y;

		// This is the amount of error we're going to accumulate on each X.
		// It is basically the slope of the line.
		float deltaError = abs(deltaY / float(deltaX));

		// Accumulated error
		float error = 0;
		int y = point1.y;

		for (int x = point1.x; x <= point2.x; x++)
		{
			if (transposed)
			{
				// De-transpose the image
				image.set(y, x, color);
			}
			else
			{
				image.set(x, y, color);
			}

			error += deltaError;

			// If the accumulated error is greater than half a pixel,
			// we better increment (or decrement) y.
			if (error > 0.5)
			{
				error -= 1;

				// If the initial point is located above the second point,
				// we decrement Y, otherwise, we increment it.
				y += point1.y > point2.y ? -1 : 1;
			}
		}
	}
}