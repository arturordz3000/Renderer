#pragma once

#include <vector>
#include "vector.h"
#include "Point.h"

namespace Renderer	
{	
	Vector3<float> computeBarycentricVector(const std::vector<Point>& triangleVertices, const Point &point);
}	