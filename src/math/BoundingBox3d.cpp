#include "BoundingBox3d.h"

namespace Renderer
{
	BoundingBox3d::BoundingBox3d(const std::vector<Vector3<float>>& points, const Vector2<float>& limit)
	{
		minPoint = Vector2<float>(limit.x, limit.y);
		maxPoint = Vector2<float>(0, 0);

		for (int i = 0; i < points.size(); i++)
		{
			minPoint.x = std::max(0.0f, std::min(minPoint.x, points[i].x));
			minPoint.y = std::max(0.0f, std::min(minPoint.y, points[i].y));

			maxPoint.x = std::min(limit.x, std::max(maxPoint.x, points[i].x));
			maxPoint.y = std::min(limit.y, std::max(maxPoint.y, points[i].y));
		}
	}
}