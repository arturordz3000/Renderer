#include "Model.h"
#include "../math/point.h"
#include "../math/vector.h"
#include "../geometry/line.h"
#include "../vendor/tga/tgaimage.h"
#include "../geometry/Triangle.h"

namespace Renderer
{
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

			Point point1((vertex1.x + 1.) * viewportWidth / 2., (vertex1.y + 1.) * viewportHeight / 2.);
			Point point2((vertex2.x + 1.) * viewportWidth / 2., (vertex2.y + 1.) * viewportHeight / 2.);
			Point point3((vertex3.x + 1.) * viewportWidth / 2., (vertex3.y + 1.) * viewportHeight / 2.);

			switch (mode)
			{
			case RenderMode::FlatRandom:
				drawTriangle({ point1, point2, point3 }, image, TGAColor(rand() % 255, rand() % 255, rand() % 255, 255));
				break;
			default:
				drawLine(point1, point2, image, color);
				drawLine(point2, point3, image, color);
				drawLine(point3, point1, image, color);
			}
		}
	}
}