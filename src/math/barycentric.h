#pragma once

#include <vector>
#include "vector.h"
#include "Point.h"

namespace Renderer	
{	
	Vector3<float> computeBarycentricVector(const std::vector<Point>& triangleVertices, const Point &point);
	Vector3<float> computeBarycentricVector(const std::vector<Vector3<float>>& triangleVertices, Vector3<float>& point);
}	