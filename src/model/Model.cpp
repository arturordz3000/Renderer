#include "Model.h"
#include "../math/point.h"
#include "../math/vector.h"
#include "../geometry/line.h"
#include "../vendor/tga/tgaimage.h"
#include "../geometry/Triangle.h"

namespace Renderer
{
	float computeLightIntensity(const std::vector<Vector3<float>>& triangle, Vector3<float> &lightDirection, const TGAImage& image);

	void Model::Draw(TGAImage &image, TGAColor color, RenderMode mode)
	{
		int viewportWidth = image.get_width();
		int viewportHeight = image.get_height();

		int numberOfFaces = this->faces.size();

		for (int i = 0; i < numberOfFaces; i++)
		{
			Vector3<float> vertex1 = this->vertices[this->faces[i][0]];
			Vector3<float> vertex2 = this->vertices[this->faces[i][1]];
			Vector3<float> vertex3 = this->vertices[this->faces[i][2]];

			// Converting from <-width to +width> to <0 to +width>
			Point point1((vertex1.x + 1.) * viewportWidth / 2., (vertex1.y + 1.) * viewportHeight / 2.);
			Point point2((vertex2.x + 1.) * viewportWidth / 2., (vertex2.y + 1.) * viewportHeight / 2.);
			Point point3((vertex3.x + 1.) * viewportWidth / 2., (vertex3.y + 1.) * viewportHeight / 2.);

			switch (mode)
			{
			case RenderMode::FlatRandom:
			{
				drawTriangle({ point1, point2, point3 }, image, TGAColor(rand() % 255, rand() % 255, rand() % 255, 255));
				break;
			}
			case RenderMode::FlatLight:
			{
				float lightIntensity = computeLightIntensity({ vertex1, vertex2, vertex3 }, this->lightDirection, image);
				if (lightIntensity > 0)
				{
					drawTriangle({ point1, point2, point3 }, image, TGAColor(color.r * lightIntensity, color.g * lightIntensity, color.b * lightIntensity, color.a));
				}
				break;
			}
			default:
				drawLine(point1, point2, image, color);
				drawLine(point2, point3, image, color);
				drawLine(point3, point1, image, color);
			}
		}
	}

	float computeLightIntensity(const std::vector<Vector3<float>>& triangle, Vector3<float> &lightDirection, const TGAImage& image)
	{
		Vector3<float> a = triangle[0];
		Vector3<float> b = triangle[1];
		Vector3<float> c = triangle[2];

		Vector3<float> ab = b - a;
		Vector3<float> ac = c - a;

		auto result = Vector3<float>::CrossProduct(ab, ac);
		result.Normalize();
		float lightIntensity = result * -lightDirection;

		return lightIntensity;
	}
}