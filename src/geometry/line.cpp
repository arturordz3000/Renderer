#include "line.h"

namespace Renderer
{
	void drawLineBresenham1(Point point1, Point point2, TGAImage& image, TGAColor color);
	void drawLineBresenham2(Point point1, Point point2, TGAImage& image, TGAColor color);
	void drawLineBresenham3(Point point1, Point point2, TGAImage& image, TGAColor color);

	void drawLine(Point point1, Point point2, TGAImage& image, TGAColor color)
	{
		drawLineBresenham3(point1, point2, image, color);
	}

	void rasterize(Point point1, Point point2, TGAImage& image, TGAColor color, int yBuffer[])
	{
		// This logic is somewhat similar to bresenham1. Here we're using it only for getting
		// the zBuffer (yBuffer in 2d)
		if (point1.x > point2.x) 
		{
			std::swap(point1.x, point2.x);
			std::swap(point1.y, point2.y);
		}

		for (int x = point1.x; x <= point2.x; x++)
		{
			float t = (x - point1.x) / (float)(point2.x - point1.x);
			int y = point1.y * (1.0 - t) + point2.y * t;

			if (y > yBuffer[x])
			{
				yBuffer[x] = y;
				image.set(x, 0, color);
			}
		}
	}

	bool sortPoints(Point& point1, Point& point2)
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

		return transposed;
	}

	void drawLineBresenham1(Point point1, Point point2, TGAImage& image, TGAColor color)
	{
		bool transposed = sortPoints(point1, point2);

		for (int x = point1.x; x <= point2.x; x++)
		{
			// t represents the percentage covered from point1.x to point2.x.
			// t will help us to calculate y
			float t = (x - point1.x) / (float)(point2.x - point1.x);

			// We do a linear interpolation to calculate y based on t (should be the same percentage covered from point1.x to poin2.x)
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

	void drawLineBresenham2(Point point1, Point point2, TGAImage& image, TGAColor color)
	{
		bool transposed = sortPoints(point1, point2);

		int deltaX = point2.x - point1.x;
		int deltaY = point2.y - point1.y;

		// This is the amount of error we're going to accumulate on each X.
		// It is basically the slope of the line.
		// It always have to be positive since we're sorting the points so that
		// every step is an increment.
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
				/*
				* This condition derives from the inequality:
				*			error + deltaError > 0.5
				* where deltaError = deltaY/deltaX
				* 
				* Whenever we make a change in Y, it means the inequality
				* is valid, so we have to substract the coefficient of error,
				* which in this case is 1
				*/
				error -= 1;

				// If the initial point is located above the second point,
				// we decrement Y, otherwise, we increment it.
				y += point1.y > point2.y ? -1 : 1;
			}
		}
	}

	void drawLineBresenham3(Point point1, Point point2, TGAImage& image, TGAColor color)
	{
		bool transposed = sortPoints(point1, point2);

		int deltaX = point2.x - point1.x;
		int deltaY = point2.y - point1.y;
		int deltaX2 = deltaX * 2;

		/*
		* The formula in the function drawLineBresenham2 checks if:
		*			error + deltaError > 0.5 
		*           then increment y.
		* Where deltaError = (y1-y0)/(x1-x0).
		* We can get rid of the division by multiplying by (x1-x0) i.e. deltaX
		*           deltaX*error + deltaY > deltaX * 0.5
		* Then to get rid of 0.5 we can multiply all by 2
		*			2 * deltaX * error + 2 * deltaY > deltaX
		* In the inequality above, we can see that we can increment error in each iteration
		* by 2 * deltaY. When error becomes greater than deltaX, we increment Y and substract
		* 2 * deltaX. Let's say for now that 2 * deltaX is equivalent to the "1" that we substracted
		* from error in drawLineBresenham2.
		* 
		* src: https://blog.mbedded.ninja/programming/algorithms-and-data-structures/bresenhams-line-algorithm/
		*/ 

		// This is the amount of error we're going to accumulate on each X.
		// It is basically the slope of the line.
		// It always have to be positive since we're sorting the points so that
		// every step is an increment.
		float deltaError = abs(2 * deltaY);

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
			if (error > deltaX)
			{
				error -= deltaX2;

				// If the initial point is located above the second point,
				// we decrement Y, otherwise, we increment it.
				y += point1.y > point2.y ? -1 : 1;
			}
		}
	}
}