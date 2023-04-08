#pragma once

#include <vector>
#include "Point.h"

namespace Renderer
{
	class BoundingBox2d
	{
	public:
		Point minPoint;
		Point maxPoint;

		BoundingBox2d(const std::vector<Point>& points, const Point& limit);
	};
}