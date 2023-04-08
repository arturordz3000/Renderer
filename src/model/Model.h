#pragma once

#include <string>
#include <vector>
#include "../math/vector.h"
#include "../vendor/tga/tgaimage.h"

using namespace std;

namespace Renderer
{
	enum RenderMode
	{
		Wireframe,
		FlatRandom
	};

	class Model
	{
	public:
		vector<Vector3<float>> vertices;
		vector<vector<int>> faces;

		Model()
		{

		}

		void Draw(TGAImage& image, TGAColor color, RenderMode mode = RenderMode::Wireframe);
	};
}
