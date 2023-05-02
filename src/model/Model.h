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
		FlatRandom,
		FlatLight,
		ZBuffer
	};

	class Model
	{
	public:
		vector<Vector3<float>> vertices;
		vector<vector<int>> faces;
		Vector3<float> lightDirection;

		Model()
		{

		}

		void Draw(TGAImage& image, TGAColor color, RenderMode mode = RenderMode::Wireframe);
		void SetLightDirection(const Vector3<float>& lightDirection)
		{
			this->lightDirection = lightDirection;
		}
	};
}
