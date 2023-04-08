#include "BoundingBox2d.h"

namespace Renderer
{
	BoundingBox2d::BoundingBox2d(const std::vector<Point>& points, const Point& limit)
	{
		minPoint = Point(limit.x, limit.y);
		maxPoint = Point(0, 0);

		for (int i = 0; i < points.size(); i++)
		{
			minPoint.x = std::max(0, std::min(minPoint.x, points[i].x));
			minPoint.y = std::max(0, std::min(minPoint.y, points[i].y));

			maxPoint.x = std::min(limit.x, std::max(maxPoint.x, points[i].x));
			maxPoint.y = std::min(limit.y, std::max(maxPoint.y, points[i].y));
		}
	}
}