#include "Model.h"
#include "../math/point.h"
#include "../math/vector.h"
#include "../geometry/line.h"
#include "../vendor/tga/tgaimage.h"
#include "../geometry/Triangle.h"
#include "../math/Matrix.h"

namespace Renderer
{
	float computeLightIntensity(const std::vector<Vector3<float>>& triangle, Vector3<float> &lightDirection, const TGAImage& image);

	Vector3<float> ToVector3WithProjection(const Matrix<float>& matrix)
	{
		float nonZeroDiv = 0.0000001;
		float w = matrix[3][0] + nonZeroDiv;
		Vector3<float> v(matrix[0][0] / w, matrix[1][0] / w, matrix[2][0] / w);
		return v;
	}

	void Model::Draw(TGAImage &image, TGAColor color, RenderMode mode)
	{
		int viewportWidth = image.get_width();
		int viewportHeight = image.get_height();

		int numberOfFaces = this->faces.size();

		int pixelsCount = viewportWidth * viewportHeight;
		float* zBuffer = new float[pixelsCount];

		float c = 3.0f;
		Matrix<float> projection(4, 4);
		projection[0][0] = 1; projection[0][1] = 0; projection[0][2] = 0; projection[0][3] = 0;
		projection[1][0] = 0; projection[1][1] = 1; projection[1][2] = 0; projection[1][3] = 0;
		projection[2][0] = 0; projection[2][1] = 0; projection[2][2] = 1; projection[2][3] = 0;
		projection[3][0] = 0; projection[3][1] = 0; projection[3][2] = -1/c; projection[3][3] = 1;

		for (int i = 0; i < pixelsCount; i++)
		{
			zBuffer[i] = -std::numeric_limits<float>::max();
		}

		for (int i = 0; i < numberOfFaces; i++)
		{
			Vector3<float> vertex1 = this->vertices[this->faces[i][0]];
			Vector3<float> vertex2 = this->vertices[this->faces[i][1]];
			Vector3<float> vertex3 = this->vertices[this->faces[i][2]];

			Vector2<float> uv1 = this->uv[this->facesUV[i][0]];
			Vector2<float> uv2 = this->uv[this->facesUV[i][1]];
			Vector2<float> uv3 = this->uv[this->facesUV[i][2]];

			switch (mode)
			{
				case RenderMode::FlatRandom:
				{
					// Converting from <-width to +width> to <0 to +width>
					Point point1((vertex1.x + 1.) * viewportWidth / 2., (vertex1.y + 1.) * viewportHeight / 2.);
					Point point2((vertex2.x + 1.) * viewportWidth / 2., (vertex2.y + 1.) * viewportHeight / 2.);
					Point point3((vertex3.x + 1.) * viewportWidth / 2., (vertex3.y + 1.) * viewportHeight / 2.);

					drawTriangle({ point1, point2, point3 }, image, TGAColor(rand() % 255, rand() % 255, rand() % 255, 255));
					break;
				}
				case RenderMode::FlatLight:
				{
					// Converting from <-width to +width> to <0 to +width>
					Point point1((vertex1.x + 1.) * viewportWidth / 2., (vertex1.y + 1.) * viewportHeight / 2.);
					Point point2((vertex2.x + 1.) * viewportWidth / 2., (vertex2.y + 1.) * viewportHeight / 2.);
					Point point3((vertex3.x + 1.) * viewportWidth / 2., (vertex3.y + 1.) * viewportHeight / 2.);

					float lightIntensity = computeLightIntensity({ vertex1, vertex2, vertex3 }, this->lightDirection, image);
					if (lightIntensity > 0)
					{
						drawTriangle({ point1, point2, point3 }, image, TGAColor(color.r * lightIntensity, color.g * lightIntensity, color.b * lightIntensity, color.a));
					}
					break;
				}
				case RenderMode::ZBuffer:
				{
					// Converting from <-width to +width> to <0 to +width>
					Vector3<float> point1(int((vertex1.x + 1.) * viewportWidth / 2. + .5), int((vertex1.y + 1.) * viewportHeight / 2. + .5), vertex1.z);
					Vector3<float> point2(int((vertex2.x + 1.) * viewportWidth / 2. + .5), int((vertex2.y + 1.) * viewportHeight / 2. + .5), vertex2.z);
					Vector3<float> point3(int((vertex3.x + 1.) * viewportWidth / 2. + .5), int((vertex3.y + 1.) * viewportHeight / 2. + .5), vertex3.z);

					float lightIntensity = computeLightIntensity({ vertex1, vertex2, vertex3 }, this->lightDirection, image);
					if (lightIntensity > 0)
					{
						drawTriangle({ point1, point2, point3 }, zBuffer, image, TGAColor(color.r * lightIntensity, color.g * lightIntensity, color.b * lightIntensity, color.a));
					}

					break;
				}
				case RenderMode::Textured:
				{
					// Converting from <-width to +width> to <0 to +width>
					Vector3<float> point1(int((vertex1.x + 1.) * viewportWidth / 2. + .5), int((vertex1.y + 1.) * viewportHeight / 2. + .5), vertex1.z);
					Vector3<float> point2(int((vertex2.x + 1.) * viewportWidth / 2. + .5), int((vertex2.y + 1.) * viewportHeight / 2. + .5), vertex2.z);
					Vector3<float> point3(int((vertex3.x + 1.) * viewportWidth / 2. + .5), int((vertex3.y + 1.) * viewportHeight / 2. + .5), vertex3.z);

					float lightIntensity = computeLightIntensity({ vertex1, vertex2, vertex3 }, this->lightDirection, image);
					if (lightIntensity > 0)
					{
						drawTriangle({ point1, point2, point3 }, zBuffer, image, texture, { uv1, uv2, uv3 }, lightIntensity);
					}

					break;
				}
				case RenderMode::TexturedCenterProjection:
				{
					// Applying projection
					Matrix<float> vertex1Matrix = Matrix<float>::FromVector3(vertex1);
					Matrix<float> vertex2Matrix = Matrix<float>::FromVector3(vertex2);
					Matrix<float> vertex3Matrix = Matrix<float>::FromVector3(vertex3);

					Vector3<float> screen_vertex1 = ToVector3WithProjection(projection * vertex1Matrix);
					Vector3<float> screen_vertex2 = ToVector3WithProjection(projection * vertex2Matrix);
					Vector3<float> screen_vertex3 = ToVector3WithProjection(projection * vertex3Matrix);

					// Converting from <-width to +width> to <0 to +width>
					Vector3<float> point1(int((screen_vertex1.x + 1.) * viewportWidth / 2. + .5), int((screen_vertex1.y + 1.) * viewportHeight / 2. + .5), screen_vertex1.z);
					Vector3<float> point2(int((screen_vertex2.x + 1.) * viewportWidth / 2. + .5), int((screen_vertex2.y + 1.) * viewportHeight / 2. + .5), screen_vertex2.z);
					Vector3<float> point3(int((screen_vertex3.x + 1.) * viewportWidth / 2. + .5), int((screen_vertex3.y + 1.) * viewportHeight / 2. + .5), screen_vertex3.z);

					float lightIntensity = computeLightIntensity({ vertex1, vertex2, vertex3 }, this->lightDirection, image);
					if (lightIntensity > 0)
					{
						drawTriangle({ point1, point2, point3 }, zBuffer, image, texture, { uv1, uv2, uv3 }, lightIntensity);
					}

					break;
				}
				default:
				{
					// Converting from <-width to +width> to <0 to +width>
					Point point1((vertex1.x + 1.) * viewportWidth / 2., (vertex1.y + 1.) * viewportHeight / 2.);
					Point point2((vertex2.x + 1.) * viewportWidth / 2., (vertex2.y + 1.) * viewportHeight / 2.);
					Point point3((vertex3.x + 1.) * viewportWidth / 2., (vertex3.y + 1.) * viewportHeight / 2.);

					drawLine(point1, point2, image, color);
					drawLine(point2, point3, image, color);
					drawLine(point3, point1, image, color);
				}
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