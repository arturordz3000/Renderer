#pragma once

#include <string>
#include <vector>
#include "../math/vector.h"

using namespace std;

namespace Renderer
{
	class Model
	{
	public:
		vector<Vector3<float>> vertices;
		vector<vector<int>> faces;

		void Draw();
	};
}
