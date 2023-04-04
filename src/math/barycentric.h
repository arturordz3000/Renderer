#pragma once

#include "vector.h"
#include <vector>

namespace Renderer
{
	template<class T>
	Vector3<float> computeBarycentricVector(std::vector<Vector3<T>>& trianglePoints, Vector3<T> point);
}