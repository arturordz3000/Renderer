#pragma once

#include <string>
#include <vector>
#include "../math/vector.h"
#include "../vendor/tga/tgaimage.h"

using namespace std;

namespace Renderer
{
	class Model
	{
	public:
		vector<Vector3<float>> vertices;
		vector<vector<int>> faces;

		Model()
		{
			vertices.push_back(Vector3<float>(0, 0, 0));
		}

		void Draw(TGAImage& image, TGAColor color);
	};
}
