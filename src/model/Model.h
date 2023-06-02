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
		ZBuffer,
		Textured
	};

	class Model
	{
	public:
		vector<Vector3<float>> vertices;
		vector<Vector2<float>> uv;
		vector<vector<int>> faces;
		vector<vector<int>> facesUV;
		Vector3<float> lightDirection;
		TGAImage texture;

		Model()
		{

		}

		void Draw(TGAImage& image, TGAColor color, RenderMode mode = RenderMode::Wireframe);

		void SetLightDirection(const Vector3<float>& lightDirection)
		{
			this->lightDirection = lightDirection;
		}

		void SetTexture(std::string texturePath)
		{
			this->texture.read_tga_file(texturePath.c_str());
			this->texture.flip_vertically();
		}
	};
}
