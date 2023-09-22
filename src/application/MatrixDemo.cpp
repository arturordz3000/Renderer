#include "MatrixDemo.h"
#include "../math/Vector.h"
#include "../math/Matrix.h"

namespace Renderer
{
	int MatrixDemo::Start()
	{
		Matrix<float> matrix1(3, 3);
		matrix1[0][0] = 3.0f; matrix1[0][1] = 84.0f; matrix1[0][2] = 54.5f;
		matrix1[1][0] = 85.0f; matrix1[1][1] = 4.54f; matrix1[1][2] = 23.5f;
		matrix1[2][0] = 6.837f; matrix1[2][1] = 968.24f; matrix1[2][2] = 2.9545f;

		Matrix<float> matrix2(3, 3);
		matrix2[0][0] = 2.0f; matrix2[0][1] = 13.0f; matrix2[0][2] = 5.55f;
		matrix2[1][0] = 7.0f; matrix2[1][1] = 1.0f; matrix2[1][2] = 24.5f;
		matrix2[2][0] = 19.0f; matrix2[2][1] = 9.0f; matrix2[2][2] = 56.5f;

		Matrix<float> result = matrix1 * matrix2;

		result.Print();

		std::cout << std::endl;

		Matrix<float> projection(4, 4);
		float c = 3.0f;
		projection[0][0] = 1; projection[0][1] = 0; projection[0][2] = 0; projection[0][3] = 0;
		projection[1][0] = 0; projection[1][1] = 1; projection[1][2] = 0; projection[1][3] = 0;
		projection[2][0] = 0; projection[2][1] = 0; projection[2][2] = 1; projection[2][3] = 0;
		projection[3][0] = 0; projection[3][1] = 0; projection[3][2] = -1.f / c; projection[3][3] = 1;

		Vector3<float> v(1, 2, 3);
		Matrix<float> vMatrix = Matrix<float>::FromVector3(v);
		vMatrix[3][0] = 1;

		result = projection * vMatrix;

		result.Print();

		return 0;
	}
}