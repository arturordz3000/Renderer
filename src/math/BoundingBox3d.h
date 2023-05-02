#pragma once

#include <vector>
#include "Vector.h"

namespace Renderer
{
	class BoundingBox3d
	{
	public:
		Vector2<float> minPoint;
		Vector2<float> maxPoint;

		BoundingBox3d(const std::vector<Vector3<float>>& points, const Vector2<float>& limit);
	};
}